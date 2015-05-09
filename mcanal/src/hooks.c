/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 20:10:51 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/13 20:31:11 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handling mlx hooks
*/

#include "header.h"

int		expose_hook(t_env *e)
{
//	draw(e);
	e = e;  //debug
	return (0);
}

int		key_hook(int key, t_env *e)
{
	if (key == 65307)
		exit(0);
	else
		ft_debugnbr("key", key), ft_putendl(""); //debug
	e = e; //debug
//	mlx_clear_window(e->mlx, e->win);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	ft_debugnbr("button", button);  //debug
	ft_debugnbr("x", x);  //debug
	ft_debugnbr("y", y);  //debug
	ft_putendl(""); //debug
	e = e;  //debug
	return (0);
}
