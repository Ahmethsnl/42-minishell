/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:25:24 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/23 17:31:05 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	exec_start(t_state *state)
{
	if (!(state->token_arr && run_executor(state) == SUCCESS))
		print_unknown_err(state);
	dispose_prompt(state);
}

int	run_executor(t_state *state)
{
	int			arr_len;
	t_cmd		command;
	int			**pipe_fd;

	pipe_fd = NULL;
	if (!state && !state->token_arr)
		return (FAILURE);
	arr_len = token_arr_len(state->token_arr);
	if (arr_len < 1)
		return (FAILURE);
	if (cmd_init(&command, arr_len) != SUCCESS)
		return (FAILURE);
	if (arr_len == 1)
		return (exec_single_command(state->token_arr[0], state, &command));
	pipe_fd = pipe_fd_init(arr_len - 1);
	if (!pipe_fd)
		return (free(command.heredoc), FAILURE);
	if (fork_init(state, &command, pipe_fd, arr_len) != SUCCESS)
		return (pipe_fd_dispose_idx(pipe_fd, arr_len - 1), free(command.heredoc),
			FAILURE);
	return (pipe_fd_dispose_idx(pipe_fd, arr_len - 1), free(command.heredoc),
		SUCCESS);
}
