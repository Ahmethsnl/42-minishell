/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:10:26 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/22 14:27:22 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_dollar_value(char *key, t_state *state)
{
	int			i;
	int			key_len;
	char		*value;

	i = 0;
	value = NULL;
	while (state->env[i])
	{
		key_len = ft_strlen(key);
		if (ft_strncmp(state->env[i], key, key_len) == 0
			&& state->env[i][key_len] == '=')
		{
			value = ft_strdup(&state->env[i][key_len + 1]);
			if (!value)
				return (NULL);
		}
		i++;
	}
	return (value);
}

char	*create_data_from_dollar(char *data, char *value, int start,
		int index)
{
	char	*new_data;
	int		i;
	int		j;
	int		value_len;

	if (!data)
		return (NULL);
	value_len = ft_strlen(value);
	new_data = (char *)malloc((start + value_len + ft_strlen(data + index - 1))
			* sizeof(char));
	if (!new_data)
		(void)index;
	i = 0;
	j = 0;
	while (i < start - 1)
		new_data[j++] = data[i++];
	i = 0;
	while (i < value_len)
		new_data[j++] = value[i++];
	while (data[index])
		new_data[j++] = data[index++];
	new_data[j] = '\0';
	return (new_data);
}

void	extract_dollar_key_values(char **data, t_state *state, bool *has_dollar)
{
	int	flag_single_quote;
	int	i;
	int	start;

	if (!data || !*data)
		return ;
	i = 0;
	flag_single_quote = 0;
	while ((*data)[i])
	{
		flag_single_quote = get_in_quote(flag_single_quote, (*data)[i]);
		if (flag_single_quote != '\'' && is_valid_dollar(*data, i))
		{
			*has_dollar = true;
			start = i + 1;
			if ((*data)[i + 1] == '0' || (*data)[i + 1] == '?')
				i = handle_special_dollar(data, start, i, state);
			else if ((*data)[i + 1] > '0' && (*data)[i + 1] <= '9')
				handle_number_dollar(data, start, i + 1);
			else
				i = handle_regular_dollar(data, start, i + 1, state);
		}
		else
			i++;
	}
}
