/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_rain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 16:26:48 by bmbarga           #+#    #+#             */
/*   Updated: 2015/07/03 10:28:26 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

/*
** old_version
*/

/*

void	put_rain2(t_mod *mod, int i)
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
	if (!(sm = mod->z_tops[mod->ind_e].ring[i].obj->s_mesh))
		error(NUL, "real_time.c", "sm", TXT_YELLOW);
	while (sm[++k].end != 1)
	{
		if ((int)sm[k].x < S_WIDTH  && (int)sm[k].x >= 0 && (int)sm[k].z < S_HEIGH && (int)sm[k].z >= 0)
		{
			if (((ret = tab[(int)sm[k].z][(int)sm[k].x]) >= sm[k].y) || !ret)
			{
				if (sm[k].col)
				{
					pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z, sm[k].col, mod->img2);
				}
			}
		}
	}
}

void	put_rain(t_mod *mod)
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
	if (!(sm = mod->rain->s_mesh))
		error(NUL, "real_time.c", "sm", TXT_YELLOW);
	while (sm[++k].end != 1)
	{
		if ((int)sm[k].x < S_WIDTH  && (int)sm[k].x >= 0 && (int)sm[k].z < S_HEIGH && (int)sm[k].z >= 0)
		{
			if (((ret = tab[(int)sm[k].z][(int)sm[k].x]) >= sm[k].y) || !ret)
			{
				if (sm[k].col)
				{
					pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z, sm[k].col, mod->img);
					tab[(int)sm[k].z][(int)sm[k].x] = sm[k].y;
				}
			}
		}
	}
}

void	put_up_rain(t_mod *mod)
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
	if (!(sm = mod->water->s_mesh))
		error(NUL, "real_time.c", "sm", TXT_YELLOW);
	while (sm[++k].end != 1)
	{
		if ((int)sm[k].x < S_WIDTH  && (int)sm[k].x >= 0 && (int)sm[k].z < S_HEIGH && (int)sm[k].z >= 0)
		{
			if (((ret = tab[(int)sm[k].z][(int)sm[k].x]) >= sm[k].y) || !ret)
			{
				if (sm[k].col)
				{
					pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z, sm[k].col, mod->img2);
					tab[(int)sm[k].z][(int)sm[k].x] = sm[k].y;
				}
			}
		}
	}
}

void	init_vel(t_mod *mod, int e)
{
	int		i;

	i = -1;
	while (++i < (int)mod->z_tops[e].div)
		mod->z_tops[e].ring[i].st = 0;
}

void	init_ring(t_mod *mod)
{
	int		i;

	if (!mod->z_tops[mod->ind_e].ring)
	{
		mod->z_tops[mod->ind_e].div = (int)((mod->z_tops[mod->ind_e].vertx.z * MAX_DIV) / UPPER_DIV);
		if (mod->z_tops[mod->ind_e].div < 0)
			mod->z_tops[mod->ind_e].div = 0;
		if (!(mod->z_tops[mod->ind_e].ring = (t_ring*)malloc(sizeof(t_ring) * (int)(mod->z_tops[mod->ind_e].div + 1.))))
			error(MALLOC, "real_time.c", "ring", TXT_YELLOW);
		i = -1;
		while (++i < (int)mod->z_tops[mod->ind_e].div)
		{
			mod->z_tops[mod->ind_e].ring[i].obj = NULL;
			mod->z_tops[mod->ind_e].ring[i].st = i * (mod->z_tops[mod->ind_e].vertx.z / mod->z_tops[mod->ind_e].div);
			mod->z_tops[mod->ind_e].ring[i].r_vel = 1;
		}
		mod->z_tops[mod->ind_e].ring[mod->z_tops[mod->ind_e].div].r_vel = -1;
	}
}

void	ecoul_rain(t_mod *mod)
{
	int		i;

	srand(time(NULL) + mod->v_part);
	mod->ind_e = -1;
	clear_img(mod, mod->img2);
	while (mod->z_tops[++(mod->ind_e)].vertx.end != 1)
	{
		init_ring(mod);
		i = -1;
		while (++i < mod->z_tops[mod->ind_e].div)
		{
			dynamic_rain(mod, mod->col, mod->col_bord, mod->col_lim, i);
			put_rain2(mod, i);
			free(mod->z_tops[mod->ind_e].ring[i].obj->s_mesh);
			free(mod->z_tops[mod->ind_e].ring[i].obj->g_mesh);
			if (!(mod->z_tops[mod->ind_e].ring[i].r_vel / 2))
				mod->z_tops[mod->ind_e].ring[i].r_vel += SPEED;
			mod->z_tops[mod->ind_e].ring[i].st += mod->z_tops[mod->ind_e].ring[i].r_vel;
			mod->z_tops[mod->ind_e].ring[i].r_vel++;
		}
	}
	put_water(mod);
	//	free(mod->water->l_mesh);
	//	free(mod->water->s_mesh);
	//	free(mod->water->g_mesh);
	//	free(mod->water);
	//	mod->water = NULL;
}

void	real_rain(t_mod *mod)
{
	mod->etime = time(NULL);
	ecoul_rain(mod);
	mod->etime = time(NULL);
	if ((mod->etime - mod->stime) > (time_t)60)
	{
		if (!mod->ind_r)
		{
			clear_img(mod, mod->img4);
			mod->ind_r = 1;
		}
		mod->stime = mod->etime;
	}
	on_window(mod, 1, 1, mod->ind_r, !mod->ind_r);
}
*/

void	put_rain(t_mod *mod)
{
	mod->check = 1;
	#ifdef FT
		clear_img(mod, mod->img2);
	#endif
	#ifdef HOME
		clear_img(mod, mod->img2);
		clear_img(mod, mod->img1);
	#endif
// 	particules handling
	if (mod->st_lm)
		set_lm_rain(mod, mod->rain->l_mesh);
	if (mod->upd_sm)
	{
		if (mod->plane && mod->plane->plan)
		{
			set_gbase_trans(mod, mod->plane->plan);
			update_sm(mod, mod->plane->plan);
		}
		set_gbase_trans(mod, mod->rain);
		update_sm(mod, mod->rain);
	}
	#ifdef FT
		draw_obj(mod, mod->rain, mod->img2);
	#endif
	#ifdef HOME
		draw_obj(mod, mod->rain, mod->img1);
 		if (mod->plane && mod->plane->plan)
 			draw_obj(mod, mod->plane->plan, mod->img1);
	#endif
	if (mod->st_lm)
	{
		if (!mod->check)
		{
			mod->st_lm = 0;
			mod->upd_sm = 0;
		}
	}
}

void	real_rain(t_mod *mod)
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
	put_rain(mod);
	mod->ind_h++;
	#ifdef FT
		on_window(mod, 1, 1, 0);
	#endif
	#ifdef HOME
		on_window(mod, 1, 0, 0);
	#endif
}
