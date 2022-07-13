/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:45:41 by junylee           #+#    #+#             */
/*   Updated: 2022/07/06 18:45:43 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

int	connect_redir(void)
{
	t_info	*info;

	info = get_info();
	if (info->file->open_stdin > 0)
	{
		if (dup2(info->file->open_stdin, STDIN) < 0)
			return (FALSE);
	}
	if (info->file->open_stdout > 0)
	{
		if (dup2(info->file->open_stdout, STDOUT) < 0)
			return (FALSE);
	}
	return (TRUE);
}

int	disconnect_redir(void)
{
	t_info	*info;

	info = get_info();
	if (info->file->open_stdin > 0)
	{
		close(info->file->open_stdin);
		if (dup2(info->file->origin_stdin, STDIN) < 0)
			return (FALSE);
	}
	if (info->file->open_stdout > 0)
	{
		close(info->file->open_stdout);
		if (dup2(info->file->origin_stdout, STDOUT) < 0)
			return (FALSE);
	}
	return (TRUE);
}

static void	init_redir(int is_stdin)
{
	if (is_stdin == FALSE && get_info()->file->open_stdout > 0)
	{
		close(get_info()->file->open_stdout);
		get_info()->file->open_stdout = 0;
	}
	if (is_stdin == TRUE && get_info()->file->open_stdin < 0)
	{
		close(get_info()->file->open_stdin);
		get_info()->file->open_stdin = 0;
	}
}

void	redirection(t_node *node)
{
	t_file	**file;
	int		is_stdin;
	char	*path;

	file = &(get_info()->file);
	path = node->right->data;
	is_stdin = TRUE;
	if (node->data[0] == '>')
		is_stdin = FALSE;
	init_redir(is_stdin);
	if (!ft_strcmp(">", node->data))
		(*file)->open_stdout = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (!ft_strcmp(">>", node->data))
		(*file)->open_stdout = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (!ft_strcmp("<", node->data))
		(*file)->open_stdin = open(path, O_RDONLY, 0644);
	if ((*file)->open_stdout < 0 || (*file)->open_stdin < 0)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(path, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(strerror(errno), STDERR);
		return ;
	}
	execute_tree(node->left);
}
