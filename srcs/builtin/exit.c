/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:26 by junylee           #+#    #+#             */
/*   Updated: 2022/07/06 15:16:27 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_atoi_(const char *str)
{
	char		*s;
	long long	ret;
	long long	flag;

	s = (char *)str;
	ret = 0;
	flag = 1;
	while (ft_isblank(*s))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			flag = -1;
	while (ft_isdigit(*s))
	{
		ret = ret * 10 + *s - '0';
		s++;
	}
	while (ft_isblank(*s))
		s++;
	if (*s)
		return (-1);
	return (ret * flag);
}

void	builtin_exit(t_node *node)
{
	if (get_info()->is_pipe == FALSE)
		ft_putendl_fd("exit", get_info()->file->origin_stdout);
	if (node->left)
	{
		get_info()->exitcode = ft_atoi_(node->left->data);
		if (get_info()->exitcode < 0 || !ft_strcmp(node->left->data, "-"))
		{
			ft_putstr_fd("minishell: exit: ", STDERR);
			ft_putstr_fd(node->left->data, STDERR);
			ft_putendl_fd(": numeric argument required", STDERR);
			get_info()->exitcode = 255;
		}
		else if (node->left->left)
		{
			ft_putendl_fd("minishell: exit: too many arguments", STDERR);
			get_info()->exitcode = 1;
			return ;
		}
	}
	exit(get_info()->exitcode);
}