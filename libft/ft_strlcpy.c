/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:17:34 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:17:34 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	ret = 0;
	if (!dst || !src)
		return (0);
	while (ret + 1 < dstsize && src[ret] != '\0')
	{
		dst[ret] = src[ret];
		ret++;
	}
	if (dstsize != 0)
		dst[ret] = '\0';
	while (src[ret] != '\0')
		ret++;
	return (ret);
}
