/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:53:08 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/14 02:51:55 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Print a character on stdout.
*/

#include "libft.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
