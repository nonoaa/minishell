/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:15:14 by junylee           #+#    #+#             */
/*   Updated: 2022/07/13 18:15:15 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_cmd_path(char *cmd, int fd, int idx)
{
	char	*path;
	char	**paths;
	char	*temp;

	paths = ft_split(get_env("PATH"), ':');
	path = 0;
	while (paths[idx])
	{
		temp = ft_strjoin(paths[idx++], "/");
		path = ft_strjoin(temp, cmd);
		fd = open(path, O_RDONLY, 0644);
		free(temp);
		if (fd > 0)
		{
			close(fd);
			break ;
		}
		free(path);
		path = 0;
	}
	free_split(paths);
	return (path);
}

static void	get_path(t_node *node, char **path)
{
	char	*cmd;

	cmd = node->data;
	if (!ft_memcmp("./", cmd, 2) || !ft_memcmp("/", cmd, 1))
		*path = ft_strdup(cmd);
	else
		*path = get_cmd_path(cmd, 0, 0);
}

static char	**list_to_array(t_list *env_lst)
{
	char	**ret;
	int		i;
	t_list	*cur;
	char	*temp;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_lstsize(env_lst) + 1));
	if (!ret)
		print_strerr(errno);
	cur = env_lst;
	while (cur)
	{
		temp = ft_strjoin(((t_enode *)cur->content)->key, "=");
		ret[i] = ft_strjoin(temp, ((t_enode *)cur->content)->value);
		free(temp);
		i++;
		cur = cur->next;
	}
	ret[i] = 0;
	return (ret);
}

static void	ft_execve(t_node *node, char **env)
{
	char	*path;
	char	**opt;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	opt = get_cmd_opt(node);
	get_path(node, &path);
	echoctl_on();
	if (execve(path, opt, env) < 0)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(node->data, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(strerror(errno), STDERR);
		exit(127);
	}
}

void	exec(t_node *node, int status)
{
	char	*path;
	pid_t	pid;
	char	**env;

	get_path(node, &path);
	if (!path)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(node->data, STDERR);
		ft_putendl_fd(": command not found", STDERR);
		get_info()->exitcode = 127;
		return ;
	}
	free(path);
	path = 0;
	signal(SIGINT, SIG_IGN);
	env = list_to_array(get_info()->env_list);
	pid = fork();
	if (pid < 0)
		print_strerr(errno);
	else if (pid == 0)
		ft_execve(node, env);
	waitpid(pid, &(status), 0);
	exec_signal(status);
	free_split(env);
}
