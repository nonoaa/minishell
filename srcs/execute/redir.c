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

# include "minishell.h" 

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
	int		status;
	t_info	*info;

	info = get_info();
	status = 0;
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