/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:45:04 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/05 19:26:57 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int which_command_built_in(t_state *state, t_token *token)
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
	return (SUCCESS);
}
