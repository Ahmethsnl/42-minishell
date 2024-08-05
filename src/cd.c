/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:11:08 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/05 19:26:25 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void run_cd(t_state *state, t_token *token)
{
	char	*home;

	home = get_env_value(state, "HOME");
	if (!home)
		return (exec_error(state, token, 1, ERR_HOME_NOT_SET));
	if (chdir(home) == -1)
		return (exec_error(state, token, 1, strerror(0)));
}
