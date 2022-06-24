/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:15:40 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:15:41 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*ret;
	size_t			iter;
	unsigned char	val;

	iter = 0;
	ret = (unsigned char *)ptr;
	val = (unsigned char)c;
	while (iter < len)
	{
		*ret = val;
		ret++;
		iter++;
	}
	return (ptr);
}
