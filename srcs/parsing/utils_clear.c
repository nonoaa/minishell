#include "../minishell.h"

static void	clear_list(t_tok_list *list)
{
	t_tok	*curr;
	t_tok	*next;

	if (!list || !(list->count))
		return ;
	curr = list->head;
	while (curr)
	{
		next = curr->next;
		free(curr->data);
		curr->data = NULL;
		free(curr);
		ft_bzero(curr, sizeof(t_tok));
		curr = next;
	}
	ft_bzero(list, sizeof(t_tok_list));
}

static void	delete_node(t_node	*node)
{
	if (!node)
		return ;
	delete_node(node->left);
	delete_node(node->right);
	free(node->data);
	node->data = 0;
	free(node);
	node = 0;
}

static void	clear_tree(t_astree *tree)
{
	if (!tree)
		return ;
	delete_node(tree->root);
	ft_bzero(tree, sizeof(t_astree));
}

void	ft_clear(void)
{
	t_info	*info;

	info = get_info();
	clear_list(info->list);
	clear_tree(info->tree);
	info->h_count = 0;
}
