/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:10:48 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/07 18:41:44 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	delete_unnecessary_quotes(char **data)
{
	int			i;
	int			j;
	int			quote;
	char		*new_data;

	new_data = (char *) malloc(sizeof(char) * \
		(ft_strlen(*data) - count_unnecessary_quotes(*data) + 1));
	if (!new_data)
		return ;
	i = 0;
	j = 0;
	quote = 0;
	while ((*data)[i])
	{
		if ((*data)[i] && !is_unnecessary_quote(&quote, (*data)[i]))
			new_data[j++] = (*data)[i];
		i++;
	}
	new_data[j] = '\0';
	free(*data);
	*data = new_data;
}

void	handle_unnecessary_quotes(t_token *root)
{
	t_token	*temp;

	if (!root)
		return ;
	temp = root;
	while (temp)
	{
		if (has_unnecessary_quotes(temp->data))
			delete_unnecessary_quotes(&temp->data);
		temp = temp->next;
	}
}
