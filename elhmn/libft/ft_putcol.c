/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/25 12:48:20 by bmbarga           #+#    #+#             */
/*   Updated: 2015/04/25 13:11:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putcol(char *color, char *str)
{
	if (!color || !str)
		return (0);
	ft_putstr("\033[");
	ft_putstr(color);
	ft_putstr("m");
	ft_putstr(str);
	ft_putstr("\033[");
	ft_putstr("0");
	ft_putstr("m");
	return (1);
}

int		ft_putcol_endl(char *color, char *str)
{
	if (!color || !str)
		return (0);
	ft_putcol(color, str);
	ft_putendl("");
	return (1);
}
