/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_gbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 16:53:24 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/13 20:05:09 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

/*
** set_gbase_surf )==> set surface's global base
*/

void	set_gbase_surf(t_mod *mod, t_obj *obj)
{
	t_base *base;

	(void)mod;
	if (!obj)
		error(NUL, "set_gbase.c", "obj", TXT_YELLOW);
	base = &(obj->g_base);
	base->o.x = -120.;
	base->o.y = mod->dist;
	base->o.z = -60.;
	base->o.col = NULL;
	if (!(base->o.col = init_color(NULL, WHITE)))
		error(MALLOC, "set_gbase.c", "o.col", TXT_YELLOW);
	base->i.x = -120.309082;
	base->i.y = mod->dist + 0.950684;
	base->i.z = -60.000031;
	base->i.col = NULL;
	if (!(base->i.col = init_color(NULL, RED)))
		error(MALLOC, "set_gbase.c", "i.col", TXT_YELLOW);
	base->j.x = -120.904053;
	base->j.y = mod->dist - (1. - 0.706299);
	base->j.z = -60.308853;
	base->j.col = NULL;
	if (!(base->j.col = init_color(NULL, BLUE)))
		error(MALLOC, "set_gbase.c", "j.col", TXT_YELLOW);
	base->k.x = -120.293945;
	base->k.y = mod->dist - (1. - 0.904541);
	base->k.z = -59.048950;
	base->k.col = NULL;
	if (!(base->k.col = init_color(NULL, BLUE)))
		error(MALLOC, "set_gbase.c", "k.col", TXT_YELLOW);
}

void	set_gbase_trans(t_mod *mod, t_obj *obj)
{
	t_base *base;

	(void)mod;
	if (!obj)
		error(NUL, "set_gbase.c", "obj", TXT_YELLOW);
	base = &(mod->obj->g_base);
	if (obj)
	{
		obj->g_base.o.x = base->o.x;
		obj->g_base.o.y = base->o.y;
		obj->g_base.o.z = base->o.z;

		obj->g_base.i.x = base->i.x;
		obj->g_base.i.y = base->i.y;
		obj->g_base.i.z = base->i.z;
		
		obj->g_base.j.x = base->j.x;
		obj->g_base.j.y = base->j.y;
		obj->g_base.j.z = base->j.z;
		
		obj->g_base.k.x = base->k.x;
		obj->g_base.k.y = base->k.y;
		obj->g_base.k.z = base->k.z;
		
		base = &(mod->obj->l_base);
	
		obj->l_base.o.x = base->o.x;
		obj->l_base.o.y = base->o.y;
		obj->l_base.o.z = base->o.z;	
		
		obj->l_base.i.x = base->i.x;
		obj->l_base.i.y = base->i.y;
		obj->l_base.i.z = base->i.z;
		
		obj->l_base.j.x = base->j.x;
		obj->l_base.j.y = base->j.y;
		obj->l_base.j.z = base->j.z;
		
		obj->l_base.k.x = base->k.x;
		obj->l_base.k.y = base->k.y;
		obj->l_base.k.z = base->k.z;
	}
}
