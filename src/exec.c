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

void	run_executor(t_state *state)
{
	if (!(state->token_arr && exec_prompt(state) == SUCCESS))
		print_unknown_err(state); //is not implemented yet
	dispose_prompt(state); //is not implemented yet
}
/* which_command_built_in is not implemented yet (It will be written into built_in.c) (There is no need to check if it is a command) */
void	exec_prompt(t_state *state)
{
	(void)state;
}