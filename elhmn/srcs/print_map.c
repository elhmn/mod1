/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:39:59 by bmbarga           #+#    #+#             */
/*   Updated: 2015/04/23 20:58:11 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "debug.h"
#include "check_errors.h"
#include <stdio.h> /*_DEBUG_*/

void	print_map(float **map)
{
	int		i;
	int		j; /*_DEBUG_*/

	if (!map)
		check_errors(NUL, "init_mod.c", "map");
	printf("je suis print_map()"); /*_DEBUG_*/
	i = -1; /*_DEBUG_*/
	while (++i < SCALE)
	{
		j = -1;
		while (++j < SCALE)
		{
			printf("[%2.f] ", map[i][j]);
		}
//		print_type("j", &j, INT);
		printf("\n");
	}
}

void		print_surface(t_mod *mod)
{
	int		i;
	int		j;
	t_color	*color;

	i = -1;
	color = init_color(NULL, (t_uint)0xFF0000);
//	ft_putendl("je suis print_surface()"); /*_DEBUG_*/
	while (++i < 50)
	{
		j = -1;
		while (++j < 50)
		{
			pixel_put_img(mod, j, i, color);
		}
	}
	//print_map(mod->map); /*_DEBUG_*/
}

void		clear_img(t_mod *mod)
{
	int			i;
	int			j;
	t_color		*color;

	i = -1;
	color = init_color(NULL, 0);
//	ft_putendl("je suis clear_map()"); /*_DEBUG_*/
	while (++i < S_HEIGH)
	{
		j = -1;
		while (++j < S_WIDTH)
		{
			pixel_put_img(mod, j, i, color);
		}
	}
}

void	put_map(t_mod *mod)
{
//	ft_putendl("je suis put_map()"); /*_DEBUG_*/
	if (!mod)
		check_errors(NUL, "real_time.c", "mod");
	print_surface(mod);
	mlx_put_image_to_window(mod->e.mlx, mod->e.win, mod->bg, 0, 0);
	clear_img(mod);
}
