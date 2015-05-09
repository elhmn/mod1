/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debugstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:24:49 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 11:40:25 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allows to print a char * variable preceded by its name (debug!)
*/

#include "libft.h"

void	ft_debugstr(char *name, char *str)
{
	ft_putchar_clr('<', "r");
	ft_putstr_clr(name, "r");
	ft_putstr_clr(":", "r");
	ft_putstr_clr(str, "g");
	ft_putendl_clr(">", "r");
}
