/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 01:40:55 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/06 17:26:41 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

void	move_water_up(t_base *base)
{
	if (!base)
		error(NUL, "dynamic_up.c", "base", TXT_YELLOW);
	base->o.z += VEL_WZ;
	base->i.z += VEL_WZ;
	base->j.z += VEL_WZ;
	base->k.z += VEL_WZ;
}

void		init_water_bases(t_mod *mod)
{
	t_base	*base;

	base = NULL;
	base = &(mod->obj->g_base);
	if (!base)
		error(NUL, "base", "dynamic_up.c", TXT_YELLOW);
	if (mod->water)
	{
		mod->water->g_base.o.x = base->o.x;
		mod->water->g_base.o.y = base->o.y;
		mod->water->g_base.o.z = base->o.z;

		mod->water->g_base.i.x = base->i.x;
		mod->water->g_base.i.y = base->i.y;
		mod->water->g_base.i.z = base->i.z;
		
		mod->water->g_base.j.x = base->j.x;
		mod->water->g_base.j.y = base->j.y;
		mod->water->g_base.j.z = base->j.z;
		
		mod->water->g_base.k.x = base->k.x;
		mod->water->g_base.k.y = base->k.y;
		mod->water->g_base.k.z = base->k.z;
		
		base = &(mod->obj->l_base);
	
		mod->water->l_base.o.x = base->o.x;
		mod->water->l_base.o.y = base->o.y;
		mod->water->l_base.o.z = base->o.z;	
		
		mod->water->l_base.i.x = base->i.x;
		mod->water->l_base.i.y = base->i.y;
		mod->water->l_base.i.z = base->i.z;
		
		mod->water->l_base.j.x = base->j.x;
		mod->water->l_base.j.y = base->j.y;
		mod->water->l_base.j.z = base->j.z;
		
		mod->water->l_base.k.x = base->k.x;
		mod->water->l_base.k.y = base->k.y;
		mod->water->l_base.k.z = base->k.z;
	}
}

void		init_water_meshes(t_mod *mod, t_color *col, t_color *col_bord, t_color *col_lim)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	mod->water->l_mesh = (t_vertx*)malloc(sizeof(t_vertx) * (mod->scale * mod->scale + 1));
	if (!mod->water->l_mesh)
		error(MALLOC, "dynamic_up.c", "mod->water->l_mesh", TXT_YELLOW);
	mod->water->l_mesh[mod->scale * mod->scale].end = 1;
	while (++i < mod->scale)
	{
		j = -1;
		while (++j < mod->scale)
		{
			mod->water->l_mesh[k].x = (float)j;
			mod->water->l_mesh[k].y = (float)i;
			mod->water->l_mesh[k].z = mod->z_bot;
			if ((i == 0 && (!j || j == mod->scale - 1)) || (j == 0 && (!i || i == mod->scale - 1)))
				mod->water->l_mesh[k].col = col_lim;
			else if ((i == 0  || j == mod->scale - 1 || j == 0 || i == mod->scale - 1))
				mod->water->l_mesh[k].col = col_bord;
			else
				mod->water->l_mesh[k].col = col;
			mod->water->l_mesh[k].end = 0;
			k++;
		}
	}
//	print_mesh(mod->water->l_mesh);
	loc_to_glob(mod->water, mod);
	get_persp(&(mod->water->s_mesh), mod->water->g_mesh, mod);
	get_s_map(mod->water->s_mesh, mod);
}

void	water_init(t_mod *mod, t_color *col, t_color *col_bord, t_color *col_lim)
{
	if (!mod)
		error(MALLOC, "dynamic_up.c", "mod", TXT_YELLOW);
	if (!(mod->water = (t_obj*)malloc(sizeof(t_obj))))
		error(MALLOC, "dynamic_up.c", "mod->ater", TXT_YELLOW);
	init_water_bases(mod);
	init_water_meshes(mod, col, col_bord, col_lim);
}

void	dynamic_up(t_mod *mod, t_color *col, t_color *col_bord, t_color *col_lim)
{
	if (!mod)
		error(MALLOC, "dynamic_up.c", "mod", TXT_YELLOW);
	if (!mod->water)
		water_init(mod, col, col_bord, col_lim);
}
