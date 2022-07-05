#include "../minishell.h"

static int	chk_quote(char *str)
{
	while (*str)
	{
		if (*str == '\'')
		{
			if (ft_strchr(str + 1, '\''))
				str = ft_strchr(str + 1, '\'');
			else
				return (FALSE);
		}
		else if (*str == '\"')
		{
			if (ft_strchr(str + 1, '\"'))
				str = ft_strchr(str + 1, '\"');
			else
				return (FALSE);
		}
		str++;
	}
	return (TRUE);
}

static int	chk_syntax(t_node *node)
{
	if (!node)
		return (TRUE);
	if (node->type == PIPE)
	{
		if (!node->left || !node->right)
			return (FALSE);
		else if (node->left->type == REDIR
			&& ft_strlen(node->left->data) == 1 && node->left->data[0] == '>')
			return (TRUE);
	}
	else if (node->type == REDIR || node->type == HEREDOC)
	{
		if (!node->right)
			return (FALSE);
	}
	return (chk_syntax(node->left) && chk_syntax(node->right));
}

int	chk_input(char *line)
{
	int	idx;

	idx = 0;
	add_history(line);
	if (chk_quote(line) == FALSE)
	{
		print_syntax_err(line);
		return (TRUE);
	}
	tokenize(&(get_info()->list), line);
	pipeline(&idx);
	if (chk_syntax(get_info()->tree->root) == FALSE)
	{
		print_syntax_err(line);
		return (TRUE);
	}
	return (FALSE);
}