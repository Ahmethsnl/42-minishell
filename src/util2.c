/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:11:26 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/07 18:41:28 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	ft_count_digit(int n)
{
	int	c;

	if (n == 0)
		return (1);
	c = 0;
	while (n)
	{
		c++;
		n /= 10;
	}
	return (c);
}

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static void	ft_strrev(char *str)
{
	int		length;
	int		i;
	char	temp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	int		length;

	is_neg = (n < 0);
	str = (char *)malloc((ft_count_digit(n) + is_neg + 1) * sizeof(char));
	if (!str)
		return (NULL);
	length = 0;
	if (n == 0)
	{
		str[0] = '0';
		length++;
	}
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	if (is_neg)
		str[length++] = '-';
	str[length] = '\0';
	ft_strrev(str);
	return (str);
}
