/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:26:43 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/28 15:24:48 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	set_other_redirect(t_token *token, t_cmd *cmd, t_state *state)
{
	bool		has_last_heredoc;
	t_token		*temp;

	if (!token)
		return (FAILURE);
	has_last_heredoc = false;
	temp = token;
	while (temp)
	{
		if (temp->type == RED_HEREDOC)
			has_last_heredoc = true;
		else if (temp->type == RED_INPUT)
			has_last_heredoc = false;
		temp = temp->next;
	}
	if (handle_fds(token, cmd, state, has_last_heredoc) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int	handle_fds(t_token *token, t_cmd *cmd, t_state *state, \
	bool has_last_heredoc)
{
	while (token)
	{
		if (token->type == RED_INPUT)
		{
			if (handle_red_input(token, cmd, has_last_heredoc, \
					state) != SUCCESS)
				return (FAILURE);
		}
		else if (token->type == RED_OUTPUT)
		{
			if (handle_red_output(token, cmd, state) != SUCCESS)
				return (FAILURE);
		}
		else if (token->type == RED_APPEND)
		{
			if (handle_red_append(token, cmd, state) != SUCCESS)
				return (FAILURE);
		}
		token = token->next;
		if (!token)
			break ;
	}
	return (SUCCESS);
}

int	set_heredoc(t_token *token, t_cmd *cmd, int i)
{
	if (!token)
		return (FAILURE);
	while (token)
	{
		if (token->type == RED_HEREDOC)
			if (handle_red_heredoc(token, cmd, i) != SUCCESS)
				return (FAILURE);
		token = token->next;
	}
	return (SUCCESS);
}
