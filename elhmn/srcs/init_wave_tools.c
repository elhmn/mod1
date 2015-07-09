/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wave_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 20:26:36 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/06 17:02:17 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

void		init_wave_bases(t_mod *mod)
{
	t_base	*base;

	base = NULL;
	base = &(mod->obj->g_base);
	if (!base)
		error(NUL, "base", "init_wave_tools.c", TXT_YELLOW);
	if (!mod || !mod->wave)
		error(NUL, " mod || mod->wave", "init_wave_tools.c", TXT_YELLOW);
	if (mod->wave)
	{
		mod->wave->g_base.o.x = base->o.x;
		mod->wave->g_base.o.y = base->o.y;
		mod->wave->g_base.o.z = base->o.z;

		mod->wave->g_base.i.x = base->i.x;
		mod->wave->g_base.i.y = base->i.y;
		mod->wave->g_base.i.z = base->i.z;
		
		mod->wave->g_base.j.x = base->j.x;
		mod->wave->g_base.j.y = base->j.y;
		mod->wave->g_base.j.z = base->j.z;
		
		mod->wave->g_base.k.x = base->k.x;
		mod->wave->g_base.k.y = base->k.y;
		mod->wave->g_base.k.z = base->k.z;
	}
}

void	init_wave_meshes(t_mod *mod)
{
	t_vertx	*lm;
	int		k;
	int		i;
	int		j;

	i = 0;
	k = 0;
	if (!mod || !mod->wave)
		error(NUL, "init_wave_tools.c", "mod || mod->wave", TXT_YELLOW);
	lm = mod->wave->l_mesh;
	if (!lm)
		error(NUL, "init_wave_tools.c", "lm", TXT_YELLOW);
	while (i < (int)mod->scale)
	{
		j = 0;
		while (j < (int)mod->scale)
		{
			lm[k].x = (float)i;
			lm[k].y = (float)j;
			lm[k].z = mod->z_bot;
			lm[k].end = 0;
			k++;
			j++;
		}
		i++;
	}
}

void	set_wave_meshes(t_mod *mod)
{
	t_vertx	*lm;
	t_vertx	*om;
	int		i;
	int		j;

	//	if (lm[k].z == mod->obj->l_mesh[((int)lm[k].x * (int)(mod->scale) - 1) + (int)lm[k].y].z && lm[k].act)
	i = 0;
	if (!mod || !mod->wave || !mod->obj)
		error(NUL, "init_wave_tools.c", "mod || mod->wave || mod->obj", TXT_YELLOW);
	lm = mod->wave->l_mesh;
	om = mod->obj->l_mesh;
	if (!lm)
		error(NUL, "init_wave_tools.c", "lm || om", TXT_YELLOW);
	while (i < (int)mod->scale)
	{
		j = 0;
		while (j < (int)mod->scale)
		{
			if (lm[i * ((int)mod->scale - 1) + j].z == om[i * ((int)mod->scale - 1) + j].z)
				lm[i * ((int)mod->scale - 1) + j].col = mod->col_bord;
			else
				lm[i * ((int)mod->scale - 1) + j].col = NULL;
			if (j > 1)
			{
				if (lm[i * ((int)mod->scale - 1) + j - 1].z == om[i * ((int)mod->scale - 1) + j - 1].z)
					lm[i * ((int)mod->scale - 1) + j - 1].col = mod->col_bord;
				else
					lm[i * ((int)mod->scale - 1) + j - 1].col = NULL;
			}
			if (j < mod->scale - 1)
			{
				if (lm[i * ((int)mod->scale - 1) + j + 1].z == om[i * ((int)mod->scale - 1) + j - 1].z)
					lm[i * ((int)mod->scale - 1) + j + 1].col = mod->col_bord;
				else
					lm[i * ((int)mod->scale - 1) + j + 1].col = NULL;
			}
			if (i < mod->scale - 1)
			{
				if (lm[(i + 1) * ((int)mod->scale - 1) + j].z == om[i * ((int)mod->scale - 1) + j].z)
					lm[(i + 1) * ((int)mod->scale - 1) + j].col = mod->col_bord;
				else
					lm[(i + 1) * ((int)mod->scale - 1) + j].col = NULL;
			}
			if (i > 1)
			{
				if (lm[(i - 1) * ((int)mod->scale - 1) + j].z == om[i * ((int)mod->scale - 1) + j].z)
					lm[(i - 1) * ((int)mod->scale - 1) + j].col = mod->col_bord;
				else
					lm[(i - 1) * ((int)mod->scale - 1) + j].col = NULL;
			}
			j++;
		}
		i++;
	}
}
