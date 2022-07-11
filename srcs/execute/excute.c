/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:51:13 by junylee           #+#    #+#             */
/*   Updated: 2022/07/05 20:51:14 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void exe_command(t_node *node)
{
	connect_redir();
	if (!ft_strcmp(node->data, "echo"))
		builtin_echo(node);
	else if (!ft_strcmp(node->data, "cd"))
		builtin_cd(node);
	else if (!ft_strcmp(node->data, "pwd"))
		builtin_pwd(node);
	else if (!ft_strcmp(node->data, "export"))
		builtin_export(node);
	else if (!ft_strcmp(node->data, "unset"))
		builtin_unset(node);
	else if (!ft_strcmp(node->data, "env"))
		builtin_env(node);
	// else if (!ft_strcmp(node->data, "exit"))
	// 	builtin_exit(node);
	// else
	// 	exec(node, 0);
	disconnect_redir();
}

static void execute_node(t_node *node)
{
	if (!node)
		return ;
	if (node->type == HEREDOC)
		start_heredoc(node);
	else if (node->type == PIPE)
		execute_pipe(node);
	else if (node->type == REDIR)
		redirection(node);
	else if (node->type == TOKEN)
		exe_command(node);
	// get_info()->is_hdoc = FALSE;
}

void execute_tree(t_node *node)
{
	t_info	*info;

	if (!node)
		return ;
	info = get_info();
	info->file->origin_stdin = dup(STDIN);
	info->file->origin_stdout = dup(STDOUT);
	if (info->file->origin_stdin < 0 || info->file->origin_stdout < 0)
		print_strerr(errno);
	execute_node(node);
}