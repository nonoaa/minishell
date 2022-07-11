/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:42 by junylee           #+#    #+#             */
/*   Updated: 2022/07/06 15:16:44 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(t_node *node)
{
	char	*pwd;

	pwd = (char *)malloc(sizeof(char) * (BUFSIZ + 1));
	if (!pwd)
		print_strerr(errno);
	if (node->left && node->left->data[0] == '-' && node->left->data[1])
	{
		ft_putstr_fd("minishell: pwd: ", STDERR);
		ft_putchar_fd(node->left->data[0], STDERR);
		ft_putchar_fd(node->left->data[1], STDERR);
		ft_putendl_fd(": invalid option", STDERR);
		ft_putendl_fd("pwd: usage: pwd with no option", STDERR);
		get_info()->exitcode = 1;
	}
	else
	{
		getcwd(pwd, BUFSIZ);
		ft_putendl_fd(pwd, STDOUT);
		get_info()->exitcode = 0;
	}
	free(pwd);
	pwd = 0;
}