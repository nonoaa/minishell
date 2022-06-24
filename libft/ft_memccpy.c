/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:14:23 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:14:24 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sc;
	size_t			idx;

	if (n == 0)
		return (NULL);
	dest = (unsigned char *)dst;
	sc = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		dest[idx] = sc[idx];
		if (sc[idx++] == (unsigned char)c)
			return (&dest[idx]);
	}
	return (NULL);
}
