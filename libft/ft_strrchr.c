/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:18:33 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:18:34 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*s;
	char			*ret;
	unsigned char	find;
	int				flag;

	s = (char *)str;
	ret = 0;
	find = (unsigned char)c;
	flag = 1;
	while (*s)
	{
		if ((unsigned char)*s++ == find)
		{
			ret = s - 1;
			flag = 0;
		}
	}
	if ((unsigned char)*s == find && flag)
		return (s);
	return (ret);
}
