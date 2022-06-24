/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:18:23 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:18:25 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *org, const char *sub, size_t len)
{
	char	*origin;
	char	*find;
	size_t	i;
	size_t	j;

	i = 0;
	origin = (char *)org;
	find = (char *)sub;
	if (!*find)
		return (origin);
	while (i < len && origin[i])
	{
		j = 0;
		if (origin[i] == find[j])
		{
			while (origin[i + j] == find[j] && i + j < len)
			{
				if (find[j + 1] == '\0')
					return (&origin[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
