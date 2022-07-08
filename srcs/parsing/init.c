/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:33:43 by byahn             #+#    #+#             */
/*   Updated: 2022/07/07 17:33:47 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handler(int signo)
{
	if (signo == SIGINT)
	{
		get_info()->exitcode = 1;
		get_info()->is_hdoc = FALSE;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	init(int argc, char **argv, char **envp)
{
	t_info	*info;

	(void)argc;
	(void)argv;
	(void)envp;
	info = get_info();
	ft_bzero(info, sizeof(t_info));
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	info->list = create_list();
	info->tree = create_tree();
	info->file = (t_file *)malloc(sizeof(t_file));
	if (!(info->file))
		print_strerr(errno);
	ft_bzero(info->file, sizeof(t_file));
	set_env_list(envp);
}
