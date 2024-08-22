/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:44:55 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/07 18:45:49 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	run_pwd(t_cmd *cmd, t_state *state)
{
	char	cwd[PATH_MAX];

	if ((getcwd(cwd, sizeof(cwd)) == 0) || ft_strlen(cwd) == 0)
		return (FAILURE);
	dprintln(cmd->bout, cwd);
	state->status = 0;
	return (SUCCESS);
}
