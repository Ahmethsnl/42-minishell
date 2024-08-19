/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:44:42 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/19 15:50:08 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"

void	free_pointer_variable(char **ptr)
{
	while (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
		ptr++;
	}
	free(ptr);
}
