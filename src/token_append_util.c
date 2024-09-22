/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_append_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:11:08 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/22 16:36:01 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	token_append_meta_pipe(t_token **token)
{
	t_token	*new;
	char	*data;

	if (!token || !*token)
		return (FAILURE);
	data = ft_strdup("|");
	if (!data)
		return (FAILURE);
	new = token_new(data, PIPE);
	if (!new)
		return (free(data), FAILURE);
	token_add_prev(token, new);
	return (SUCCESS);
}

int	token_append_meta_redl(t_token **token)
{
	t_token	*new;
	char	*data;

	if (!token || !*token)
		return (FAILURE);
	data = ft_strdup("<");
	if (!data)
		return (FAILURE);
	new = token_new(data, RED_INPUT);
	if (!new)
		return (free(data), FAILURE);
	token_add_prev(token, new);
	return (SUCCESS);
}

int	token_append_meta_redll(t_token **token)
{
	t_token	*new;
	char	*data;

	if (!token || !*token)
		return (FAILURE);
	data = ft_strdup("<<");
	if (!data)
		return (FAILURE);
	new = token_new(data, RED_HEREDOC);
	if (!new)
		return (free(data), FAILURE);
	token_add_prev(token, new);
	return (SUCCESS);
}

int	token_append_meta_redr(t_token **token)
{
	t_token	*new;
	char	*data;

	if (!token || !*token)
		return (FAILURE);
	data = ft_strdup(">");
	if (!data)
		return (FAILURE);
	new = token_new(data, RED_OUTPUT);
	if (!new)
		return (free(data), FAILURE);
	token_add_prev(token, new);
	return (SUCCESS);
}

int	token_append_meta_redrr(t_token **token)
{
	t_token	*new;
	char	*data;

	if (!token || !*token)
		return (FAILURE);
	data = ft_strdup(">>");
	if (!data)
		return (FAILURE);
	new = token_new(data, RED_APPEND);
	if (!new)
		return (free(data), FAILURE);
	token_add_prev(token, new);
	return (SUCCESS);
}
