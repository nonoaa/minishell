/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:14:30 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:14:31 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char		*ustr;
	size_t				idx;
	unsigned char		find;

	find = (unsigned char)c;
	idx = 0;
	ustr = (unsigned char *)str;
	while (idx < n)
	{
		if (ustr[idx] == find)
			return (ustr + idx);
		idx++;
	}
	return (0);
}
