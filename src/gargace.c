/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gargace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:05:39 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/21 13:05:39 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_add_garbage(t_state *s, void *data)
{
	t_garbage	*new;
	t_garbage	*tmp;

	new = (t_garbage *)malloc(sizeof(t_garbage));
	if (!new)
		return ;
	new->ptr = ptr;
	new->next = NULL;
	if (!s->garbage)
		s->garbage = new;
	else
	{
		if (s->last_garbage)
			s->last_garbage->next = new;
		else
		{
			tmp = s->garbage;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	s->last_garbage = new;
}

void	ft_addarr_garbage(t_state *s, void **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		ft_add_garbage(s, ptr[i]);
		i++;
	}
	ft_add_garbage(s, ptr);
}

void	ft_free_garbage(t_state *s)
{
	t_garbage	*tmp;

	while (s->garbage)
	{
		tmp = s->garbage;
		s->garbage = s->garbage->next;
		free(tmp->ptr);
		free(tmp);
	}
}
