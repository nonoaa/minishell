/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:02:03 by junylee           #+#    #+#             */
/*   Updated: 2022/07/06 17:02:04 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

/*
** =============================================================================
** execute.c
** =============================================================================
*/

void execute_tree(t_node *node);

/*
** =============================================================================
** redir.c
** =============================================================================
*/

int	connect_redir(void);
int	disconnect_redir(void);

#endif