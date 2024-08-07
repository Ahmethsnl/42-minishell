/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:09:52 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/07 15:54:49 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_start(t_state *state)
{
	if (!(state->token_arr && run_executor(state) == SUCCESS))
		print_unknown_err(state);
	dispose_prompt(state);
}

int run_executor(t_state *state)
{
	int			arr_len;
	t_cmd		command;
	
	if (!state && !state->token_arr)
		return (FAILURE);
	arr_len = token_arr_len(state->token_arr);
	if (arr_len < 1)
		return (FAILURE);
	if (cmd_init(&command, arr_len) != SUCCESS)
		return (FAILURE);
	if (arr_len == 1)
		return (exec_single_command(state->token_arr[0], state, &command));
	if (arr_len > 1)
		return (exec_multiple_command(state->token_arr[0], state, &command));
}
