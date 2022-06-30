#ifndef PARSING_H
# define PARSING_H

# include <errno.h>

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

typedef struct s_info
{
	t_tok_list		*list;
	int				exitcode;
}	t_info;

t_info	*get_info(void);
int	ft_isblank(char c);
void	tokenize(t_tok_list **list, char *str);
void	print_strerr(int err);
t_tok_list	*create_list(void);
void	init(int argc, char **argv, char **envp);
void	add_token(t_tok_list **list, t_tok *new_tok);
int	chk_input(char *line);
void	print_err(char *line);
void	ft_clear(void);

#endif