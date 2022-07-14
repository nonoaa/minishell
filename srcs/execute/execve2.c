/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:17:48 by junylee           #+#    #+#             */
/*   Updated: 2022/07/13 19:17:49 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	num_of_opt(t_node *node)
{
	int		ret;
	t_node	*tmp;

	ret = 1;
	tmp = node->left;
	while (tmp)
	{
		ret++;
		tmp = tmp->left;
	}
	return (ret);
}

char	**get_cmd_opt(t_node *node)
{
	int		idx;
	char	**opt;
	t_node	*cur;

	idx = 0;
	cur = node;
	opt = (char **)malloc(sizeof(char *) * (num_of_opt(node) + 1));
	if (!opt)
		print_strerr(errno);
	while (cur)
	{
		opt[idx] = ft_strdup(cur->data);
		idx++;
		cur = cur->left;
	}
	opt[idx] = 0;
	return (opt);
}

void	exec_signal(int status)
{
	int	sig;

	echoctl_off();
	if (WIFEXITED(status))
		get_info()->exitcode = status / 256;
	else if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGQUIT)
		{
			ft_putendl_fd("Quit: 3", STDIN);
			get_info()->exitcode = 131;
		}
		else if (sig == SIGINT)
		{	
			if (get_info()->has_pipe == FALSE)
				ft_putchar_fd('\n', STDIN);
			else
				ft_putstr_fd("\033[12D", STDIN);
			get_info()->exitcode = 130;
		}
	}
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
}
