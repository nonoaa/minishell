/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:16:35 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:16:37 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_writenum(int n, int fd)
{
	char	s;

	if (n > 9)
	{
		ft_writenum(n / 10, fd);
		ft_writenum(n % 10, fd);
	}
	else
	{
		s = n + '0';
		write(fd, &s, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			n = -147483648;
		}
		n *= -1;
	}
	ft_writenum(n, fd);
}
