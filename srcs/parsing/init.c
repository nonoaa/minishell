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
	info->file = (t_file *)malloc(sizeof(t_file));
	if (!(info->file))
		print_strerr(errno);
	ft_bzero(info->file, sizeof(t_file));
	env_list(envp);
}
