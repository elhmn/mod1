/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 23:58:24 by bmbarga           #+#    #+#             */
/*   Updated: 2015/07/03 11:33:05 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "debug.h"
#include "check_errors.h"
#include <stdio.h> /*_DEBUG_*/

/*
** general function
*/

static void	fill_gm(t_mod *mod, t_vertx *lm, t_vertx *gm, t_base gbs)
{
	int		k;

	k = -1;
	if (mod->obj->g_mesh && mod->ecoul == VOID)
		mod->z_gtop = -5555555.;
	while (lm[++k].end != 1)
	{
		gm[k].x = (gbs.i.x - gbs.o.x) * lm[k].x + (gbs.i.y - gbs.o.y) * lm[k].y + (gbs.i.z - gbs.o.z) * lm[k].z + gbs.o.x;
		gm[k].y = (gbs.j.x - gbs.o.x) * lm[k].x + (gbs.j.y - gbs.o.y) * lm[k].y + (gbs.j.z - gbs.o.z) * lm[k].z + gbs.o.y;
		gm[k].z = (gbs.k.x - gbs.o.x) * lm[k].x + (gbs.k.y - gbs.o.y) * lm[k].y + (gbs.k.z - gbs.o.z) * lm[k].z + gbs.o.z;
		if (mod->ecoul == VOID)
			if (gm[k].z > mod->z_gtop)
				mod->z_gtop = gm[k].z;
		gm[k].col = lm[k].col;
		gm[k].end = lm[k].end;
	}
}

int		lmesh_len(t_obj *obj)
{
	int		len;
	t_vertx *lm;

	len = 0;
	if (obj && obj->l_mesh)
	{
		lm = obj->l_mesh;
		while (!lm[len].end)
			len++;
	}
	return (len);
}

void	loc_to_glob(t_mod *mod, t_obj *obj)
{
	int		len_m;

	if (!mod || !obj)
		error(NUL, "set_obj.c", "mod && obj", TXT_YELLOW);
	if (!obj->l_mesh)
		error(NUL, "set_obj.c", "obj->l_mesh", TXT_YELLOW);
	len_m = lmesh_len(obj);
	if (!obj->g_mesh)
	{
		if (!(obj->g_mesh = (t_vertx*)malloc(sizeof(t_vertx) * (len_m + 1))))
			error(MALLOC, "set_obj.c", "g_mesh", TXT_YELLOW);
		obj->g_mesh[len_m].end = 1;
//		ft_putcol(TXT_YELLOW, " g_mesh malloc did\n");/*_DEBUG_*/
	}
	fill_gm(mod, obj->l_mesh, obj->g_mesh, obj->g_base);
}

void	get_persp(t_mod *mod, t_obj *obj)
{
	int		k;
	int		len_m;
	float	dist_so;
	float	dtmp;
	t_vertx	*sm;
	t_vertx	*gm;

	k = -1;
	if (!mod || !obj || !obj->g_mesh)
		error(NUL, "set_obj.c", "mod ||  obj", TXT_YELLOW);
	len_m = lmesh_len(obj);
	if (!obj->s_mesh)
	{
		if (!(obj->s_mesh = (t_vertx*)malloc(sizeof(t_vertx) * (len_m + 1))))
			error(NUL, "set_obj.c", "sm", TXT_YELLOW);
//		ft_putcol(TXT_YELLOW, " s_mesh malloc did\n");/*_DEBUG_*/
		obj->s_mesh[len_m].end = 1;
	}
	sm = obj->s_mesh;
	gm = obj->g_mesh;
	dist_so = ((float)S_WIDTH / 2.) / (float)(sin((double)(FIELD / 2.)) / cos((double)(FIELD / 2.)));
	while (gm[++k].end != 1)
	{
		dtmp = (dist_so / (float)gm[k].y);
		sm[k].x = gm[k].x * dtmp;
		sm[k].y = sqrt(pow(gm[k].y, 2.) + pow(gm[k].z, 2.) + pow(gm[k].x, 2.));
		sm[k].z = gm[k].z * dtmp;
		sm[k].col = gm[k].col;
		sm[k].end = gm[k].end;
	}
}

void	get_sm(t_mod *mod, t_obj *obj)
{
	int		k;
	t_vertx	*sm;

	k = -1;
	if (!mod || !obj || !obj->s_mesh)
		error(NUL, "set_obj.c", "mod || obj || obj->s_mesh", TXT_YELLOW);
	sm = obj->s_mesh;
	while (sm[++k].end != 1)
	{
		sm[k].x += ((float)S_WIDTH / 2.);
		sm[k].z = sm[k].z * -1. + ((float)S_HEIGH / 2.);
	}
}

/*
** t_initlm )==> void (*t_initlm)(t_mod*, t_obj*)
** t_gbase )==> void (*t_gbase)(t_mod*, t_obj*)
*/

void	init_obj(t_mod *mod, t_obj **obj, t_initlm init_lm, t_gbase set_gbase)
{
	if (!mod)
		error(NUL, "mod", "set_obj.c", TXT_YELLOW);
	if (!(*obj = (t_obj*)malloc(sizeof(t_obj))))
		error(MALLOC, "obj", "set_obj.c", TXT_YELLOW);
	(*obj)->l_mesh = NULL;
	(*obj)->g_mesh = NULL;
	(*obj)->s_mesh = NULL;
	(*obj)->size = 0;
//	ft_putcol("init_obj debug", TXT_YELLOW);/*_DEBUG_*/
	if (init_lm)
		init_lm(mod, *obj);
	if (set_gbase)
		set_gbase(mod, *obj);
}
