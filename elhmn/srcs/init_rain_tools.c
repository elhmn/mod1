/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rain_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 01:55:14 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/11 17:29:49 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

void		init_rain_bases(t_mod *mod, int i)
{
	t_base	*base;
	int		e;

	e = mod->ind_e;
	base = NULL;
	base = &(mod->obj->g_base);
	if (!base)
		error(NUL, "base", "init_rain_tools.c", TXT_YELLOW);
	if (mod->z_tops[e].ring[i].obj)
	{
		mod->z_tops[e].ring[i].obj->g_base.o.x = base->o.x;
		mod->z_tops[e].ring[i].obj->g_base.o.y = base->o.y;
		mod->z_tops[e].ring[i].obj->g_base.o.z = 8 + base->o.z;

		mod->z_tops[e].ring[i].obj->g_base.i.x = base->i.x;
		mod->z_tops[e].ring[i].obj->g_base.i.y = base->i.y;
		mod->z_tops[e].ring[i].obj->g_base.i.z = 8 + base->i.z;
		
		mod->z_tops[e].ring[i].obj->g_base.j.x = base->j.x;
		mod->z_tops[e].ring[i].obj->g_base.j.y = base->j.y;
		mod->z_tops[e].ring[i].obj->g_base.j.z = 8 + base->j.z;
		
		mod->z_tops[e].ring[i].obj->g_base.k.x = base->k.x;
		mod->z_tops[e].ring[i].obj->g_base.k.y = base->k.y;
		mod->z_tops[e].ring[i].obj->g_base.k.z = 8 + base->k.z;
		
		base = &(mod->obj->l_base);
	
		mod->z_tops[e].ring[i].obj->l_base.o.x = base->o.x;
		mod->z_tops[e].ring[i].obj->l_base.o.y = base->o.y;
		mod->z_tops[e].ring[i].obj->l_base.o.z = base->o.z;	
		
		mod->z_tops[e].ring[i].obj->l_base.i.x = base->i.x;
		mod->z_tops[e].ring[i].obj->l_base.i.y = base->i.y;
		mod->z_tops[e].ring[i].obj->l_base.i.z = base->i.z;
		
		mod->z_tops[e].ring[i].obj->l_base.j.x = base->j.x;
		mod->z_tops[e].ring[i].obj->l_base.j.y = base->j.y;
		mod->z_tops[e].ring[i].obj->l_base.j.z = base->j.z;
		
		mod->z_tops[e].ring[i].obj->l_base.k.x = base->k.x;
		mod->z_tops[e].ring[i].obj->l_base.k.y = base->k.y;
		mod->z_tops[e].ring[i].obj->l_base.k.z = base->k.z;
	}
}

float	get_z(t_mod *mod, float x, float y)
{
	int		k;
	t_vertx	*lm;
	

	if (x < mod->scale && x >= 0. && y < mod->scale && y >= 0.)
	{
		k = (int)(y * mod->scale) + (int)x + 1;
		lm = mod->obj->l_mesh;
		return (lm[k].z);
	}
	else
		return (0);
}

void	set_rain_meshes(t_mod	*mod, t_color *col, int i)
{
	t_vertx		*lm;
	int			k;
	t_top		*tp;
	int			x;
	int			y;
	int			e;
	double		r;
	double		ang;
	float		z;
	int			vel;

	(void)col;
	k = 0;
	e = mod->ind_e;
	r = (2. * M_PI) / (double)RAY;
	lm = mod->z_tops[e].ring[i].obj->l_mesh;
	if (!(tp = mod->z_tops))
		error(NUL, "dynamic_rain.c", "mod->z_tops", TXT_YELLOW);
	ang = 0.;
	vel = mod->z_tops[mod->ind_e].ring[i].st;
	while (k < (int)RAY)
	{
		x = (int)(vel * cos(ang) + tp[e].vertx.x);
		y = (int)(vel * sin(ang) + tp[e].vertx.y);
		if (x < mod->scale && x >= 0. && y < mod->scale && y >= 0. && lm[k].end == -1)
			lm[k].col = mod->tmp;
		else
			lm[k].col = NULL;
		lm[k].x = (float)x;
		lm[k].y = (float)y;
		if (lm[k].z < (z = get_z(mod, (float)x, (float)y)))
			lm[k].col = NULL;
		lm[k].z = z;
		if (lm[k].z <= mod->z_bot && (x < mod->scale && x >= 0. && y < mod->scale && y >= 0.))
		{
			mod->z_tops[e].ring[i].st = ST;
			mod->z_tops[e].ring[i].r_vel = 1;
		}
		ang += r;
		k++;
	}
}

void	init_rain_meshes(t_mod	*mod, t_color *col, int i)
{
	t_vertx		*lm;
	int			k;
	t_top		*tp;
	int			x;
	int			y;
	int			e;
	double		r;
	float		z;
	double		ang;
	int			vel;

	(void)col;
	k = 0;
	e = mod->ind_e;
	r = (2. * M_PI) / (double)RAY;
	if (!(tp = mod->z_tops))
		error(NUL, "dynamic_rain.c", "mod->z_tops", TXT_YELLOW);
	if (!(lm = (t_vertx*)malloc(sizeof(t_vertx) * ((int)RAY + 1))))
		error(MALLOC, "init_rain_tools.c", "lm", TXT_YELLOW);
	lm[(int)RAY].end = 1;
	ang = 0.;
	vel = mod->z_tops[mod->ind_e].ring[i].st;
	while (k < (int)RAY)
	{

		x = (int)(vel * cos(ang) + tp[e].vertx.x);
		y = (int)(vel * sin(ang) + tp[e].vertx.y);

		if (x < mod->scale && x >= 0. && y < mod->scale && y >= 0. && !(rand() % 20))
		{
			lm[k].col = mod->tmp;
			lm[k].end = -1;
		}
		else
		{
			lm[k].end = 0;
			lm[k].col = NULL;
		}
		lm[k].x = (float)x;
		lm[k].y = (float)y;
		(void)z;
		lm[k].z = get_z(mod, (float)x, (float)y);
		ang += r;
		k++;
	}
	mod->z_tops[e].ring[i].obj->l_mesh = lm;
}

