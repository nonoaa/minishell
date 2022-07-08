/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:28:09 by byahn             #+#    #+#             */
/*   Updated: 2022/06/24 20:33:33 by junylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	char	*line;

	init(argc, argv, envp);
	while(1)
	{
		echoctl_off();
		line = readline("minishell:$ ");
		if (line)
		{
			if (line[0] == '\0' || chk_input(line) == TRUE)
				continue ;
			replace_recur(get_info()->tree->root);
			execute_tree(get_info()->tree->root);
			ft_clear();
			free(line);
			line = NULL;
			set_org_term();
		}
		else
			ctrl_d();
	}
	return (0);
}
