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
		line = readline("minishell:$ ");
		tokenize(&(get_info()->list), line);
	}
	return (0);
}
