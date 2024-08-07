/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:11:08 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/07 14:58:06 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void run_cd(t_state *state, t_token *token)
{
	char	*home;

	if (!token)
		return (FAILURE);
	if (!token->next)
	{
		home = get_env_value(state, "HOME");
		if (!home)
			return (exec_error(state, token, 1, ERR_HOME_NOT_SET));
		if (chdir(home) == -1)
			return (exec_error(state, token, 1, strerror(0)));
		if (env_set_pwd(state) != SUCCESS)
			return (exec_error(state, token, 1, strerror(0)));
		state->status = 0;
		return (FAILURE);
	}
	if (chdir(token->next->data) == -1)
		return (print_execute_error(state, token, 1, ERR_NO_SUCH_FILE_OR_DIR));
	if (env_set_pwd(state) != SUCCESS)
		return (FAILURE);
	state->status = 0;
	return (SUCCESS);
}
