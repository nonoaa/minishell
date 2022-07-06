/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:26:23 by junylee           #+#    #+#             */
/*   Updated: 2022/07/06 19:26:24 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_enode *create_enode(char *str)
{
    t_enode *new;
    char    *value;

    new = (t_enode *)malloc(sizeof(t_enode));
    if (!new)
        print_strerr(errno);
    value = ft_strchr(str, '=');
    new->key = ft_substr(str, 0, ft_strlen(str) - ft_strlen(value));
    new->value = ft_substr(value, 1, ft_strlen(value) - 1);
    return (new);
}


void env_list(char **envp)
{
    t_info  *info;
    int     i;

    info = get_info();
    info->env_list = ft_lstnew(create_enode(envp[0]));
    i = 1;
    while (envp[i])
    {
        ft_lstadd_back(&(info->env_list), ft_lstnew(create_enode(envp[i])));
        i++;
    }
}
