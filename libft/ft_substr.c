/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:18:53 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:18:54 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	idx;

	idx = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[0] = '\0';
	if (ft_strlen(s) < start)
		return (ret);
	while (s[idx + start] != '\0' && idx < len)
	{
		ret[idx] = s[idx + start];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}
