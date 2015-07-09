/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_wave.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 16:27:27 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/30 18:22:36 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

/*
** old_version
*/

/*

void	put_wave(t_mod *mod)
{
	int		k;
	float	ret;
	float	**tab;

	t_vertx	*sm;
	k = -1;
	sm = NULL;
	tab = mod->img_tab;
	if (!mod)
		error(NUL, "real_time.c", "mod", TXT_YELLOW);
	if (!(sm = mod->wave->s_mesh))
		error(NUL, "real_time.c", "sm", TXT_YELLOW);
	while (sm[++k].end != 1)
	{
		if ((int)sm[k].x < S_WIDTH  && (int)sm[k].x >= 0 && (int)sm[k].z < S_HEIGH && (int)sm[k].z >= 0)
		{
			if (sm[k].col)
			{
				if (((ret = tab[(int)sm[k].z][(int)sm[k].x]) >= sm[k].y) || !ret)
				{
					pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z,mod->tmp, mod->img2);
				}
			}
		}
	}
}

void	real_wave(t_mod *mod)
{
	mod->pos++;
	if (mod->pos < mod->scale)
	{
		ecoul_wave(mod);
		on_window(mod, 1, 1, 0, 0);
		free(mod->wave->s_mesh);
		free(mod->wave->g_mesh);
		mod->wave->g_mesh = NULL;
		mod->wave->s_mesh = NULL;
	}
	else
		mod->refresh = 0;
}

void	ecoul_wave(t_mod *mod)
{
	dynamic_wave(mod);
	loc_to_glob_wave(mod->wave, mod);
	get_persp_wave(&(mod->wave->s_mesh), mod->wave->g_mesh, mod);
	get_s_map(mod->wave->s_mesh, mod);
	put_wave(mod);
}
*/

void	real_wave(t_mod *mod)
{
	clear_img(mod, mod->img2);
	if (mod->pt_surf)
	{
		clear_img(mod, mod->img1);
		tab_zero(mod->img_tab);
		if (mod->upd_sm)
			update_sm(mod, mod->obj);
		draw_obj(mod, mod->obj, mod->img1);
		mod->pt_surf = 0;
	}
	put_trans(mod);
	mod->ind_h++;
	#ifdef FT
		on_window(mod, 1, 1, 0);
	#endif
	#ifdef HOME
		on_window(mod, 1, 0, 0);
	#endif
}
