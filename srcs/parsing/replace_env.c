#include "../minishell.h"

static char	*replace_env(char *data, int start, int end, int flag)
{
	int		idx;
	char	*env;
	char	*rpl;
	char	*ret;
	char	*str;

	idx = 0;
	if (end - start < 1 && flag == FALSE)
		return (ft_strdup("$"));
	else if (end - start < 1 && flag == TRUE)
		return (ft_strdup(""));
	str = ft_substr(data, start, end - start);
	while (str[idx] && !ft_isblank(str[idx]))
		idx++;
	env = ft_substr(str, 0, idx);
	rpl = get_env_or_status(env);
	if (!str[idx])
		ret = ft_strdup(rpl);
	else
		ret = ft_strjoin(rpl, str + idx);
	free(rpl);
	rpl = 0;
	free(str);
	str = 0;
	return (ret);
}

static void	replace_home(t_node *data)
{
	char	*home;
	char	*org;
	char	*path;

	home = get_env("HOME");
	if (!home || !home[0])
		home = getenv("HOME");
	if (data && data->data[0] == '~'
		&& (!data->data[1] || (data->data[1] && data->data[1] == '/')))
	{
		org = ft_substr(data->data, 1, ft_strlen(data->data) - 1);
		path = ft_strjoin(home, org);
		free(org);
		org = data->data;
		data->data = path;
		free(org);
		org = 0;
	}
}

static void	replace_token(char **res, char *data)
{
	int	dquote;
	int	front;
	int	end;
	int	flag;

	init_variable(&dquote, &front, &end);
	while (data[++end])
	{
		if (data[end] == SQUOTE && dquote == FALSE)
			join_squote(res, data, &front, &end);
		else if (data[end] == DQUOTE)
		{
			dquote = !dquote;
			join_str(res, data, &front, end);
		}
		else if (data[end] == '$')
		{
			join_str(res, data, &front, end++);
			find_end_pos(data, &end, &flag);
			join_envp(res, replace_env(data, front, end, flag), &front, &end);
		}
		else if (!data[end + 1])
			join_str(res, data, &front, end + 1);
	}
}

void	replace_recur(t_node *node)
{
	char	*org_data;

	if (!node)
		return ;
	replace_home(node);
	if (ft_strcmp(node->data, "$"))
	{
		org_data = node->data;
		node->data = ft_strdup("");
		replace_token(&(node->data), org_data);
		free(org_data);
		org_data = 0;
	}
	replace_recur(node->left);
	replace_recur(node->right);
}