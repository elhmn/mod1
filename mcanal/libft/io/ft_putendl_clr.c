/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_clr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:51:30 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/27 11:40:43 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Print the char * s followed on one '\n' on stdout, with colors!
** clr = yellow, blue, red, green, pink, sky, white, (default = grey)
*/

#include "libft.h"
#include <unistd.h>

void	ft_putendl_clr(char const *s, char *clr)
{
	ft_putstr_clr(s, clr);
	write(1, "\n", 1);
}
