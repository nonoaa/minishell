#ifndef UTIL_H
# define UTIL_H

# include "minishell.h"

/*
** =============================================================================
** utils.c
** =============================================================================
*/
t_info	*get_info(void);
int	ft_isblank(char c);
void	ctrl_d(void);
char	*get_env(char *key);
int	ft_strcmp(char *s1, char *s2);

/*
** =============================================================================
** utils_print.c
** =============================================================================
*/
void	print_strerr(int err);
void	print_syntax_err(char *line);


/*
** =============================================================================
** utils_clear.c
** =============================================================================
*/
void	ft_clear(void);

/*
** =============================================================================
** utils_replace.c
** =============================================================================
*/
void	join_str(char **new_data, char *org_data, int *start, int end);
void	join_envp(char **new_data, char *env, int *start, int *end);
void	find_end_pos(char *data, int *end, int *flag);
char	*get_env_or_status(char *env);

/*
** =============================================================================
** utils_replace2.c
** =============================================================================
*/
void	init_variable(int *dquote, int *front, int *end);
void	join_squote(char **res, char *data, int *front, int *end);

/*
** =============================================================================
** utils_termios.c
** =============================================================================
*/
void		get_org_term(void);
void		set_org_term(void);
void		echoctl_off(void);
void		echoctl_on(void);

/*
** =============================================================================
** utils_free.c
** =============================================================================
*/

void	free_enode(void *node);

/*
** =============================================================================
** utils_env.c
** =============================================================================
*/

t_enode	*ft_enode_dup(t_enode *enode);
t_list	*ft_lstdup(t_list *list);
void	env_sort(t_list **lst);

#endif