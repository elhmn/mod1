/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 03:51:51 by mcanal            #+#    #+#             */
/*   Updated: 2015/06/06 21:09:01 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Read all the text in the specified file descriptor and fill a given string.
** Return 0 if fail, else 1.
*/

#include "libft.h"
#include "debug.h"
#include "check_errors.h"
#include <unistd.h>

int		get_all(int fd, char **a)
{
	ft_putendl("je suis con");
	int		i;
	char	*buf;

	buf = ft_strnew(BUFF_SIZE);
	if (!buf)
		error(MALLOC, "buf", "get_all.c", TXT_YELLOW);
	if (!a || fd < 0)
		return (0);
	if (!*a)
		*a = ft_strnew(1);
	while ((i = (int)read(fd, (void*)buf, (size_t)BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		*a = ft_realloc(*a, ft_strlen(*a), ft_strlen(*a) + i);
		ft_strcat(*a, buf);
	}
	free(buf);
	if (!*a || i < 0)
		return (0);
	return (1);
}
