/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:02:18 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/11 18:25:40 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "debug.h"
#include "check_errors.h"

void		del_tops(void *elem, size_t size)
{
	(void)size;
	free(elem);
}

void		del_tab(float **tab)
{
	int		i;

	i = -1;
	while (++i < S_HEIGH)
		free((void*)(*(tab + i)));
	free((void*)tab);
}

void		del_map(float **map)
{
	int		i;

	i = -1;
	while (++i < (int)SCALE)
		free((map[i]));
	free(map);
}

void		del_trans(t_obj	***trans)
{
	t_obj	**tmp;
	int		i;

	i = -1;
	tmp = *trans;
	if (trans && *trans)
	{
		while (++i < TRANS_NBR)
		{
			if (tmp[i]->l_mesh)
				free(tmp[i]->l_mesh);
			if (tmp[i]->s_mesh)
				free(tmp[i]->s_mesh);
			if (tmp[i]->g_mesh)
				free(tmp[i]->g_mesh);
			tmp[i]->l_mesh = NULL;
			tmp[i]->s_mesh = NULL;
			tmp[i]->g_mesh = NULL;
			free(tmp[i]);
			tmp[i] = NULL;
		}
		free(*trans);
		*trans = NULL;
	}
}

void		del_plane(t_mod *mod)
{
	t_lstpl	*pl;

	pl = mod->plane;
	if (pl)
	{
		if (pl->plan)
		{
			if (pl->plan->l_mesh)
				free(pl->plan->l_mesh);
			if (pl->plan->s_mesh)
				free(pl->plan->s_mesh);
			if (pl->plan->g_mesh)
				free(pl->plan->g_mesh);
			pl->plan->l_mesh = NULL;
			pl->plan->s_mesh = NULL;
			pl->plan->g_mesh = NULL;
			free(pl->plan);
			pl->plan = NULL;
		}
		free(pl);
		mod->plane = NULL;
	}
}

void		del_rain(t_mod *mod)
{
	if (mod->rain)
	{
		if (mod->rain->l_mesh)
			free(mod->rain->l_mesh);
		if (mod->rain->s_mesh)
			free(mod->rain->s_mesh);
		if (mod->rain->g_mesh)
			free(mod->rain->g_mesh);
		mod->rain->l_mesh = NULL;
		mod->rain->s_mesh = NULL;
		mod->rain->g_mesh = NULL;
		free(mod->rain);
		mod->rain = NULL;
	}
}

void		destroy_mod(t_mod *mod)
{
	if (!mod)
		error(NUL, "destroy_mod.c", "mod", TXT_YELLOW);
	/*
	** mod->... free && free_sub
	*/

	/*
		water;
		rain;
		wave;
		obj;
		z_tops;
	*/
	if (mod->tmp)
		free(mod->tmp);
	if (mod->img_tab)
		del_tab(mod->img_tab);
	if (mod->tops)
		ft_lstdel(&(mod->tops), del_tops);
	mlx_destroy_window(mod->e.mlx, mod->e.win);
	mlx_destroy_image(mod->e.mlx, mod->buf1);
	mlx_destroy_image(mod->e.mlx, mod->buf2);
	mlx_destroy_image(mod->e.mlx, mod->buf3);
	mlx_destroy_image(mod->e.mlx, mod->buf4);
	if (mod->col)
		free(mod->col);
	if (mod->col_bord)
		free(mod->col_bord);
	if (mod->col_lim)
		free(mod->col_lim);
	if (!mod)
		free(mod);
	ft_putcol_endl(TXT_GREEN, "je suis destroy_mod.c");/*_DEBUG_*/
}
