/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkarakus <kkarakus@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:11:08 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/21 16:38:14 by kkarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	run_cd(t_state *state, t_token *token)
{
	const char	*home;

	if (!token)
		return (FAILURE);
	if (!token->next)
	{
		home = get_env_value(state, "HOME");
		if (!home)
			return (print_execute_err(state, token, 1, ERR_HOME_NOT_SET));
		if (chdir(home) == -1)
			return (print_execute_err(state, token, 114, ERR_CANT_CHANGE_DIR));
		if (env_set_pwd(state) != SUCCESS)
			return (FAILURE);
		state->status = 0;
		return (SUCCESS);
	}
	if (chdir(token->next->data) == -1)
		return (print_execute_err(state, token, 1, ERR_NO_SUCH_FILE_OR_DIR));
	if (env_set_pwd(state) != SUCCESS)
		return (FAILURE);
	state->status = 0;
	return (SUCCESS);
}
