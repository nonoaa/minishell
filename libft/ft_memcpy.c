/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:14:54 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:14:55 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sc;
	size_t			idx;

	if (!src && !dst)
		return (0);
	dest = (unsigned char *)dst;
	sc = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		dest[idx] = sc[idx];
		idx++;
	}
	return (dst);
}
