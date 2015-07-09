/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_void.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 20:33:05 by bmbarga           #+#    #+#             */
/*   Updated: 2015/07/03 10:59:47 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

/*
** old version
*/

/*
void	tab_zero(float **tab)
{
	int	i;
	int	j;

	i = -1;
	while (++i < S_HEIGH)
	{
		j = -1;
		while (j++ < S_WIDTH)
			tab[i][j] = 0.;
	}
}

void	put_obj(t_mod *mod, t_vertx *sm, char *img)
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
			if (((ret = tab[(int)sm[k].z][(int)sm[k].x]) > sm[k].y) || !ret)
			{
				pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z, sm[k].col, img);
				tab[(int)sm[k].z][(int)sm[k].x] = sm[k].y;
			}
		}
	}
}

void	put_surface(t_mod *mod)
{
	tab_zero(mod->img_tab);
	clear_img(mod, mod->img);
	loc_to_glob(mod->obj, mod);
	get_persp(&(mod->obj->s_mesh), mod->obj->g_mesh, mod);
	get_s_map(mod->obj->s_mesh, mod);
	put_obj(mod, mod->obj->s_mesh, mod->img);
	mlx_clear_window(mod->e.mlx, mod->e.win);
	mlx_put_image_to_window(mod->e.mlx, mod->e.win, mod->bg, 0, 0);
	mod->refresh = 0;
}

void	real_void(t_mod *mod)
{
	free(mod->obj->s_mesh);
	free(mod->obj->g_mesh);
	put_surface(mod);
	mod->refresh = 0;
}
*/

void	tab_zero(float **tab)
{
	int	i;
	int	j;

	i = -1;
	while (++i < S_HEIGH)
	{
		j = -1;
		while (j++ < S_WIDTH)
			tab[i][j] = 0.;
	}
}

void	real_void(t_mod *mod)
{
	clear_img(mod, mod->img1);
	tab_zero(mod->img_tab);
	if (mod->upd_sm)
		update_sm(mod, mod->obj);
	draw_obj(mod, mod->obj, mod->img1);
	on_window(mod, 1, 0, 0);
	mod->upd_sm = 0;
}
