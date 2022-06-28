#include "minishell.h"

void	print_strerr(int err)
{
	ft_putendl_fd(strerror(err), STDERR);
	exit(EXIT_FAILURE);
}