/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:55:19 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/14 16:35:42 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Print a string on stdout.
*/

#include "libft.h"
#include <unistd.h>

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
