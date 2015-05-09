/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:38:12 by bmbarga           #+#    #+#             */
/*   Updated: 2015/05/05 05:48:38 by bmbarga          ###   ########.fr       */
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
/*
float	fun_surface(int i, int j, t_mod *mod, int Sn)
{
	double		x;
	double		y;
	double		z;

	(void)mod;
	x = (double)j / (double)Sn;
	y = (double)i / (double)Sn;
	z = (-1. + x) * x * (y - 1.) * y;
	return ((float)z * mod->k_scale);
}
*/
float	fun_surface1(int i, int j, int k_scale, int scale)
{
	double		x;
	double		y;
	double		z;

	x = (double)j / (double)scale;//mod->scale;
	y = (double)i / (double)scale;//mod->scale;
	z = (-1. + x) * x * (y - 1.) * y;
	return ((float)z * k_scale);
}

/*
float	fun_surface(int i, int j, t_mod *mod)
{
	double		x;
	double		y;
	double		z;

	(void)mod;
	x = (double)j / (double)mod->scale;
	y = (double)i / (double)mod->scale;
	z = sin(2. * M_PI * x) * sin(2 * M_PI * y) / 4.;
	return ((float)z * mod->scale);
}

void	map_builder(t_mod *mod)
{
	int		i;
	int		j;
	float	**map;
	float	tmp;

	map = mod->map;
	ft_putendl("je suis map_builder.c");
		i = -1;
		while (++i < SCALE)
		{
			j = -1;
			while (++j < SCALE)
			{
				{
					tmp = fun_surface1(i, j, mod->k_scale, mod->scale);
					if (tmp > map[i][j])
						map[i][j] = tmp;//fun_surface(i, j, mod);
				}
				if (map[i][j] > mod->z_top)
					mod->z_top = map[i][j];
				if (map[i][j] < mod->z_bot)
					mod->z_bot = map[i][j];
			}
		}
}
*/

void	map_builder(t_mod *mod)
{
	int		i;
	int		j;
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
	if (!(ls = mod->tops))
		check_errors(NUL, "map_builder.c", "ls");
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
						map[i][j] = tmp;//fun_surface(i, j, mod);
				}
				else
					if (map[i][j] < 0.)
						map[i][j] = 0.;
				if (map[i][j] > mod->z_top)
					mod->z_top = map[i][j];
				if (map[i][j] < mod->z_bot)
					mod->z_bot = map[i][j];
			}
		}
		ls = ls->next;
	}
}
