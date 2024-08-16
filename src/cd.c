/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:11:08 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/16 20:44:44 by ahmsanli         ###   ########.fr       */
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
		free(old_path);
	return (SUCCESS);
}

static int	cd_with_flag(t_state *state, t_token *token, bool is_home_set)
{
	char *path;

	if (ft_strncmp(token->next->data, "-", 2) == 0)
	{
		if (is_home_set == false)
		{
			path = ft_strdup("OLDPWD=");
			print_execute_err(state, token, 1, ERR_OLDPWD_NOT_SET);
			env_set_value(state, path);
			return (SUCCESS);
		}
		is_home_set = true;
	}
	return (SUCCESS);
}

static int	home_set(t_state *state, char *home, t_token *token, bool is_home_set)
{
	if (cd_with_flag(state, token, is_home_set))
		return (SUCCESS);
	if (!token->next)
	{
		if (chdir(home) == -1)
			return (print_execute_err(state, token, 0, ERR_HOME_NOT_SET), SUCCESS);
		if (env_set_pwd(state) != SUCCESS)
			return (FAILURE);
		state->status = 0;
		return (FAILURE);
	}
	return (SUCCESS);
}

int	run_cd(t_state *state, t_token *token)
{
	char	*home;
	char	*old_path;
	bool	is_home_set;

	old_path = getcwd(NULL, 0);
	is_home_set = false;
	if (!token)
		return (FAILURE);
	home = get_env_value(state, "HOME");
	if (home_set(state, home, token, is_home_set) != SUCCESS)
		return (FAILURE);
	if (chdir(token->next->data) == -1)
		return (print_execute_err(state, token, 1, ERR_NO_SUCH_FILE_OR_DIR));
	if (env_set_pwd(state) != SUCCESS)
		return (FAILURE);
	if (old_path_util(state, old_path) != SUCCESS)
		return (FAILURE);
	state->status = 0;
	return (SUCCESS);
}
