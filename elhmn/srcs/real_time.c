/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:51:34 by bmbarga           #+#    #+#             */
/*   Updated: 2015/05/05 05:48:20 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

/*
** Fonction de loop:
** 1- affichage de la map a l'ecran.
** 1'- Essayer d'eliminer les faces caches.
** 2- gere les evenements.
** 3- gere l'ecoulement de l'eau
*/

void	put_obj(t_mod *mod)
{
	int		k;
	int		i;
	int		j;
	float	ret;

	t_vertx	*sm;
	float	tab[S_HEIGH][S_WIDTH] = {{0.}};
//	t_color	*col;
//	t_uint	r;
//	t_uint	g;
//	t_uint	b;
	(void)i;
	(void)j;
	k = -1;
	sm = NULL;
	if (!mod)
		check_errors(NUL, "real_time.c", "mod");
	if (!(sm = mod->obj->s_mesh))
		check_errors(NUL, "real_time.c", "sm");
//	col = init_color(NULL, (t_uint)100);
//	r = col->r;
//	g = col->g;
//	b = col->b;
	while (!sm[++k].end)
	{
		if ((int)sm[k].x < S_WIDTH  && (int)sm[k].x >= 0 && (int)sm[k].z < S_HEIGH && (int)sm[k].z >= 0)
		{

//			col->r = (mod->z_top) ? (t_uint)((float)(r * mod->obj->l_mesh[k].z) / mod->z_top) : r;
//			col->g = (mod->z_top) ? (t_uint)((float)(g * mod->obj->l_mesh[k].z) / mod->z_top) : g;
//			col->b = (mod->z_top) ? (t_uint)((float)(b * mod->obj->l_mesh[k].z) / mod->z_top) : b;
//			print_color(col);/*_DEBUG_*/
//			printf("\n");/*_DEBUG_*/
//			printf("val = [%f]\n", ((float)(r * mod->obj->l_mesh[k].z) / mod->z_top));
//			print_color(col);/*_DEBUG_*/
//			printf("\n");/*_DEBUG_*/
	//		printf("sm[%d].x = [%.2f]\n", k, sm[k].x);
	//		printf("sm[%d].z = [%.2f]\n", k, sm[k].z);
//			low_light(col, (int)((float)(255. * mod->obj->l_mesh[k].z) / mod->z_top), 1);
			if (((ret = tab[(int)sm[k].z][(int)sm[k].x]) > sm[k].y) || !ret)
			{
				pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z, sm[k].col);
				tab[(int)sm[k].z][(int)sm[k].x] = sm[k].y;
			}
//			pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z, col);
		}
	}
	/*
	i = -1;
	while (++i < SCALE)
	{
		j = -1;
		while (++j < SCALE)
		{
			printf("[%2.2f] ", tab[i][j]);
		}
		printf("\n");

	}	
	*/
//	free(col);
}

int		real_time(t_mod *mod)
{
	if (!mod)
		check_errors(NUL, "real_time.c", "mod");
	if (mod->refresh == 1)
	{
	//	ft_putendl("I can refresh."); /*_DEBUG_*/
//		put_map(mod);/*_DEBUG_*/
//		print_map(mod->map); /*_DEBUG_*/
//		clear image (may be)
		clear_img(mod);
		loc_to_glob(mod->obj, mod);
		get_persp(&(mod->obj->s_mesh), mod->obj->g_mesh, mod);
		get_s_map(mod->obj->s_mesh, mod);
		put_obj(mod);
		mlx_clear_window(mod->e.mlx, mod->e.win);
		mlx_put_image_to_window(mod->e.mlx, mod->e.win, mod->bg, 0, 0);
		mod->refresh = 0;
		free(mod->obj->s_mesh);
		free(mod->obj->g_mesh);
	}
	return (0);
}
