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

#include "minishell.h"

static void	print_art(void)
{
	printf(
		"                                           "
		"  __                  ___       ___      \n"
		"              __              __           "
		" /\\ \\                /\\_ \\     /\\_ \\     \n"
		"  ___ ___    /\\_\\     ___    /\\_\\     __"
		"__  \\ \\ \\___       __   \\//\\ \\    \\//\\ \\    \n"
		"/' __` __`\\  \\/\\ \\  /' _ `\\  \\/\\ \\   "
		"/',__\\  \\ \\  _ `\\   /'__`\\   \\ \\ \\   "
		"  \\ \\ \\   \n"
		"/\\ \\/\\ \\/\\ \\  \\ \\ \\ /\\ \\/\\ \\  \\"
		" \\ \\ /\\__, `\\  \\ \\ \\ \\ \\ /\\  __/    \\_\\ \\_    \\_\\ \\_ \n"
		"\\ \\_\\ \\_\\ \\_\\  \\ \\_\\\\ \\_\\ \\_\\ "
		" \\ \\_\\\\/\\____/   \\ \\_\\ \\_\\\\ \\____\\   /\\____\\   /\\____\\\n"
		" \\/_/\\/_/\\/_/   \\/_/ \\/_/\\/_/   \\/_/ \\"
		"/___/     \\/_/\\/_/ \\/____/   \\/____/   \\/____/\n"
		"                                             "
		"              made by    byahn & junylee\n");
}

void	handler(int signo)
{
	if (signo == SIGINT)
	{
		get_info()->exitcode = 1;
		get_info()->is_hdoc = FALSE;
		ioctl(STDIN_FILENO, TIOCSTI, "\\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	init(int argc, char **argv, char **envp)
{
	t_info	*info;

	(void)argc;
	(void)argv;
	print_art();
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
	get_org_term();
}
