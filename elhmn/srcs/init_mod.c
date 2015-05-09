/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:42:23 by bmbarga           #+#    #+#             */
/*   Updated: 2015/05/05 05:46:46 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "debug.h"
#include "check_errors.h"

void	set_map(t_mod *mod)
{
	int		i;

	i = -1;
	if (!mod)
		check_errors(NUL, "init_mod.c", "mod");
//	ft_putcol_endl(TXT_YELLOW, "je suis set_map()"); /*_DEBUG_*/
	if (!(mod->map = (float**)malloc(sizeof(float*) * (mod->scale + 1))))
		check_errors(MALLOC, "init_mod.c", "mod->map");
	mod->map[mod->scale] = NULL;
	while (++i < mod->scale)
	{
		if (!(mod->map[i] = (float*)malloc(sizeof(float) * mod->scale)))
			check_errors(MALLOC, "init_mod.c", "mod->map[i]");
	}
}

void	init_map(float **map, t_mod *mod)
{
	int		i;
	int		j;

	j = -1;
	ft_putcol_endl(TXT_YELLOW, "je suis init_map()"); /*_DEBUG_*/
	if (!mod)
		check_errors(NUL, "init_mod.c", "mod");
	if (!map || !*map)
		check_errors(NUL, "init_mod.c", "map");
	while (++j < mod->scale)
	{
		i = -1;
		while (++i < mod->scale)
			map[i][j] = '0';
	}
}

void	init_env(t_mod *mod)
{
	if (!(mod->e.mlx = mlx_init()))
		check_errors(NUL, "init_mod.c", "mod->e.mlx");
	mod->e.win = mlx_new_window(mod->e.mlx, S_WIDTH, S_HEIGH, WIN_TITLE);
	if (!(mod->e.win))
		check_errors(NUL, "init_mod.c", "mod->win");
}

void	init_hook (t_mod *mod)
{
	mlx_key_hook(mod->e.win, key_release, mod);
	mlx_mouse_hook(mod->e.win, mouse_hook, mod);
	mlx_hook(mod->e.win, KeyPress, KeyPressMask, key_press, mod);
	mlx_hook(mod->e.win, MotionNotify,
			PointerMotionMask, motion_notify, mod);
	mlx_expose_hook(mod->e.win, expose_hook, mod);
	mlx_loop_hook(mod->e.mlx, real_time, mod);
}

void	init_image(t_mod *mod)
{
	if (!mod)
		check_errors(NUL, "init_mod.c", "mod");
	mod->bg = NULL;
	mod->img = NULL;
	if (!(mod->lay = (t_lay*)malloc(sizeof(t_lay))))
		check_errors(MALLOC, "init_mod.c", "mod->lay");

	if (!(mod->bg = mlx_new_image(mod->e.mlx, S_WIDTH, S_HEIGH)))
		check_errors(MALLOC, "init_mod.c", "mod->bg");
	if (!(mod->img = mlx_get_data_addr(mod->bg, &(mod->lay->bpp),
			&(mod->lay->line), &(mod->lay->endian))))
		check_errors(MALLOC, "init_mod.c", "mod->img");
}

void	init_mod(t_mod *mod, char *file)
{
	ft_putcol_endl(TXT_YELLOW, "je suis init_mod");/*_DEBUG_*/
	if (!mod)
		check_errors(NUL, "init_mod.c", "mod");
	mod->refresh = 1;
	mod->tops = NULL;
	mod->dist = DIST;
	mod->scale = SCALE;
	mod->k_scale = K_SCALE;
	mod->z_top = -1.;
	mod->z_bot = 0.;
	set_map(mod); // ** test
	init_map(mod->map, mod);
//	print_map(mod->map); /*_DEBUG_*/
	init_scene(mod);
	init_cam(mod);
	init_obj(mod);
	get_data(mod, file);
	map_builder(mod);
	set_obj(mod);
	init_env(mod);
	init_image(mod);
	init_hook(mod);
}
