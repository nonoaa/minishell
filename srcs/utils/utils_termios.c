/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_termios.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:49:26 by byahn             #+#    #+#             */
/*   Updated: 2022/07/11 20:49:28 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_org_term(void)
{
	t_info	*info;

	info = get_info();
	tcgetattr(STDIN, &(info->org_term));
}

void	set_org_term(void)
{
	t_info	*info;

	info = get_info();
	tcsetattr(STDIN, TCSANOW, &(info->org_term));
}

void	echoctl_off(void)
{
	t_info	*info;

	info = get_info();
	tcgetattr(STDIN, &(info->new_term));
	info->new_term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN, TCSANOW, &(info->new_term));
}

void	echoctl_on(void)
{
	t_info	*info;

	info = get_info();
	tcgetattr(STDIN, &(info->new_term));
	info->new_term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN, TCSANOW, &(info->new_term));
}
