/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:34:18 by byahn             #+#    #+#             */
/*   Updated: 2022/07/07 17:34:19 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	<PIPELINE> := <CMD>
**				| <CMD> '|' <PIPELINE>
**	
**	<CMD> := <SIMPLE_CMD>
**			| <SIMPLE_CMD> <REDIRS>
**	
**  <REDIRS> := <REDIR>
**			 | <REDIR> <REDIRS>
**
**	<REDIR> := '<' <FILENAME>
**			| '>' <FILENAME>
**			| '>>' <FILENAME>
**			| '<<' <FILENAME>
**
**	<SIMPLE_CMD> := <PATH>
**				| <PATH> <ARGS>
**	
**  <ARGS> := WORD
**			| WORD <ARGS>
**
**	<PATH> := WORD
**	
**	<FILENAME> := WORD
*/

void	args(int *idx)
{
	t_tok	*token;
	t_node	*node;
	t_info	*info;

	info = get_info();
	token = get_token(info->list, *idx);
	if (!token)
		return ;
	if (token->type == REDIR || token->type == PIPE || token->type == HEREDOC)
		return ;
	node = create_node(token);
	insert_path(info->tree, node);
	(*idx)++;
	if (token->next)
		args(idx);
}

void	path(int *idx)
{
	t_tok	*token;
	t_node	*node;
	t_info	*info;

	info = get_info();
	token = get_token(info->list, *idx);
	if (!token)
		return ;
	node = create_node(token);
	insert_path(info->tree, node);
	(*idx)++;
}

void	filename(int *idx)
{
	t_tok	*token;
	t_node	*node;
	t_info	*info;

	info = get_info();
	token = get_token(info->list, *idx);
	if (!token || token->type == PIPE)
		return ;
	node = create_node(token);
	insert_filename(info->tree, node);
	(*idx)++;
}
