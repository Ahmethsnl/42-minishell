/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:26:43 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/21 16:26:43 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	set_red(t_token *token, t_cmd *cmd, t_state *state)
{
	bool		has_last_heredoc;
	t_token		*temp;

	if (!token)
		return (FAILURE);
	has_last_heredoc = false;
	temp = token;
	while (temp)
	{
		if (temp->type == RED_LL)
			has_last_heredoc = true;
		else if (temp->type == RED_L)
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
		if (token->type == RED_L)
		{
			if (handle_redl(token, cmd, has_last_heredoc, state) != SUCCESS)
				return (FAILURE);
		}
		else if (token->type == RED_R)
		{
			if (handle_redr(token, cmd, state) != SUCCESS)
				return (FAILURE);
		}
		else if (token->type == RED_RR)
		{
			if (handle_redrr(token, cmd, state) != SUCCESS)
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
		if (token->type == RED_LL)
			if (handle_redll(token, cmd, i) != SUCCESS)
				return (FAILURE);
		token = token->next;
	}
	return (SUCCESS);
}
