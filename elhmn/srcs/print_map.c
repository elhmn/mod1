/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:39:59 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/08 18:25:43 by bmbarga          ###   ########.fr       */
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
		error(NUL, "init_mod.c", "map", TXT_YELLOW);
	printf("je suis print_map()"); /*_DEBUG_*/
	i = -1; /*_DEBUG_*/
	while (++i < SCALE)
	{
		j = -1;
		while (++j < SCALE)
			printf("[%2.f] ", *(*(map + i) + j));
		printf("\n");
	}
}


void		print_surface(t_mod *mod, char *img)
{
	int		i;
	int		j;
	t_color	*color;

	i = -1;
	color = init_color(NULL, (t_uint)0xFFFFFFFF);
	while (++i < 50)
	{
		j = -1;
		while (++j < 50)
		{
			pixel_put_img(mod, j, i, color, img);
		}
	}
}

void		clear_img(t_mod *mod, char *img)
{
	int			i;
	int			j;
	t_color		*color;

	i = -1;
	color = init_color(NULL, 0xFF000000);
	while (++i < S_HEIGH)
	{
		j = -1;
		while (++j < S_WIDTH)
		{
			pixel_put_img(mod, j, i, color, img);
		}
	}
	free(color);
}

void	put_map(t_mod *mod, char *img)
{
	if (!mod)
		error(NUL, "real_time.c", "mod", TXT_YELLOW);
	print_surface(mod, img);
	mlx_put_image_to_window(mod->e.mlx, mod->e.win, mod->buf1, 0, 0);
	clear_img(mod, img);
}
