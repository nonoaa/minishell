/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:17:08 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:17:10 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char			*s;
	unsigned char	find;

	s = (char *)str;
	find = (unsigned char)c;
	while (*s)
		if ((unsigned char)*s++ == find)
			return (s - 1);
	if ((unsigned char)*s == find)
		return (s);
	return (0);
}
