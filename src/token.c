#include "minishell.h"
#include <stdlib.h>

void	token_smash(t_token **token)
{
	if (!token)
		return ;
	if (*token)
	{
		free((*token)->data);
		(*token)->data = NULL;
	}
	free(*token);
	*token = NULL;
}

void	token_smash_all(t_token **token)
{
	if (!token || !*token)
		return ;
	if ((*token)->next)
		token_smash_all(&(*token)->next);
	token_smash(token);
}

void	token_arr_smash(t_token ***token_arr)
{
	int	i;

	if (!token_arr || !*token_arr || !**token_arr)
		return ;
	i = 0;
	while ((*token_arr)[i])
	{
		token_smash_all(&(*token_arr)[i]);
		i++;
	}
	free(*token_arr);
	*token_arr = NULL;
}

bool	token_sep_md_init(t_token_sep_md *md, t_token *token)
{
	(*md).token_arr = (t_token **)malloc(sizeof(t_token *) * \
		(token_count_pipe(token)+ 2));
	if (!(*md).token_arr)
		return (true);
	(*md).iter = token;
	(*md).temp_root = token;
	(*md).i = 0;
	return (false);
}

t_token	**token_separate_by_pipe(t_token *token)
{
	t_token_sep_md	md;

	if (token_sep_md_init(&md, token))
		return (NULL);
	while (md.iter)
	{
		if (md.iter->type == PIPE)
		{
			md.temp = md.iter;
			md.token_arr[md.i] = md.temp_root;
			md.temp_root = md.iter->next;
			md.iter->prev->next = NULL;
			md.iter = md.iter->next;
			if (md.temp)
				token_smash(&md.temp);
			if (md.temp_root && md.temp_root->type == PIPE)
				return (NULL);
			md.i++;
		}
		else
			md.iter = md.iter->next;
	}
	md.token_arr[md.i++] = md.temp_root;
	md.token_arr[md.i] = NULL;
	return (md.token_arr);
}
