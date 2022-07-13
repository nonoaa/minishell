/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:28:19 by junylee           #+#    #+#             */
/*   Updated: 2022/07/07 20:28:21 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_enode(void *node)
{
	t_enode	*del;

	del = (t_enode *)node;
	free(del->key);
	del->key = 0;
	free(del->value);
	del->value = 0;
	free(del);
	del = 0;
}

void	free_split(char **split)
{
	int	idx;

	idx = -1;
	while (split[++idx])
	{
		free(split[idx]);
		split[idx] = 0;
	}
	free(split);
	split = 0;
}
