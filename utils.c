#include "minishell.h"

t_info	*get_info(void)
{
	static t_info	info;

	return (&info);
}

int	ft_isblank(char c)
{
	if (c == ' ' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == '\t')
		return (1);
	return (0);
}

void	ctrl_d(void)
{
	ft_putstr_fd("\033[1A", STDOUT);
	ft_putstr_fd("\033[11C", STDOUT);
	ft_putendl_fd("exit", STDOUT);
	// set_org_term();
	exit(get_info()->exitcode);
}