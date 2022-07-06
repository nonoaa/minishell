/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:08 by junylee           #+#    #+#             */
/*   Updated: 2022/07/06 15:16:11 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int is_n(char *str)
{
    int i;

    i = 1;
    while (str[i])
    {
        if (str[i] != 'n')
            return (FALSE);
        i++;
    }
    return (TRUE);
}

static int chk_n_option(t_node *node)
{
    if (node->data[0] == '-' && is_n(node->data))
        return (TRUE);
    return (FALSE);
}

void builtin_echo(t_node *node)
{
    t_node  *cur;
    int     n_flag;

    n_flag = FALSE;
    if (!(node->left))
    {
        ft_putchar_fd('\n', STDOUT);
        return ;
    }
    cur = node->left;
    if (chk_n_option(cur))
    {
        n_flag = TRUE;
        cur = cur->left;
    }
    while(cur)
    {
        ft_putstr_fd(cur->data, STDOUT);
        if (cur->left)
            ft_putchar_fd(' ', STDOUT);   
        cur = cur->left;
    }
    if (n_flag == FALSE)
        ft_putchar_fd('\n', STDOUT);
    get_info()->exitcode = 0;
}
