#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
# include "minishell.h"

# define TRUE 1
# define FALSE 0

typedef enum e_std
{
	STDIN = 0,
	STDOUT,
	STDERR
}	t_std;

typedef enum e_type
{
	TOKEN = -1,
	BLANK = -2,
	PIPE = '|',
	LESS = '<',
	GREAT = '>',
	SQUOTE = '\'',
	DQUOTE = '\"',
	DLESS = -3,
	DGREAT = -4,
	REDIR = -5,
	CMD = -6,
	HEREDOC = -7
}	t_type;

typedef char	*t_data;

typedef struct s_file
{
	int	open_stdin;
	int	open_stdout;
	int	origin_stdin;
	int	origin_stdout;
}	t_file;

typedef struct s_tok
{
	t_data			data;
	t_type			type;
	struct s_tok	*next;
}	t_tok;

typedef struct s_tok_list
{
	t_tok	*head;
	int		count;
}	t_tok_list;

typedef struct s_node
{
	t_data			data;
	t_type			type;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_astree
{
	t_node	*root;
}	t_astree;

typedef struct s_enode
{
	char	*key;
	char	*value;
}	t_enode;

typedef struct s_info
{
	t_tok_list		*list;
	t_astree		*tree;
	t_file			*file;
	t_list			*env_list;
	int				exitcode;
	int				h_count;
}	t_info;

t_info	*get_info(void);
int	ft_isblank(char c);
void	tokenize(t_tok_list **list, char *str);
void	print_strerr(int err);
t_tok_list	*create_list(void);
void	init(int argc, char **argv, char **envp);
void	add_token(t_tok_list **list, t_tok *new_tok);
int	chk_input(char *line);
void	print_syntax_err(char *line);
void	ft_clear(void);
void	pipeline(int *idx);
t_astree	*create_tree(void);
t_node	*create_node(t_tok	*token);
t_tok	*get_token(t_tok_list *list, int pos);
void	ctrl_d(void);

void	pipeline(int *idx);
void	cmd(int *idx);
void	simple_cmd(int *idx);
void	redirs(int *idx);
void	redir(int *idx);
void	args(int *idx);
void	path(int *idx);
void	filename(int *idx);

void	insert_pipe_heredoc(t_astree *tree, t_node *node);
void	insert_redir(t_astree *tree, t_node *node);
void	insert_path(t_astree *tree, t_node *node);
void	insert_filename(t_astree *tree, t_node *node);
void	insert_heredoc_redir(void);

t_enode *create_enode(char *str);
void env_list(char **envp);

#endif