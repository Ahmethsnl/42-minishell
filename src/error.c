/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:06:56 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/07 18:34:08 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	print_execute_err(t_state *state, const t_token *token, int status, int err)
{
	state->err = HANDLED;
	state->status = status;
	if (print_exec_err_with_prefix(token, err) != SUCCESS)
		return (FAILURE);
	else if (err == ERR_NUMERIC_ARG_REQUIRED)
		eprintln(ESTR_NUMERIC_ARG_REQUIRED);
	else if (err == ERR_TOO_MANY_ARG)
		eprintln(ESTR_TOO_MANY_ARG);
	else if (err == ERR_PERMISSION_DENIED)
		eprintln(ESTR_PERMISSION_DENIED);
	else if (err == ERR_PERMISSION_DENIED_BROKEN_PIPE)
		eprintln(ESTR_PERMISSION_DENIED_BROKEN_PIPE);
	else if (err == ERR_NOT_VALID_IN_THIS_CTX)
		eprintln(ESTR_NOT_VALID_IN_THIS_CTX);
	else if (err == ERR_IS_DIR)
		eprintln(ESTR_IS_DIR);
	else
		eprintln(ESTR_UNEXPECTED);
	return (FAILURE);
}
