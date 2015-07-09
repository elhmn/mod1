/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_rain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 00:14:20 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/06 16:54:36 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void	init_water_meshes_rain(t_mod *mod, t_color *col, t_color *col_bord, t_color *col_lim)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	(void)col_lim;
	(void)col_bord;
	(void)col;
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
			mod->water->l_mesh[k].z = mod->obj->l_mesh[k].z;
			if ((i == 0 && (!j || j == mod->scale - 1)) || (j == 0 && (!i || i == mod->scale - 1)))
				mod->water->l_mesh[k].col = NULL;//col_lim;
			else if ((i == 0  || j == mod->scale - 1 || j == 0 || i == mod->scale - 1))
				mod->water->l_mesh[k].col = NULL;//col_bord;
			else
			{
				if (!(rand() % 100) && mod->water->l_mesh[k].z == mod->z_bot)
					mod->water->l_mesh[k].col = col;
				else if (!(rand() % 1000) && mod->water->l_mesh[k].z != mod->z_bot)
					mod->water->l_mesh[k].col = col;//mod->tmp;//;mod->obj->s_mesh[k].col;
				else
					mod->water->l_mesh[k].col = NULL;//;mod->obj->s_mesh[k].col;
			}
			mod->water->l_mesh[k].end = 0;
			k++;
		}
	}
//	print_mesh(mod->water->l_mesh);
}

void	init_rain_obj(t_mod *mod, t_color *col, int i)
{
	if (!mod->z_tops[mod->ind_e].ring[i].obj)
	{
		if (!(mod->z_tops[mod->ind_e].ring[i].obj = (t_obj*)malloc(sizeof(t_obj))))
				error(MALLOC, "mod->z_tops[mod->ind_e].ring[i].obj", "dynamic_rain.c", TXT_YELLOW);
			init_rain_meshes(mod, col, i);
			init_rain_bases(mod, i);
	}
	else
		set_rain_meshes(mod, col, i);
	init_rain_bases(mod, i);
}

void	dynamic_rain(t_mod *mod, t_color *col, t_color *col_bord, t_color *col_lim, int i)
{
	(void)col_bord;
	(void)col_lim;
	init_rain_obj(mod, col, i);
	loc_to_glob_rain(mod->z_tops[mod->ind_e].ring[i].obj, mod);
	get_persp_rain(&(mod->z_tops[mod->ind_e].ring[i].obj->s_mesh), mod->z_tops[mod->ind_e].ring[i].obj->g_mesh, mod);
	get_s_map(mod->z_tops[mod->ind_e].ring[i].obj->s_mesh, mod);
}
