/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:22:47 by junylee           #+#    #+#             */
/*   Updated: 2022/07/11 20:22:48 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static pid_t	pipe_input(int *fd, t_node *node)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		print_strerr(errno);
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT);
		close(fd[1]);
		execute_tree(node);
		exit(0);
	}
	return (pid);
}

static pid_t	pipe_output(int *fd, t_node *node)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		print_strerr(errno);
	else if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		close(fd[0]);
		get_info()->is_pipe = TRUE;
		execute_tree(node);
		exit(get_info()->exitcode);
	}
	return (pid);
}

void	execute_pipe(t_node *node)
{
	int	pipe_fd[2];
	int	node_left;
	int	node_right;

	if (pipe(pipe_fd) == -1)
		print_strerr(errno);
	node_left = pipe_input(pipe_fd, node->left);
	node_right = pipe_output(pipe_fd, node->right);
	waitpid(node_left, &(get_info()->exitcode), 0);
	close(pipe_fd[1]);
	waitpid(node_right, &(get_info()->exitcode), 0);
	close(pipe_fd[0]);
	if (get_info()->exitcode > 0)
		get_info()->exitcode /= 256;
}
