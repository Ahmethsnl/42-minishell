/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:34:58 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/07 19:48:09 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int which_command_built_in(t_state *state, t_token *token, t_cmd *cmd, int **pipe_fds)
{
	int i;

	// built_in_handle_fds(cmd, fds); not iplemented yet
	(void)cmd;
	(void)pipe_fds;
	i = 0;
	while (state->token_arr[i])
	{
		// if (ft_strcmp(token->data, "echo") == 0)
		// 	run_echo(state);
		if (ft_strcmp(token->data, "cd") == 0)
			run_cd(state, token);
		else if (ft_strcmp(token->data, "pwd") == 0)
			run_pwd(state);
		// else if (ft_strcmp(token->data, "export") == 0)
		// 	run_export(state);
		// else if (ft_strcmp(token->data, "unset") == 0)
		// 	run_unset(state);
		else if (ft_strcmp(token->data, "env") == 0)
			run_env(state);
		// else if (ft_strcmp(token->data, "exit") == 0)
		// 	run_exit(state);
		i++;
	}
	return (FAILURE);
}
