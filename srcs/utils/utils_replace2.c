/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_replace2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:35:13 by byahn             #+#    #+#             */
/*   Updated: 2022/07/07 17:35:14 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_variable(int *dquote, int *front, int *end)
{
	*dquote = FALSE;
	*end = -1;
	*front = 0;
}

void	join_squote(char **res, char *data, int *front, int *end)
{
	join_str(res, data, front, *end);
	*end = ft_strlen(data) - ft_strlen(ft_strchr(data + *front, SQUOTE));
	join_str(res, data, front, *end);
}
