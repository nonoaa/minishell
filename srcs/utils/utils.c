/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:12:09 by junylee           #+#    #+#             */
/*   Updated: 2022/07/07 20:28:24 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	len;

	len = ft_strlen(s1);
	if (len < ft_strlen(s2))
		len = ft_strlen(s2);
	return (ft_memcmp(s1, s2, len));
}

t_info	*get_info(void)
{
	static t_info	info;

	return (&info);
}

int	ft_isblank(char c)
{
	if (c == ' ' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == '\t')
		return (1);
	return (0);
}

void	ctrl_d(void)
{
	ft_putstr_fd("\033[1A", STDOUT);
	ft_putstr_fd("\033[11C", STDOUT);
	ft_putendl_fd("exit", STDOUT);
	// set_org_term();
	exit(get_info()->exitcode);
}

char	*get_env(char *key)
{
	t_list	*cur;
	t_info	*info;

	info = get_info();
	cur = info->env_list;
	while (cur)
	{
		if (!ft_strcmp(((t_enode *)cur->content)->key , key))
			return (((t_enode *)cur->content)->value);
		cur = cur->next;
	}
	return ("");
}
