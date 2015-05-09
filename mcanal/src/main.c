/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 07:58:32 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/13 20:10:34 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** yep, this is the main
*/

#include "header.h"

int			main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		return (failn("Usage: ./mod1 FILE.mod1."), -1);
	if (!(e.alst = read_file(av[1])))
		return (-2);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_SIZE, WIN_SIZE, "zboub");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
