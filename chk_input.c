#include "minishell.h"

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

static int	syntax(void)
{
	
	return (TRUE);
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
	if (syntax() == FALSE)
	{
		print_syntax_err(line);
		return (TRUE);
	}
	return (FALSE);
}