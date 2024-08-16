/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:34:58 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/16 18:35:46 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	built_in_handle_fds(t_cmd *cmd, int **pipe_fds)
{
	(void)pipe_fds;
	if (cmd->in == NAFD)
		if (cmd->heredoc)
			cmd->in = cmd->heredoc[cmd->idx];
	if (cmd->bout == NAFD)
		cmd->bout = STDOUT_FILENO;
	if (cmd->bin == NAFD)
		cmd->bin = STDIN_FILENO;
}

int	which_command_built_in(t_state *state, t_token *token, \
	t_cmd *cmd, int **pipe_fds)
{
	built_in_handle_fds(cmd, pipe_fds);
	if (ft_strncmp(token->data, "echo", 5) == 0)
		return (run_echo(state, token, cmd));
	if (ft_strncmp(token->data, "cd", 3) == 0)
		return (run_cd(state, token));
	if (ft_strncmp(token->data, "pwd", 4) == 0)
		return (run_pwd(cmd, state));
	if (ft_strncmp(token->data, "export", 7) == 0)
		return (run_export(state, token, cmd));
	if (ft_strncmp(token->data, "env", 4) == 0)
		return (run_env(state, cmd));
	if (ft_strncmp(token->data, "exit", 5) == 0)
		return (run_exit(state, token));
	return (FAILURE);
}
