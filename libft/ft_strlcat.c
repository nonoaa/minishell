/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:17:25 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:17:26 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	idx;

	idx = 0;
	dst_size = ft_strlen(dst);
	if (size <= dst_size)
		return (ft_strlen(src) + size);
	while (idx + dst_size + 1 < size && src[idx] != '\0')
	{
		dst[idx + dst_size] = src[idx];
		idx++;
	}
	dst[idx + dst_size] = '\0';
	return (ft_strlen(src) + dst_size);
}
