/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 01:19:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/11 01:31:28 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strdup() function returns a pointer to a	new	string	which	is	a
** duplicate	of the string s.	Memory for the new string is obtained with
** malloc(3), and can be freed with free(3). The copy stops after n characters.
*/

#include "libft.h"
#include <stdlib.h>

char		*ft_strndup(char *src, size_t n)
{
	char	*dup;
	size_t	i;

	if (!src || !n)
		return (NULL);
	if (!(dup = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
