#include "minishell.h"

void	init(int argc, char **argv, char **envp)
{
	t_info	*info;

	(void)argc;
	(void)argv;
	(void)envp;
	info = get_info();
	ft_bzero(info, sizeof(t_info));
	info->list = create_list();
	info->tree = create_tree();
}