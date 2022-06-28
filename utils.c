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