/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:39:11 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:26:50 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  memchr()  function  scans  the  initial n bytes of the memory area
** pointed to by s for the first instance of c.  Both c and the  bytes  of
** the memory area pointed to by s are interpreted as unsigned char.
*/

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	if (!s || !n)
		return (0);
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (0);
}
