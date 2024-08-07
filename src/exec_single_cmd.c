/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:49:06 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/07 15:54:51 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_dispose(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free(cmd->cmd);
	cmd->cmd = NULL;
	free(cmd->argv);
	cmd->argv = NULL;
	free(cmd->heredoc);
	cmd->heredoc = NULL;
}

int	exec_single_command_prepare(t_token *token, t_state *state, t_cmd *cmd)
{
	if (token_has_cmd(token) == false)
		return (SUCCESS);
	if (set_cmd_arg_and_path(token, state, cmd, NULL) != SUCCESS)
		return (FAILURE);
	if (!cmd->cmd)
		return (FAILURE);
	return (SUCCESS);
}

int exec_single_command(t_token *token, t_state *state, t_cmd *command)
{
	if (!token || !state || !command)
		return (FAILURE);
	if (exec_single_command_prepare_fds(token, state, command) == FAILURE)
		return (cmd_dispose(command), FAILURE);
	which_command_built_in(state, token);
	cmd_dispose(command);
	return (SUCCESS);
}