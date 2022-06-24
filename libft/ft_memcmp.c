/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:14:40 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:14:41 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			idx;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	idx = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (idx < n)
	{
		if (ptr1[idx] != ptr2[idx])
			break ;
		idx++;
	}
	if (idx == n)
		idx--;
	return (ptr1[idx] - ptr2[idx]);
}
