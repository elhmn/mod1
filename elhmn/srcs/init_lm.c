/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 16:58:07 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/13 20:04:57 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

static void		try_initlm(t_mod *mod, t_obj *obj)
{
	if (!mod)
		error(NUL, "set_obj.c", "mod", TXT_YELLOW);
	if (!obj)
		error(NUL, "set_obj.c", "obj", TXT_YELLOW);
}

static void		fill_lm(t_mod *mod, t_vertx **mesh, t_color *coli, t_color *colf)
{
	t_color *coln;
	int		i;
	int		j;
	int		k;

	k = -1;
	i = -1;
	mesh[0][mod->scale * mod->scale].end = 1;
	if (!mod->map)
		error(NUL, "mod->map", "init_lm.c", TXT_YELLOW);
	while (++i < mod->scale)
	{
		j = -1;
		while (++j < mod->scale)
		{
			mesh[0][++k].x = j;
			mesh[0][k].y = i;
			mesh[0][k].z = mod->map[i][j];
			mesh[0][k].end = 0;
			coln = degrad_col(coli, colf, mod->z_bot, mod->z_top, mesh[0][k].z);
			if (!coln)
				error(MALLOC, "set_obj.c", "coln", TXT_YELLOW);
			mesh[0][k].col = coln;
		}
	}
}

void			init_lm_surf(t_mod *mod, t_obj *obj)
{
	t_color	*coli;
	t_color	*colf;

	if (!(coli = init_color(NULL, COLI)))
		error(MALLOC, "set_obj.c", "coli", TXT_YELLOW);
	if (!(colf = init_color(NULL, COLF)))
		error(MALLOC, "set_obj.c", "colf", TXT_YELLOW);
	try_initlm(mod, obj);
	if (!mod->map)
		error(NUL, "set_obj.c", "map", TXT_YELLOW);
	obj->l_mesh = (t_vertx *)malloc(sizeof(t_vertx) * (mod->scale * mod->scale + 1));
	if (!obj->l_mesh)
		error(MALLOC, "set_obj.c", "mesh", TXT_YELLOW);
	fill_lm(mod, &obj->l_mesh, coli, colf);
	free(coli);
	free(colf);
}

static void		get_active_up(t_mod *mod, t_vertx *mesh, int k)
{
	float	mid;
	float	pos;
	float	dist;
	t_vertx	*om;

	mid = mod->scale / 2.;
	dist = (mid - RAY) * (mid - RAY);
	pos = pow(mesh[k].x - mid, 2.) + pow(mesh[k].z, 2.) + pow(mesh[k].y - mid, 2.);
	om = mod->obj->l_mesh;
	if (pos > dist && om[k].z <= mod->lvl[mod->ind_lvl])
		mesh[k].col = mod->col;
	else
		mesh[k].col = NULL;
}

static void		get_active_wave(t_mod *mod, t_vertx *mesh, int k)
{
	t_vertx	*om;

	om = mod->obj->l_mesh;
	if (mesh[k].x <= (float)TRANS_NBR - (float)mod->h && om[k].z <= mod->lvl[mod->ind_lvl])
		mesh[k].col = mod->col;
	else
		mesh[k].col = NULL;
}

void			init_lm_trans(t_mod *mod, t_obj *obj)
{
	int		i;
	int		j;
	int		k;
	t_vertx	*mesh;

	k = -1;
	i = -1;
	try_initlm(mod, obj);
	if (!obj->l_mesh)
		obj->l_mesh = (t_vertx *)malloc(sizeof(t_vertx) * (mod->scale * mod->scale + 1));
	if (!obj->l_mesh)
		error(MALLOC, "set_obj.c", "mesh", TXT_YELLOW);
	obj->l_mesh[mod->scale * mod->scale].end = 1;
	mesh = obj->l_mesh;
	while (++i < mod->scale)
	{
		j = -1;
		while (++j < mod->scale)
		{
			mesh[++k].x = j;
			mesh[k].y = i;
			mesh[k].z = mod->lvl[mod->ind_lvl];
			mesh[k].act = 0;
			mesh[k].end = 0;
			mesh[k].col = NULL;
		}
	}
}

void			init_lm_trans_up(t_mod *mod, t_obj *obj)
{
	int		i;
	int		j;
	int		k;
	t_vertx	*mesh;

	k = -1;
	i = -1;
	try_initlm(mod, obj);
	if (!obj->l_mesh)
		obj->l_mesh = (t_vertx *)malloc(sizeof(t_vertx) * (mod->scale * mod->scale + 1));
	if (!obj->l_mesh)
		error(MALLOC, "set_obj.c", "mesh", TXT_YELLOW);
	obj->l_mesh[mod->scale * mod->scale].end = 1;
	mesh = obj->l_mesh;
	while (++i < mod->scale)
	{
		j = -1;
		while (++j < mod->scale)
		{
			mesh[++k].x = j;
			mesh[k].y = i;
			mesh[k].z = mod->lvl[mod->ind_lvl];
			mesh[k].act = 0;
			mesh[k].end = 0;
			get_active_up(mod, mesh, k);
		}
	}
}

void			init_lm_trans_wave(t_mod *mod, t_obj *obj)
{
	int		i;
	int		j;
	int		k;
	t_vertx	*mesh;

	k = -1;
	i = -1;
	try_initlm(mod, obj);
	if (!obj->l_mesh)
		obj->l_mesh = (t_vertx *)malloc(sizeof(t_vertx) * (mod->scale * mod->scale + 1));
	if (!obj->l_mesh)
		error(MALLOC, "set_obj.c", "mesh", TXT_YELLOW);
	obj->l_mesh[mod->scale * mod->scale].end = 1;
	mesh = obj->l_mesh;
	while (++i < mod->scale)
	{
		j = -1;
		while (++j < mod->scale)
		{
			mesh[++k].x = j;
			mesh[k].y = i;
			mesh[k].z = mod->lvl[mod->ind_lvl];
			mesh[k].act = 0;
			mesh[k].end = 0;
			mesh[k].col = NULL;
			get_active_wave(mod, mesh, k);
		}
	}
}

void		init_lm_rain(t_mod *mod, t_obj *rain)
{
	int		i;
	int		j;
	int		k;
	t_vertx	*mesh;

	k = -1;
	i = -1;
	try_initlm(mod, rain);
	if (!rain->l_mesh)
		rain->l_mesh = (t_vertx *)malloc(sizeof(t_vertx) * (mod->scale * mod->scale + 1));
	if (!rain->l_mesh)
		error(MALLOC, "set_rain.c", "mesh", TXT_YELLOW);
	rain->l_mesh[mod->scale * mod->scale].end = 1;
	mesh = rain->l_mesh;
	while (++i < mod->scale)
	{
		j = -1;
		while (++j < mod->scale)
		{
			mesh[++k].x = j;
			mesh[k].y = i;
			mesh[k].z = 0.f;
			mesh[k].act = 0;
			mesh[k].vel = 1;
			mesh[k].col_s = 0;
			mesh[k].dirxy = 0;
			mesh[k].dirz = -1;
			mesh[k].col = NULL;
			mesh[k].end = 0;
		}
	}
}
