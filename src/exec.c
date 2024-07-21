/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:09:52 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/07/21 21:26:46 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void run_executor(t_state *state)
{
	if (!state)
	{
		state->status = 1;
		//exec_exit(state); exec_exit is not implemented yet
	}
}
/* which_command_built_in is not implemented yet

void which_command_built_in(t_state *state)
{
	int i;

	i = 0;
	while (state->token_arr[i])
	{
		if (ft_strcmp(state->token_arr[i], "echo") == 0)
			run_echo(state);
		else if (ft_strcmp(state->token_arr[i], "cd") == 0)
			run_cd(state);
		else if (ft_strcmp(state->token_arr[i], "pwd") == 0)
			run_pwd(state);
		else if (ft_strcmp(state->token_arr[i], "export") == 0)
			run_export(state);
		else if (ft_strcmp(state->token_arr[i], "unset") == 0)
			run_unset(state);
		else if (ft_strcmp(state->token_arr[i], "env") == 0)
			run_env(state);
		else if (ft_strcmp(state->token_arr[i], "exit") == 0)
			run_exit(state);
		i++;
	}
}
*/
