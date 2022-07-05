#include "../minishell.h"

static t_type	get_type(char *str, int len)
{
	char	c;

	c = *str;
	if (c == PIPE)
		return (PIPE);
	else if (c == LESS && len > 1)
		return (HEREDOC);
	else if (c == LESS || c == GREAT)
		return (REDIR);
	else if (c == SQUOTE)
		return (SQUOTE);
	else if (c == DQUOTE)
		return (DQUOTE);
	else
		return (TOKEN);
}

static void	init_token(t_tok_list **list, char *str, int len)
{
	t_tok	*new_tok;

	new_tok = (t_tok *)malloc(sizeof(t_tok));
	if (!new_tok)
		print_strerr(errno);
	ft_bzero(new_tok, sizeof(t_tok));
	new_tok->data = str;
	new_tok->type = get_type(str, len);
	add_token(list, new_tok);
}

void	tokenize(t_tok_list **list, char *str)
{
	char	*end;

	while (*str)
	{
		while (ft_isblank(*str))
			str++;
		end = str;
		while (*end && !ft_strchr(" |<>", *end))
		{
			if (ft_strchr("\'\"", *end))
				end = ft_strchr(end + 1, *end);
			if (ft_strchr(" |<>", *(end + 1)))
				break ;
			end++;
		}
		if (*end && *end == *(end + 1) && ft_strchr("<>", *(end + 1)))
			end++;
		if (*str)
		{
			init_token(list, ft_substr(str, 0, end - str + 1), end - str + 1);
			if (!*end)
				break ;
			str = end + 1;
		}
	}
}
