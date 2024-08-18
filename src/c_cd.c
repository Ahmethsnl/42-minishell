/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:11:08 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/18 18:20:21 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	env_set_oldpwd(t_state *state, char *path)
{
	path = ft_strjoin("OLDPWD=", path, 0);
	if (!state)
		return (FAILURE);
	if (env_set_value(state, path) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static int	old_path_util(t_state *state, char *old_path)
{
	if (env_set_oldpwd(state, old_path) != SUCCESS)
		return (FAILURE);
	else
	{
		free(old_path);
		old_path = NULL;
	}
	return (SUCCESS);
}

static int	cd_with_flag(t_state *state, t_token *token)
{
	char *path;
	char *tmp;
	
	tmp = get_env_value(state, "OLDPWD");
	path = ft_substr(tmp, 2, ft_strlen(tmp) - 1);
	if (path == NULL)
		return(print_execute_err(state, token, 0, ERR_OLDPWD_NOT_SET), FAILURE);
	if (chdir(path) == -1)
		return (print_execute_err(state, token, 0, ERR_OLDPWD_NOT_SET), FAILURE);
	if (env_set_pwd(state) != SUCCESS)
		return (FAILURE);
	old_path_util(state, path);
	state->status = 0;
	return (SUCCESS);
}

static int	home_set(t_state *state, char *home, t_token *token, char *old_path)
{
	if (!token->next)
	{
		if (chdir(home) == -1)
			return (print_execute_err(state, token, 0, ERR_HOME_NOT_SET), SUCCESS);
		if (env_set_pwd(state) != SUCCESS)
			return (FAILURE);
		state->status = 0;
		if (old_path_util(state, old_path) != SUCCESS)
			return (FAILURE);
		return (FAILURE);
	}
	if (token->next->data[0] == '-')
		return (cd_with_flag(state, token), SUCCESS);
	return (SUCCESS);
}

int	run_cd(t_state *state, t_token *token)
{
	char	*home;
	char	*old_path;

	old_path = getcwd(NULL, 256);
	if (!token)
		return (FAILURE);
	home = get_env_value(state, "HOME");
	if (home_set(state, home, token,old_path) != FAILURE)
		return (SUCCESS);
	else if (!token->next || chdir(token->next->data) == -1)
		return (print_execute_err(state, token, 1, ERR_NO_SUCH_FILE_OR_DIR));
	if (env_set_pwd(state) != SUCCESS)
		return (FAILURE);
	if (old_path_util(state, old_path) != SUCCESS)
		return (FAILURE);
	state->status = 0;
	// system("leaks minishell");
	return (SUCCESS);
}
