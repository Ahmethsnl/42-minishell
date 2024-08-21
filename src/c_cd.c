/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:54:21 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/19 16:13:27 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"

static int	set_home_path(t_state *state, t_token *token)
{
	char *home;
	
	home = get_env_value(state, "HOME");
	if (!home)
	{
		print_execute_err(state, token, 0, ERR_HOME_NOT_SET);
		state->status = 1;
		free_pointer_variable(&home);
		return (FAILURE);
	}
	if (chdir(home) == -1)
	{
		print_execute_err(state, token, 0, ERR_HOME_NOT_SET);
		state->status = 1;
		if (!home)
			free_pointer_variable(&home);
		return (FAILURE);
	}
	if (!home)
		free_pointer_variable(&home);
	return (SUCCESS);
}

static int	set_path(t_state *state, t_token *token)
{
	if (chdir(token->next->data) == -1)
	{
		print_execute_err(state, token, 0, ERR_NO_SUCH_FILE_OR_DIR);
		state->status = 1;
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	update_old_pwd(t_state *state, char **old_pwd)
{
	if (!*old_pwd)
	{
		print_execute_err(state, NULL, 0, ERR_OLDPWD_NOT_SET);
		free_pointer_variable(old_pwd);
		state->status = 1;
		return (FAILURE);
	}
	if (env_set_value(state, ft_strjoin("OLDPWD=", *old_pwd, 0)) == SUCCESS)
		return (SUCCESS);
	print_execute_err(state, NULL, 0, ERR_CANT_CHANGE_DIR);
	if (*old_pwd)
		free_pointer_variable(old_pwd);
	if (!*old_pwd)
		free_pointer_variable(old_pwd);
	state->status = 1;
	return (FAILURE);
}

static int	update_pwd_old_pwd(t_state *state, char **old_pwd)
{
	if (env_set_pwd(state) != SUCCESS)
		return (FAILURE);
	if (update_old_pwd(state, old_pwd) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int	run_cd(t_state *state, t_token *token)
{	
	char *old_pwd;

	if (!token)
		return (FAILURE);
	if (!(old_pwd = getcwd(NULL, 256)))
	{
		free(old_pwd);
		old_pwd = NULL;
	}
	if (!token->next)
		set_home_path(state, token);
	else
		set_path(state, token);
	if (update_pwd_old_pwd(state, &old_pwd) != SUCCESS)
		return (FAILURE);
	state->status = 0;
	if (old_pwd)
		free(old_pwd);
	old_pwd = NULL;
	return (SUCCESS);
}
