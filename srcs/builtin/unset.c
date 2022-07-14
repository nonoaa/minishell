/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:48 by junylee           #+#    #+#             */
/*   Updated: 2022/07/06 15:16:50 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_error(char *target)
{
	ft_putstr_fd("minishell: unset: \'", STDERR);
	ft_putstr_fd(target, STDERR);
	ft_putendl_fd("\': not a valid identifier", STDERR);
	get_info()->exitcode = 1;
}

static	int	target_chk(char *data)
{
	int	i;

	i = 0;
	if (!ft_isalpha(data[0]) && data[0] != '_')
		return (FALSE);
	while (data[i])
	{
		if (ft_isdigit(data[i]) || ft_isalpha(data[i]) || data[i] == '_')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

static void	ft_unset(t_info *info, char *target)
{
	t_list	*pre;
	t_list	*cur;

	pre = info->env_list;
	cur = pre;
	if (!target_chk(target))
	{
		unset_error(target);
		return ;
	}
	while (cur)
	{
		if (!ft_strcmp(target, ((t_enode *)cur->content)->key))
			break ;
		pre = cur;
		cur = cur->next;
	}
	if (!cur)
		return ;
	if (pre == cur)
		info->env_list = cur->next;
	else
		pre->next = cur->next;
	ft_lstdelone(cur, free_enode);
}

void	builtin_unset(t_node *node)
{
	t_node	*arg;

	arg = node->left;
	get_info()->exitcode = 0;
	if (arg && arg->data[0] == '-' && arg->data[1])
	{
		ft_putstr_fd("minishell: unset: ", STDERR);
		ft_putchar_fd(arg->data[0], STDERR);
		ft_putchar_fd(arg->data[1], STDERR);
		ft_putendl_fd(": invalid option", STDERR);
		ft_putendl_fd("unset: usage: unset with no option", STDERR);
		get_info()->exitcode = 2;
		return ;
	}
	while (arg)
	{
		ft_unset(get_info(), arg->data);
		arg = arg->left;
	}
}
