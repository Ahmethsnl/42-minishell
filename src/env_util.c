/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:24:47 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/15 17:24:57 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	is_empty_arg(t_token *arg)
{
	while (arg)
	{
		if (arg->type == ARG)
			return (false);
		arg = arg->next;
	}
	return (true);
}

int	env_len(t_state *state)
{
	int	i;

	i = 0;
	if (!state)
		return (0);
	while (state->env[i])
		i++;
	return (i);
}
