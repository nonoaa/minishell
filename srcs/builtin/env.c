/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:17 by junylee           #+#    #+#             */
/*   Updated: 2022/07/06 15:16:18 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void arg_chk(char *data)
{
	if (data[0] == '-' && data[1])
	{
		ft_putstr_fd("minishell: env: ", STDERR);
		ft_putchar_fd(data[0], STDERR);
		ft_putchar_fd(data[1], STDERR);
		ft_putendl_fd(": invalid option", STDERR);
		ft_putstr_fd("env: usage: env with no options\n", STDERR);
		get_info()->exitcode = 1;
	}
	else if (data[0] == '-')
	{
		get_info()->exitcode = 0;
		return ;
	}
	else
	{
		ft_putstr_fd("env: usage: env with no args\n", STDERR);
		get_info()->exitcode = 127;
	}	
}

void	builtin_env(t_node *node)
{
	t_list *env_lst;

	if (node->left)
	{
		arg_chk(node->left->data);
		return ;
	}
	env_lst = get_info()->env_list;
	while(env_lst)
	{
		ft_putstr_fd(((t_enode *)env_lst->content)->key, STDOUT);
		ft_putchar_fd('=', STDOUT);
		ft_putendl_fd(((t_enode *)env_lst->content)->value, STDOUT);
		env_lst = env_lst->next;
	}	
}