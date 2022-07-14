/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:34:34 by byahn             #+#    #+#             */
/*   Updated: 2022/07/07 17:34:36 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_astree	*create_tree(void)
{
	t_astree	*tree;

	tree = (t_astree *)malloc((sizeof(t_astree)));
	if (!tree)
		print_strerr(errno);
	ft_bzero(tree, sizeof(t_astree));
	return (tree);
}

t_node	*create_node(t_tok	*token)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		print_strerr(errno);
	ft_bzero(node, sizeof(t_node));
	node->data = ft_strdup(token->data);
	node->type = token->type;
	return (node);
}
