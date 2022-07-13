/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:34 by junylee           #+#    #+#             */
/*   Updated: 2022/07/06 15:16:36 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_no_args(void)
{
	t_list	*lst;
	t_list	*head;

	lst = ft_lstdup(get_info()->env_list);
	head = lst;
	env_sort(&lst);
	while(lst)
	{
		ft_putstr_fd("declare -x ", STDOUT);
		ft_putstr_fd(((t_enode *)lst->content)->key, STDOUT);
		ft_putstr_fd("=\"", STDOUT);
		ft_putstr_fd(((t_enode *)lst->content)->value, STDOUT);
		ft_putendl_fd("\"", STDOUT);
		lst = lst->next;
	}
	ft_lstclear(&head, free_enode);
}

void	export_error(char *data)
{
	ft_putstr_fd("minishell: export: \'", STDERR);
	ft_putstr_fd(data, STDERR);
	ft_putendl_fd("\': not a valid identifier", STDERR);
	get_info()->exitcode = 1;
}

int		data_chk(char *data)
{
	int	i;

	i = 0;
	if (!ft_isalpha(data[0]) && data[0] != '_')
		return (FALSE);
	while (data[i] && data[i] != '=')
	{
		if (ft_isdigit(data[i]) || ft_isalpha(data[i]) || data[i] == '_')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

void	add_env(t_info *info, char *data, int *arg_check)
{
	t_enode	*new_value;
	t_list	*env_lst;

	if (!ft_strcmp("", data))
		return ;
	*arg_check = 1;
	if (!data_chk(data))
	{
		export_error(data);
		return ;
	}
	if (!ft_strchr(data, '='))
		return ;
	new_value = create_enode(data);
	env_lst = info->env_list;
	while (env_lst && ft_strcmp(new_value->key, ((t_enode *)env_lst->content)->key))
		env_lst = env_lst->next;
	if (!env_lst)
		ft_lstadd_back(&(info->env_list), ft_lstnew(new_value));
	else
	{
		free_enode(env_lst->content);
		env_lst->content = new_value;
	}
}

void	builtin_export(t_node *node)
{
	int	arg_check;
	t_node *arg;

	arg_check = 0;
	arg = node->left;
	get_info()->exitcode = 0;
	if (node->data[0] == '-' && node->data[1])
	{
		ft_putstr_fd("minishell: export: ", STDERR);
		ft_putchar_fd(node->data[0], STDERR);
		ft_putchar_fd(node->data[1], STDERR);
		ft_putendl_fd(": invalid option", STDERR);
		ft_putendl_fd("export : usage: export with no options", STDERR);
		get_info()->exitcode = 2;
		return ;
	}
	while (arg)
	{
		add_env(get_info(), arg->data, &arg_check);
		arg = arg->left;
	}
	if (!arg_check)
		export_no_args();
	return ;
}