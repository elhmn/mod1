/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 18:28:34 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/30 19:17:26 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"
#include "debug.h"/*_DEBUG_*/

void	fill_rnd(t_mod *mod, t_vertx *lm, int i, int j)
{
	int		k;
	int		mod_h;
	t_vertx	*om;

	k = i * (mod->scale) + j;
	om = mod->obj->l_mesh;
	mod_h = mod->h - 1;
	if (!lm[k].col && (((int)om[k].z <= (int)lm[k].z)))
	{
		lm[k].col = mod->col_bord;
		lm[k].act = mod->act;
		mod->check++;
		while (mod_h > 0)
		{
			if (mod->trans[mod_h]->l_mesh[k].col == NULL)
			{
				mod->trans[mod_h]->l_mesh[k].col = mod->col_bord;
				mod->trans[mod_h]->l_mesh[k].act = mod->act;

				lm[k].col = NULL;
				mod->check++;
				lm[k].act = mod->act;
				break;
			}
			mod_h--;
		}
	}
	else if (lm[k].col == mod->col_bord && lm[k].act != mod->act)
	{
		mod->check++;
		lm[k].col = mod->col;
	}
}

void	set_lm_up(t_mod *mod, t_vertx *lm)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	if (!mod)
		error(NUL, "mod", "set_lm.c", TXT_YELLOW);
	if (!lm)
		error(NUL, "mod", "set_lm.c", TXT_YELLOW);
	while (++i < mod->scale)
	{
		j = -1;
		while (++j < mod->scale)
		{
			if (lm[k].col && lm[k].act != mod->act)
			{
				fill_rnd(mod, lm, i , j);
				if (j + 1 < mod->scale)
					fill_rnd(mod, lm, i , j + 1);
				if (j - 1 >= 0)
					fill_rnd(mod, lm, i , j - 1);
				if (i + 1 < mod->scale)
					fill_rnd(mod, lm, i + 1, j);
				if (i + 1 < mod->scale && j + 1 < mod->scale)
					fill_rnd(mod, lm, i + 1, j + 1);
				if (i + 1 < mod->scale && j - 1 >= 0)
					fill_rnd(mod, lm, i + 1, j - 1);
				if (i - 1 >= 0)
					fill_rnd(mod, lm, i - 1, j);
				if (j + 1 < mod->scale && i - 1 >= 0)
					fill_rnd(mod, lm, i - 1, j + 1);
				if (j - 1 >= 0 && i - 1 >= 0)
					fill_rnd(mod, lm, i - 1, j - 1);
			}
			k++;
		}
	}
	mod->act++;
}

void		gen_part(t_mod *mod, t_vertx *lm)
{
	int		part_nb;
	int		i;
	int		k;

	k = -1;
	i = 0;
	part_nb = (int)(mod->scale * 5. / 100.);
	while (!lm[++k].end)/*_DEBUG_*/
	{
		if (!lm[k].act)
		{
			lm[k].x = rand() % mod->scale;
			lm[k].y = rand() % mod->scale;
			lm[k].z = mod->z_top;
			lm[k].vel = 1;
			lm[k].act = 1;
			lm[k].col = mod->col;
			if (++i >= part_nb)
				break;
		}
	}
}

void		plan_newelem(t_mod *mod, t_lstpl **plane)
{
	if (plane && !*plane)
	{
		*plane = (t_lstpl*)malloc(sizeof(t_lstpl));
		if (!*plane)
			error(MALLOC, "plane", "set_lm.c", TXT_YELLOW);
		(*plane)->plan = NULL;
		(*plane)->i = 2;
		mod->ind_lvl = (*plane)->i;
		init_obj(mod, &((*plane)->plan), init_lm_trans, set_gbase_trans);
		(*plane)->next = NULL;
	}
}

float	absf(float a)
{
	return ((a < 0) ? a * -1. : a);
}

t_vertx	*getDirUndVel(t_mod *mod, t_vertx *om, int x, int y)
{
	float	tab[8] = {0};
	int		i;
	t_vertx	*e;

	i = 0;
	if (!(e = (t_vertx*)malloc(sizeof(t_vertx))))
		error(MALLOC, "e", "set_lm.c", TXT_YELLOW);
	if ((y - 1 >= 0 && x - 1 >= 0)
		&& (x < mod->scale && y < mod->scale))
		tab[0] = om[(y - 1) * (int)mod->scale + x - 1].z 
			- om[y * (int)mod->scale + x].z;
	if ((y - 1 >= 0)
		&& (x < mod->scale && y < mod->scale))
		tab[1] = om[(y - 1) * (int)mod->scale + x].z 
			- om[y * (int)mod->scale + x].z;
	if ((y - 1 >= 0 && x + 1 < mod->scale)
		&& (x < mod->scale && y < mod->scale))
		tab[2] = om[(y - 1) * (int)mod->scale + x + 1].z 
			- om[y * (int)mod->scale + x].z;
	if ((x - 1 >= 0)
		&& (x < mod->scale && y < mod->scale))
		tab[3] = om[y * (int)mod->scale + x - 1].z 
			- om[y * (int)mod->scale + x].z;
	if ((x + 1 < mod->scale)
		&& (x < mod->scale && y < mod->scale))
		tab[4] = om[y * (int)mod->scale + x + 1].z 
			- om[y * (int)mod->scale + x].z;
	if ((x - 1 >= 0 && y + 1 < mod->scale)
		&& (x < mod->scale && y < mod->scale))
		tab[5] = om[(y + 1) * (int)mod->scale + x - 1].z 
			- om[y * (int)mod->scale + x].z;
	if ((y + 1 < mod->scale)
		&& (x < mod->scale && y < mod->scale))
		tab[6] = om[(y + 1) * (int)mod->scale + x].z 
			- om[y * (int)mod->scale + x].z;
	if ((y + 1 < mod->scale && x + 1 < mod->scale)
			&& (x < mod->scale && y < mod->scale))
		tab[7] = om[(y + 1) * (int)mod->scale + x + 1].z 
			- om[y * (int)mod->scale + x].z;
	tab[i] = (tab[i] > 0) ? 0 : tab[i];
	e->dirz = absf(tab[0]);
	e->dirxy = 0;
	while (++i < 8)
	{
		tab[i] = (tab[i] > 0) ? 0 : tab[i];
		if (e->dirz < absf(tab[i]))
		{
			e->dirz = absf(tab[i]);
			e->dirxy = i;
		}
	}
// 	printf("abs dirz = [%.3f]\n", absf((e->dirz)));
	return (e);
}

void		moveInDirXY(t_mod *mod, t_vertx *lm)
{
	int		i;

	if (lm)
	{
// 		lm->dirz += 3;
 		i = 1;
		if (lm->dirxy == 0)
		{
// 			printf("dir = [%d]\n", lm->dirxy);/*_DEBUG_*/
			lm->x -= (int)i;
			lm->y -= (int)i;
		}
		if (lm->dirxy == 1)
		{
// 			printf("dir = [%d]\n", lm->dirxy);/*_DEBUG_*/
			lm->y -= (int)i;
		}
		if (lm->dirxy == 2)
		{
// 			printf("dir = [%d]\n", lm->dirxy);/*_DEBUG_*/
			lm->x += (int)i;
			lm->y -= (int)i;
		}
		if (lm->dirxy == 3)
		{
// 			printf("dir = [%d]\n", lm->dirxy);/*_DEBUG_*/
			lm->x -= (int)i;
		}
		if (lm->dirxy == 4)
		{
// 			printf("dir = [%d]\n", lm->dirxy);/*_DEBUG_*/
			lm->x += (int)i;
		}
		if (lm->dirxy == 5)
		{
// 			printf("dir = [%d]\n", lm->dirxy);/*_DEBUG_*/
			lm->x -= (int)i;
			lm->y += (int)i;
		}
		if (lm->dirxy == 6)
		{
// 			printf("dir = [%d]\n", lm->dirxy);/*_DEBUG_*/
			lm->y += (int)i;
		}
		if (lm->dirxy == 7)
		{
// 			printf("dir = [%d]\n", lm->dirxy);/*_DEBUG_*/
			lm->y += (int)i;
			lm->x += (int)i;
		}
		lm->x = (lm->x < 0) ? 0 : lm->x;
		lm->x = (lm->x >= mod->scale) ? mod->scale - 1 : lm->x;
		lm->y = (lm->y >= mod->scale) ? mod->scale - 1 : lm->y;
		lm->y = (lm->y < 0) ? 0 : lm->y;
	}
}

int			colInFront(t_mod *mod, t_vertx *lm, t_vertx *pm, int k)
{
	t_vertx *om;
	int		x;
	int		y;

	x = lm[k].x;
	y = lm[k].y;
	om = mod->obj->l_mesh;
	if (lm->dirxy == 0)
	{
		if ((y - 1 >= 0 && x - 1 >= 0)
			&& (x < mod->scale && y < mod->scale)
			&& (pm[(y - 1) * (int)mod->scale + x - 1].col
			|| om[(y - 1) * (int)mod->scale + x - 1].z > lm[k].z + 2.))
			return (1);
	}
	if (lm->dirxy == 1)
	{
		if ((y - 1 >= 0 && x >= 0)
			&& (x < mod->scale && y < mod->scale)
			&& (pm[(y - 1) * (int)mod->scale + x].col
			|| om[(y - 1) * (int)mod->scale + x].z > lm[k].z + 2.))
			return (1);
	}
	if (lm->dirxy == 2)
	{
		if ((y - 1 >= 0 && x + 1 < mod->scale)
			&& (x < mod->scale && y < mod->scale)
			&& (pm[(y - 1) * (int)mod->scale + x + 1].col
			|| om[(y - 1) * (int)mod->scale + x + 1].z > lm[k].z + 2.))
			return (1);
	}
	if (lm->dirxy == 3)
	{
		if ((y >= 0 && x - 1 >= 0)
			&& (x < mod->scale && y < mod->scale)
			&& (pm[(y) * (int)mod->scale + x - 1].col
			|| om[(y) * (int)mod->scale + x - 1].z > lm[k].z + 2.))
			return (1);
	}
	if (lm->dirxy == 4)
	{
		if ((y >= 0 && x >= 0)
			&& (x + 1 < mod->scale && y < mod->scale)
			&& (pm[(y) * (int)mod->scale + x + 1].col
			|| om[(y) * (int)mod->scale + x + 1].z > lm[k].z + 2.))
			return (1);
	}
	if (lm->dirxy == 5)
	{
		if ((y >= 0 && x - 1 >= 0)
			&& (x < mod->scale && y + 1 < mod->scale)
			&& (pm[(y + 1) * (int)mod->scale + x - 1].col
			|| om[(y + 1) * (int)mod->scale + x - 1].z > lm[k].z + 2.))
			return (1);
	}
	if (lm->dirxy == 6)
	{
		if ((y >= 0 && x >= 0)
			&& (x < mod->scale && y + 1 < mod->scale)
			&& (pm[(y + 1) * (int)mod->scale + x].col
			|| om[(y + 1) * (int)mod->scale + x].z > lm[k].z + 2.))
			return (1);
	}
 	if (lm->dirxy == 7)
	{
		if ((y >= 0 && x >= 0)
			&& (x + 1 < mod->scale && y + 1 < mod->scale)
			&& (pm[(y + 1) * (int)mod->scale + x + 1].col
			|| om[(y + 1) * (int)mod->scale + x + 1].z > lm[k].z + 2.))
	 			return (1);
	}
	return (0);
}

void		iscol(t_mod *mod, t_vertx *lm, int k)
{
	t_vertx	*pm;
	int		tmp;

	if (!mod->plane)
		plan_newelem(mod, &(mod->plane));
	pm = mod->plane->plan->l_mesh;
 	tmp = (int)(lm[k].y * (int)mod->scale + lm[k].x);
 	tmp = (tmp >= (int)((int)mod->scale * (int)mod->scale)) ? (int)((int)mod->scale * (int)mod->scale - 1) : tmp;
 	tmp = (tmp < 0) ? 0 : tmp;
// 	mod->plane->plan->l_mesh[tmp].col = mod->col;/*_DEBUG_*/

	if (((lm[k].x >= mod->scale - 1 || lm[k].x <= 0 
		|| lm[k].y >= mod->scale - 1 || lm[k].y <= 0)
		&& !pm[tmp].col) || colInFront(mod, lm, pm, k))
	{
// 		printf("DEBUG\n");/*_DEBUG_*/
// 		printf("dir = [%d]\n", lm->dirxy);/*_DEBUG_*/
		pm[tmp].col = mod->col;/*_DEBUG_*/
		lm[k].act = 0;
		lm[k].col_s = 0;
 		lm[k].vel = 0;
		lm[k].col = NULL;
	}
}

int		checkColWithSurf(t_mod *mod, t_vertx *lm, int k)
{
	int		i;
	int		x;
	int		y;
	t_vertx *om;
	t_vertx *e;

	om = mod->obj->l_mesh;
	x = lm[k].x;
	y = lm[k].y;
	i = (int)(y * (int)mod->scale + x);
	i = (i >= (int)((int)mod->scale * (int)mod->scale)) ? (int)((int)mod->scale * (int)mod->scale - 1) : i;
	i = (i < 0) ? 0 : i;
// 	printf("i == [%d]\n", i);
// 	printf("x == [%d]\n", x);
// 	printf("y == [%d]\n", y);
	if (lm[k].z <= om[i].z + 2. || lm[k].col_s)
	{
		e = getDirUndVel(mod, om, x, y);
		lm[k].dirz = e->dirz;
		lm[k].dirxy = e->dirxy;
		free(e); //delete e
		e = NULL; //delete e
  		moveInDirXY(mod, lm + k);
		lm[k].z = om[i].z + 2.;
		lm[k].col_s = 1;
 		lm[k].vel = 0;
		iscol(mod, lm, k);
		return (1);
	}
	return (0);
}

void		part_handle(t_mod *mod, t_vertx *lm)
{
	int		k;
// 	int		tmp;

	k = -1;
	while (!lm[++k].end)
	{
		if (lm[k].act)
		{
//			check collision with map
			if (checkColWithSurf(mod, lm, k))
				lm[k].col = mod->col;
			else
			{
				lm[k].z -= (lm[k].vel += 3);
 				lm[k].col = mod->col;
				lm[k].act = 1;
				lm[k].col_s = 0;
 				lm[k].col = mod->col;
// 				if (lm[k].z < 0.)
// 				{
// 					lm[k].vel -= 3;
// 					if (lm[k].vel < 0)
// 					{
// 						lm[k].vel = 0;
// 						if (!mod->plane)
// 							plan_newelem(mod, &(mod->plane));
// 						handle segfault
// 						tmp = (int)(lm[k].y * (int)mod->scale + lm[k].x);
// 						tmp = (tmp >= (int)((int)mod->scale * (int)mod->scale)) ? (int)((int)mod->scale * (int)mod->scale - 1) : tmp;
// 						tmp = (tmp < 0) ? 0 : tmp;
// 						mod->plane->plan->l_mesh[tmp].col = mod->col;/*_DEBUG_*/
// 						lm[k].col = NULL;
// 						lm[k].act = 0;
// 					}
// 
// 				}
			}
		}
	}
}

void		set_lm_rain(t_mod *mod, t_vertx *lm)
{
// 	srand(time(NULL) + mod->ind_h++);
 	gen_part(mod, lm);
	part_handle(mod, lm);
}
