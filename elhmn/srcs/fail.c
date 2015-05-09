/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:17:22 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/11 21:49:19 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** print a string on stderr
*/

#include "libft.h"

void	*fail(char *s)
{
	ft_putstr_fd(s, 2);
	return (NULL);
}