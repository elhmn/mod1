/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 16:25:53 by bmbarga           #+#    #+#             */
/*   Updated: 2015/07/03 11:34:36 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

/*
** old_version
*/

/*

void	put_up(t_mod *mod, t_vertx *sm, char *img)
{
	int		k;
	float	ret;
	float	**tab;

	k = -1;
	tab = mod->img_tab;
	if (!mod)
		error(NUL, "real_time.c", "mod", TXT_YELLOW);
	if (!sm)
		error(NUL, "real_time.c", "sm", TXT_YELLOW);
	while (sm[++k].end != 1)
	{
		if ((int)sm[k].x < S_WIDTH  && (int)sm[k].x >= 0 && (int)sm[k].z < S_HEIGH && (int)sm[k].z >= 0)
		{
			if (((ret = tab[(int)sm[k].z][(int)sm[k].x]) >= sm[k].y) || !ret)
			{
				if (sm[k].col)
				{
					pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z, sm[k].col, img);
					tab[(int)sm[k].z][(int)sm[k].x] = sm[k].y;
				}
			}
		}
	}
}

void	put_water(t_mod *mod)
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
	if (!(sm = mod->obj->s_mesh))
		error(NUL, "real_time.c", "sm", TXT_YELLOW);
	srand(time(NULL) + mod->z_tops[0].ring[0].st);
	while (sm[++k].end != 1)
	{
		if ((int)sm[k].x < S_WIDTH  && (int)sm[k].x >= 0 && (int)sm[k].z < S_HEIGH && (int)sm[k].z >= 0)
		{
			if (sm[k].col && !(rand() % 10000))
			{
				pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z,mod->tmp, mod->img2);
				if (((ret = tab[(int)sm[k].z][(int)sm[k].x]) >= sm[k].y) || !ret)
				{
					if (mod->obj->l_mesh[k].z <= mod->z_bot)
						pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z,mod->tmp, mod->img4);
					if (rand() % 50 == 1 && mod->obj->l_mesh[k].z <= mod->z_bot)
						pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z, mod->tmp, mod->img4);
				}
			}
		}
	}
}

void	ecoul_up(t_mod *mod, char *img)
{
	dynamic_up(mod, mod->col, mod->col_bord, mod->col_lim);
	put_up(mod, mod->water->s_mesh, img);
	free(mod->water->l_mesh);
	free(mod->water->s_mesh);
	free(mod->water->g_mesh);
	free(mod->water);
	mod->water = NULL;
	move_water_up(&(mod->obj->g_base));
}

void	real_up(t_mod *mod)
{
	mod->etime = time(NULL);
	if ((float)(mod->etime - mod->stime) - (float)1. / (float)30. >= 0.)
	{
		mod->stime = mod->etime;
		ecoul_up(mod, mod->img3);
		on_window(mod, 1, 0, 1, 0);
	}
}
*/

void	put_trans(t_mod *mod)
{
	int		i;

	i = -1;
	mod->check = 0;
	#ifdef FT
		clear_img(mod, mod->img2);
	#endif
	while (++i < TRANS_NBR)
	{
		mod->h = i;
		if (i <= mod->ind_h)
		{
			if (mod->st_lm)
				set_lm_up(mod, mod->trans[i]->l_mesh);
			if (mod->upd_sm)
			{
				set_gbase_trans(mod, mod->trans[i]);
				update_sm(mod, mod->trans[i]);
			}
			#ifdef FT
				draw_obj(mod, mod->trans[i], mod->img2);
			#endif
			#ifdef HOME
				draw_obj(mod, mod->trans[i], mod->img1);
			#endif
		}
// 	printf("mod->check = [%d]\n", mod->check);/*_DEBUG_*/
	}
	if (mod->st_lm)
	{
		if (!mod->check)
		{
//  		printf("STOP\n");/*_DEBUG_*/
			mod->st_lm = 0;
			mod->upd_sm = 0;
		}
	}
}

void	real_up(t_mod *mod)
{
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
