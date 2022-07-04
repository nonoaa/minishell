#include "minishell.h"

/*
**	<PIPELINE> := <PIPELINE> '|' <PIPELINE>
**				| <CMD>
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

void	pipeline(int *idx)
{	
	t_tok	*token;
	t_node	*node;
	t_info	*info;

	info = get_info();
	cmd(idx);
	token = get_token(info->list, *idx);
	if (token && token->type == PIPE && ++(*idx))
	{
		node = create_node(token);
		// insert_pipe_heredoc(info->tree, node);
		pipeline(idx);
	}
	else if (token)
		pipeline(idx);
}