/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:30:47 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/07 14:54:09 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int which_command_built_in(t_state *state, t_token *token)
{
	int i;

	i = 0;
	while (state->token_arr[i])
	{
		if (ft_strcmp(token, "echo") == 0)
			run_echo(state);
		else if (ft_strcmp(token, "cd") == 0)
			run_cd(state);
		else if (ft_strcmp(token, "pwd") == 0)
			run_pwd(state);
		else if (ft_strcmp(token, "export") == 0)
			run_export(state);
		else if (ft_strcmp(token, "unset") == 0)
			run_unset(state);
		else if (ft_strcmp(token, "env") == 0)
			run_env(state);
		else if (ft_strcmp(token, "exit") == 0)
			run_exit(state);
		i++;
	}
}