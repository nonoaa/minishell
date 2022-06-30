#include "minishell.h"

static int	chk_quote(char *line)
{
	(void)line;
	return (TRUE);
}

int	syntax(void)
{
	return (TRUE);
}

int	chk_input(char *line)
{
	add_history(line);
	if (chk_quote(line) == FALSE)
	{
		print_err(line);
		return (TRUE);
	}
	tokenize(&(get_info()->list), line);
	if (syntax() == FALSE)
	{
		print_err(line);
		return (TRUE);
	}
	return (FALSE);
}