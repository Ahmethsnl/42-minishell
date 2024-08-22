/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:10:46 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/08/07 18:40:59 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	dprint(int fd, const char *s)
{
	write(fd, s, ft_strlen(s));
}

void	dprintln(int fd, const char *s)
{
	dprint(fd, s);
	dprint(fd, ENDL);
}

void	eprint(const char *str)
{
	dprint(STDERR_FILENO, str);
}

void	eprintln(const char *str)
{
	dprintln(STDERR_FILENO, str);
}
