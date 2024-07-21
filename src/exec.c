/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:09:52 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/07/21 21:20:29 by ahmsanli         ###   ########.fr       */
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
	if (ft_strcmp(state->token_arr[0], "echo") == 0)
		run_echo(state);
	else if (ft_strcmp(state->token_arr[0], "cd") == 0)
		run_cd(state);
	else if (ft_strcmp(state->token_arr[0], "pwd") == 0)
		run_pwd(state);
	else if (ft_strcmp(state->token_arr[0], "export") == 0)
		run_export(state);
	else if (ft_strcmp(state->token_arr[0], "unset") == 0)
		run_unset(state);
	else if (ft_strcmp(state->token_arr[0], "env") == 0)
		run_env(state);
	else if (ft_strcmp(state->token_arr[0], "exit") == 0)
		run_exit(state);
	else
		run_executor(state);
}
*/
