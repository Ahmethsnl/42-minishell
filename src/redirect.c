/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:17:30 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/23 17:55:40 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	handle_red_input(t_token *token, t_cmd *cmd, \
	bool has_last_heredoc, t_state *state)
{
	t_token	*temp;

	if (!token)
		return (FAILURE);
	temp = token->next;
	if (!temp && !temp->next)
		return (FAILURE);
	if (access(temp->data, F_OK) == -1)
		return (print_execute_err(state, token->next, 1, ERR_NO_SUCH_FILE_OR_DIR));
	if (access(temp->data, R_OK) == -1)
		return (print_execute_err(state, token->next, 101, EACCES));
	if (has_last_heredoc)
		close(open(temp->data, O_RDONLY));
	else
	{
		if (cmd->in != NAFD)
			close(cmd->in);
		cmd->in = open(temp->data, O_RDONLY);
	}
	return (SUCCESS);
}

int	handle_red_heredoc(t_token *token, t_cmd *cmd, int i)
{
	t_token	*temp;
	char	*buf;
	int		fd[2];

	if (!token || !token->next)
		return (FAILURE);
	temp = token->next;
	if (pipe(fd) == -1)
		return (FAILURE);
	g_sig = IN_HEREDOC;
	while (true && g_sig == IN_HEREDOC)
	{
		buf = readline("> ");
		if (!buf || ft_strcmp(temp->data, buf) == 0)
			break ;
		dprintln(fd[1], buf);
		free(buf);
		buf = NULL;
	}
	g_sig = AFTER_HEREDOC;
	free(buf);
	close(fd[1]);
	if (cmd->heredoc[i] != NAFD)
		close(cmd->heredoc[i]);
	return (cmd->heredoc[i] = fd[0], SUCCESS);
}

int	handle_red_output(t_token *token, t_cmd *cmd, t_state *state)
{
	t_token	*temp;

	if (!token)
		return (FAILURE);
	temp = token->next;
	if (!temp)
		return (FAILURE);
	if (access(temp->data, F_OK) == 0 && access(temp->data, W_OK) == -1)
	{
		if (token_arr_len(state->token_arr) > 1)
			return (print_execute_err(state, token, 1, \
				ERR_PERMISSION_DENIED_BROKEN_PIPE));
		return (print_execute_err(state, token, 1, ERR_PERMISSION_DENIED));
	}
	cmd->out = open(temp->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->out == -1)
		return (print_execute_err(state, token, 103, ENOENT));
	if (token_arr_len(state->token_arr) > 1)
		dup2(cmd->out, STDOUT_FILENO);
	return (SUCCESS);
}

int	handle_red_append(t_token *token, t_cmd *cmd, t_state *state)
{
	t_token	*temp;

	if (!token)
		return (FAILURE);
	temp = token->next;
	if (access(temp->data, F_OK) == 0 && access(temp->data, W_OK) == -1)
		return (print_execute_err(state, token, 1, ERR_PERMISSION_DENIED));
	cmd->out = open(temp->data, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (cmd->out == -1)
		return (print_execute_err(state, token, 105, ENOENT));
	if (token_arr_len(state->token_arr) > 1)
		dup2(cmd->out, STDOUT_FILENO);
	return (SUCCESS);
}
