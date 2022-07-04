#include "minishell.h"

void	print_strerr(int err)
{
	ft_putendl_fd(strerror(err), STDERR);
	exit(EXIT_FAILURE);
}

void	print_syntax_err(char *line)
{
	ft_clear();
	free(line);
	line = 0;
	ft_putendl_fd("minishell: syntax error", STDERR);
	get_info()->exitcode = 258;
}