/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:34:49 by byahn             #+#    #+#             */
/*   Updated: 2022/07/07 17:34:50 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
