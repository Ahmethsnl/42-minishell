/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:14:18 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/07/24 17:14:18 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	which_command_built_in(t_state *state)
{
	int	i;

	i = 0;
	while (state->token_arr[i])
	{
		if ((ft_strcmp(state->token_arr[i], "echo") == 0) && state->token_arr[i]->type == CMD)
			run_echo(state);
		else if (ft_strcmp(state->token_arr[i], "cd") == 0 && state->token_arr[i]->type == CMD)
			run_cd(state);
		else if (ft_strcmp(state->token_arr[i], "pwd") == 0 && state->token_arr[i]->type == CMD)
			run_pwd(state);
		else if (ft_strcmp(state->token_arr[i], "export") == 0 && state->token_arr[i]->type == CMD)
			run_export(state);
		else if (ft_strcmp(state->token_arr[i], "unset") == 0 && state->token_arr[i]->type == CMD)
			run_unset(state);
		else if (ft_strcmp(state->token_arr[i], "env") == 0 && state->token_arr[i]->type == CMD)
			run_env(state);
		else if (ft_strcmp(state->token_arr[i], "exit") == 0 && state->token_arr[i]->type == CMD)
			run_exit(state);
		i++;
	}
}
