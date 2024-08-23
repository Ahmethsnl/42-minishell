/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:12:54 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/23 16:18:56 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	fork_init_exec_child_part_close(int **fd, int i)
{
	if (i != 0)
	{
		close(fd[i - 1][0]);
		close(fd[i - 1][1]);
	}
}

int	fork_init_exec_child_part(t_state *state, t_cmd *cmd, pid_t *pids,
	int **fd)
{
	int		arr_len;
	pid_t	pid;
	int		i;

	i = 0;
	arr_len = token_arr_len(state->token_arr);
	while (i < arr_len)
	{
		if (set_heredoc(state->token_arr[i], cmd, i) != SUCCESS)
			return (FAILURE);
		g_sig = IN_CMD;
		pid = fork();
		if (pid == -1)
			return (free(pids), FAILURE);
		pids[i] = pid;
		if (pid == 0)
			handle_child_process(fd, state, cmd, i);
		else
			fork_init_exec_child_part_close(fd, i);
		i++;
	}
	g_sig = AFTER_CMD;
	return (SUCCESS);
}

int	fork_init(t_state *state, t_cmd *cmd, int **fd, int arr_len)
{
	pid_t	*pids;
	int		i;

	if (!fd || arr_len < 0)
		return (FAILURE);
	pids = (int *) malloc(sizeof(int) * (arr_len + 1));
	if (!pids)
		return (FAILURE);
	if (fork_init_exec_child_part(state, cmd, pids, fd) != SUCCESS)
		return (free(pids), FAILURE);
	i = 0;
	while (i < arr_len)
	{
		waitpid(pids[i], &state->status, 0);
		state->status = w_exit_status(state->status);
		i++;
	}
	return (free(pids), SUCCESS);
}
