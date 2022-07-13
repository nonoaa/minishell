/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:28:28 by junylee           #+#    #+#             */
/*   Updated: 2022/07/07 20:28:29 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_enode	*ft_enode_dup(t_enode *enode)
{
	t_enode	*ret;

	ret = (t_enode *)malloc(sizeof(t_enode));
	if (!ret)
		print_strerr(errno);
	ret->key = ft_strdup(enode->key);
	ret->value = ft_strdup(enode->value);
	return (ret);
}

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*ret;

	ret = ft_lstnew(ft_enode_dup(lst->content));
	if (!ret)
		print_strerr(errno);
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&ret, ft_lstnew(ft_enode_dup(lst->content)));
		lst = lst->next;
	}
	return (ret);
}

static int	enode_compare(t_list *l1, t_list *l2)
{
	char	*s1;
	char	*s2;

	s1 = ((t_enode *)l1->content)->key;
	s2 = ((t_enode *)l2->content)->key;
	return (ft_strcmp(s1, s2));
}

void	env_sort(t_list **lst)
{
	t_list	**l1;
	t_list	**l2;
	void	*temp;

	l1 = lst;
	while ((*l1)->next)
	{
		l2 = &(*l1)->next;
		while (*l2)
		{
			if (enode_compare(*l1, *l2) > 0)
			{
				temp = (*l1)->content;
				(*l1)->content = (*l2)->content;
				(*l2)->content = temp;
			}
			l2 = &(*l2)->next;
		}
		l1 = &(*l1)->next;
	}
}

void	update_shlvl(void)
{
	t_node	cmd_node;
	t_node	new_node;
	char	*new_lvl;
	int		org_exitcode;

	ft_bzero(&cmd_node, sizeof(t_node));
	ft_bzero(&new_node, sizeof(t_node));
	cmd_node.data = "export";
	cmd_node.type = TOKEN;
	new_lvl = ft_itoa(ft_atoi(getenv("SHLVL")) + 1);
	new_node.data = ft_strjoin("SHLVL=", new_lvl);
	new_node.type = TOKEN;
	cmd_node.left = &new_node;
	org_exitcode = get_info()->exitcode;
	builtin_export(&cmd_node);
	get_info()->exitcode = org_exitcode;
	free(new_lvl);
	free(new_node.data);
}
