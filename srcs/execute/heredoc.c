/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:06:39 by junylee           #+#    #+#             */
/*   Updated: 2022/07/09 19:06:41 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_heredoc(void *content)
{
	t_heredoc	*target;

	if (content)
	{
		target = (t_heredoc *)content;
		unlink(target->h_name);
		close(target->fd);
		free(target->h_name);
		free(target->eof);
		ft_bzero(target, sizeof(t_heredoc));
		free(target);
	}
}

t_heredoc	*new_heredoc(t_node *node)
{
	t_heredoc	*ret;
	int			flag;

	ret = (t_heredoc *)malloc(sizeof(t_heredoc));
	if (!ret)
		print_strerr(errno);
	ft_bzero(ret, sizeof(t_heredoc));
	ret->h_name = ft_strjoin(".heredoc_", ft_itoa(get_info()->h_idx++));
	flag = O_CREAT | O_TRUNC | O_RDWR;
	ret->fd = open(ret->h_name, flag, 0644);
	if (ret->fd < 0)
	{
		free(ret->h_name);
		ft_bzero(ret, sizeof(t_heredoc));
		free(ret);
		return (0);
	}
	ret->eof = ft_strdup(node->data);
	return (ret);
}

void	heredoc(t_list	*hdoc)
{
	char		*input;
	t_heredoc	*content;

	content = (t_heredoc *)hdoc->content;
	while (get_info()->is_hdoc == TRUE)
	{
		input = readline("> ");
		if (!input)
		{
			ft_putstr_fd("\033[1A", STDOUT);
			ft_putstr_fd("\033[2C", STDOUT);
			break ;
		}
		if (!ft_strcmp(input, content->eof))
		{
			free(input);
			break ;
		}
		ft_putendl_fd(input, content->fd);
		free(input);
	}	
}

void	start_heredoc(t_node *node)
{
	t_node	*eof;

	get_info()->is_hdoc = TRUE;
	eof = node->right;
	ft_lstadd_back(&get_info()->hdoc_list, ft_lstnew(new_heredoc(eof)));
	heredoc(ft_lstlast(get_info()->hdoc_list));
	if (get_info()->is_hdoc == FALSE)
		return ;
	execute_tree(node->left);
}
