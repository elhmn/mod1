/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:42:23 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/13 21:55:07 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "debug.h"
#include "check_errors.h"

void	init_env(t_mod *mod)
{
	if (!(mod->e.mlx = mlx_init()))
		error(NUL, "init_mod.c", "mod->e.mlx", TXT_YELLOW);
	mod->e.win = mlx_new_window(mod->e.mlx, S_WIDTH, S_HEIGH, WIN_TITLE);
	if (!(mod->e.win))
		error(NUL, "init_mod.c", "mod->win", TXT_YELLOW);
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
		error(NUL, "init_mod.c", "mod", TXT_YELLOW);
	if (!(mod->lay = (t_lay*)malloc(sizeof(t_lay))))
		error(MALLOC, "init_mod.c", "mod->lay", TXT_YELLOW);
	if (!(mod->buf1 = mlx_new_image(mod->e.mlx, S_WIDTH, S_HEIGH)))
		error(MALLOC, "init_mod.c", "mod->buf1", TXT_YELLOW);
	if (!(mod->buf2 = mlx_new_image(mod->e.mlx, S_WIDTH, S_HEIGH)))
		error(MALLOC, "init_mod.c", "mod->buf2", TXT_YELLOW);
	if (!(mod->buf3 = mlx_new_image(mod->e.mlx, S_WIDTH, S_HEIGH)))
		error(MALLOC, "init_mod.c", "mod->buf3", TXT_YELLOW);
	if (!(mod->buf4 = mlx_new_image(mod->e.mlx, S_WIDTH, S_HEIGH)))
		error(MALLOC, "init_mod.c", "mod->buf4", TXT_YELLOW);
	if (!(mod->img1 = mlx_get_data_addr(mod->buf1, &(mod->lay->bpp),
			&(mod->lay->line), &(mod->lay->endian))))
		error(MALLOC, "init_mod.c", "mod->img1", TXT_YELLOW);
	if (!(mod->img2 = mlx_get_data_addr(mod->buf2, &(mod->lay->bpp),
			&(mod->lay->line), &(mod->lay->endian))))
		error(MALLOC, "init_mod.c", "mod->img2", TXT_YELLOW);
	if (!(mod->img3 = mlx_get_data_addr(mod->buf3, &(mod->lay->bpp),
			&(mod->lay->line), &(mod->lay->endian))))
		error(MALLOC, "init_mod.c", "mod->img3", TXT_YELLOW);
	if (!(mod->img4 = mlx_get_data_addr(mod->buf4, &(mod->lay->bpp),
			&(mod->lay->line), &(mod->lay->endian))))
		error(MALLOC, "init_mod.c", "mod->img4", TXT_YELLOW);
	clear_img(mod, mod->img1);
	clear_img(mod, mod->img2);
	clear_img(mod, mod->img3);
	clear_img(mod, mod->img4);
}

void	init_var(t_mod *mod)
{
	mod->refresh = 1;
	mod->tops = NULL;
	mod->dist = DIST;
	mod->plane = NULL;
	mod->pos = 0;
	mod->scale = SCALE;
	mod->k_scale = K_SCALE;
	mod->z_top = -1.;
	mod->z_gtop = -5555555.;
	mod->vel_p = 1;
	mod->stime = (time_t)time(NULL);
	mod->etime = (time_t)time(NULL);
	mod->z_bot = K_SCALE;
	mod->tran_sz = (int)((H_PER * (float)K_SCALE) / 100.);
	mod->water = NULL;
	mod->rain = NULL;
	mod->wave= NULL;
	mod->trans = NULL;
	mod->act = 1;
	mod->ecoul = VOID;
	mod->img_tab = init_imgtab();
	mod->upd_sm = 0;
	mod->tmp = init_color(NULL, COL);
	mod->h = 0;
	mod->st_lm = 1;
	mod->check = 0;
	mod->pt_surf = 1;
	mod->slowMo = 0;
	if (!(mod->lvl = (float*)malloc(sizeof(float) * TRANS_NBR)))
		error(MALLOC, "mod->lvl", "init_mod.c", TXT_YELLOW);
	mod->ind_lvl = 0;
}

void	print_lvl(t_mod *mod)
{
	int		i;

	i = 0;
	while (i < TRANS_NBR)
	{
		printf("lvl[%d] = [%.2f]\n", i, mod->lvl[i]);
		i++;
	}
}

void	init_mod(t_mod *mod, char *file)
{
	ft_putcol_endl(TXT_GREEN, "je suis init_mod");/*_DEBUG_*/
	if (!mod)
		error(NUL, "init_mod.c", "mod", TXT_YELLOW);
	init_var(mod);
	set_map(mod);
	init_map(mod->map, mod);
	get_data(mod, file);
//	mod->z_tops = tops(mod); /* maybe useless*/
	map_builder(mod);
	get_lvl(mod);
	print_lvl(mod);
	init_obj(mod, &(mod->obj), init_lm_surf, set_gbase_surf);
	update_sm(mod, mod->obj);
	del_map(mod->map);
	mod->map = NULL;
	init_env(mod);
	init_image(mod);
	init_hook(mod);
	if (!(mod->col = init_color(NULL, COL)))
		error(NUL, "dynamic_up.c", "col", TXT_YELLOW);
	if (!(mod->col_bord = init_color(NULL, COL_BORD)))
		error(NUL, "dynamic_up.c", "col", TXT_YELLOW);
	if (!(mod->col_lim = init_color(NULL, RED)))
		error(NUL, "dynamic_up.c", "col", TXT_YELLOW);
}
