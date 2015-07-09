/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:38:12 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/13 20:08:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

/*
** Commencer a coder le generateur 3D de map.
*/

/*
** Test utiliser une formule de surface
**	building standard.
*/

float	fun_surface1(int i, int j, int k_scale, int scale)
{
	double		x;
	double		y;
	double		z;

	x = (double)j / (double)scale;
	y = (double)i / (double)scale;
	z = (-1. + x) * x * (y - 1.) * y;
	return ((float)z * k_scale);
}

void	map_builder(t_mod *mod)
{
	int		i;
	int		j;
	int		e;
	int		i_nd;
	int		i_st;
	int		j_nd;
	int		j_st;
	int		k_scale;
	int		scale;
	float	**map;
	t_list	*ls;
	float	tmp;

	map = mod->map;
	e = 0;
	if (!(ls = mod->tops))
		error(NUL, "map_builder.c", "ls", TXT_YELLOW);
	ft_putendl("je suis map_builder.c"); 
	while (ls)
	{
		k_scale = (mod->k_scale * ls->z) / Z_MAX;
		scale = (k_scale * mod->scale) / mod->k_scale;
		i_st = ((ls->x * mod->scale) / X_MAX) - (scale / 2);
		j_st = ((ls->y * mod->scale) / Y_MAX) - (scale / 2);
		i_nd = i_st + scale;
		j_nd = j_st + scale;
		i = -1;
		while (++i < SCALE)
		{
			j = -1;
			while (++j < SCALE)
			{
				if (i >= i_st && i < i_nd &&  j >= j_st && j < j_nd)
				{
					tmp = fun_surface1(i - i_st, j - j_st, k_scale, scale);
					if (tmp > map[i][j])
					{
						map[i][j] = tmp;
						/*
						if (mod->z_tops[e].vertx.z < map[i][j])
						{
							mod->z_tops[e].vertx.z = map[i][j];
							mod->z_tops[e].vertx.x = j;
							mod->z_tops[e].vertx.y = i;
						}
						*/
					}
				}
				else
					if (map[i][j] < 0.)
						map[i][j] = 0.;
				if (map[i][j] > mod->z_top)
				{
					mod->z_top = map[i][j];
				}
				if (map[i][j] < mod->z_bot)
					mod->z_bot = map[i][j];
			}
		}
		ls = ls->next;
		e++;
	}
	e = -1;
}

void	get_lvl(t_mod *mod)
{
	int		i;
	int		j;
	int		k;
	int		k_scale;
	int		scale;
	float	z;
	t_list	*ls;

	if (!mod || !mod->lvl)
		error(NUL, "mod || mod->lvl", "map_builder.c", TXT_YELLOW);
	if (!(ls = mod->tops))
		error(NUL, "ls", "map_builder.c", TXT_YELLOW);
	z = ls->z;
	while (ls)
	{
		if (z < ls->z)
			z = ls->z;
		ls = ls->next;
	}
//	printf("z = [%2.f]\n", z);/*_DEBUG_*/
	k_scale = (mod->k_scale * z) / Z_MAX;
	scale = (k_scale * mod->scale) / mod->k_scale;
//	printf("scale = [%d]\n", scale);/*_DEBUG_*/
	j = 0;
	i = scale / 2;
	k = 0;
	while (j <= scale / 2 && k < TRANS_NBR)
	{
		 mod->lvl[k]= fun_surface1(i, j, k_scale, scale);
		 k++;
		 j++;
	}
}
