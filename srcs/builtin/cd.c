/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:01 by junylee           #+#    #+#             */
/*   Updated: 2022/07/06 15:16:02 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	no_arg(char *home)
{
	get_info()->exitcode = 0;
	if (!home[0])
	{
		ft_putendl_fd("minishell: cd: HOME not set", STDERR);
		get_info()->exitcode = 1;
	}
	else if (chdir(home) < 0)
	{
		ft_putstr_fd("minishell: cd: ", STDERR);
		ft_putstr_fd(home, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(strerror(errno), STDERR);
		get_info()->exitcode = 1;
	}
}

void builtin_cd(t_node *node)
{
    char *home;

    home = get_env("HOME");
    if (!node->left)
		no_arg(home);
	else if (chdir(node->left->data) < 0)
	{
		ft_putstr_fd("minishell: cd: ", STDERR);
		if (!ft_strcmp("", home))
			ft_putendl_fd("HOME not set", STDERR);
		else if (node->left->data[0] == '-' && node->left->data[1])
		{
			ft_putchar_fd(node->left->data[0], STDERR);
			ft_putchar_fd(node->left->data[1], STDERR);
			ft_putendl_fd(": invalid option", STDERR);
			ft_putendl_fd("cd: usage: cd [dir]", STDERR);
		}
		else
		{
			ft_putstr_fd(node->left->data, STDERR);
			ft_putstr_fd(": ", STDERR);
			ft_putendl_fd(strerror(errno), STDERR);
		}
		get_info()->exitcode = 1;
	}

}
