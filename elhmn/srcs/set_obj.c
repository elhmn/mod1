#include "mod1.h"
#include "check_errors.h"
#include <stdio.h>

void	map_to_mesh(float **map, t_obj *obj, t_mod *mod)
{
	t_vertx	*mesh;
	t_color *coln;
	t_color	*coli;
	t_color	*colf;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	coln = NULL;
	coli = NULL;
	colf = NULL;
	mesh = NULL;
	if (!(coli = init_color(NULL, 0x440044)))
		check_errors(MALLOC, "set_obj.c", "coli");
	if (!(colf = init_color(NULL, 0xFF6666)))
		check_errors(MALLOC, "set_obj.c", "colf");
	if (!mod)
		check_errors(NUL, "set_obj.c", "mod");
	if (!map)
		check_errors(NUL, "set_obj.c", "map");
	if (!obj)
		check_errors(NUL, "set_obj.c", "obj");
	mesh = (t_vertx *)malloc(sizeof(t_vertx) * (mod->scale * mod->scale + 1));
	if (!mesh)
		check_errors(MALLOC, "set_obj.c", "mesh");
	mesh[mod->scale * mod->scale].end = 1;
	j = 0;
	while (++i < mod->scale)
	{
		j = -1;
		while (++j < mod->scale)
		{
			mesh[k].x = j;
			mesh[k].y = i;
			mesh[k].z = map[i][j];
			mesh[k].end = 0;
			coln = degrad_col(coli, colf, mod->z_bot, mod->z_top, mesh[k].z);
			if (!coln)
				check_errors(MALLOC, "set_obj.c", "coln");
			mesh[k].col = coln;
			k++;
		}
	}
	obj->l_mesh = mesh;
	free(coli);
	free(colf);
}

void	try_ltog(t_obj *obj)
{
	if (!obj)
		check_errors(NUL, "set_obj.c", "obj");
	if (!obj->l_mesh)
		check_errors(NUL, "set_obj.c", "l_mesh");
}

void	loc_to_glob(t_obj *obj, t_mod *mod)
{
	int		k;
	t_vertx	*lm;
	t_vertx	*gm;
	t_base	gbs;

	k = -1;
	try_ltog(obj);
	lm = obj->l_mesh;
	if (!mod)
		check_errors(NUL, "set_obj.c", "mod");
	if (!(obj->g_mesh = (t_vertx*)malloc(sizeof(t_vertx) * (mod->scale * mod->scale + 1))))
		check_errors(MALLOC, "set_obj.c", "g_mesh");
	obj->g_mesh[mod->scale * mod->scale].end = 1;
	gm = obj->g_mesh;
	gbs = obj->g_base;
	while (!lm[++k].end)
	{
		gm[k].x = (gbs.i.x - gbs.o.x) * lm[k].x + (gbs.i.y - gbs.o.y) * lm[k].y + (gbs.i.z - gbs.o.z) * lm[k].z + gbs.o.x;
		gm[k].y = (gbs.j.x - gbs.o.x) * lm[k].x + (gbs.j.y - gbs.o.y) * lm[k].y + (gbs.j.z - gbs.o.z) * lm[k].z + gbs.o.y;
		gm[k].z = (gbs.k.x - gbs.o.x) * lm[k].x + (gbs.k.y - gbs.o.y) * lm[k].y + (gbs.k.z - gbs.o.z) * lm[k].z + gbs.o.z;
		gm[k].col = lm[k].col;
		gm[k].end = lm[k].end;
	}
}

void	obj_set_g_base(t_base *base, t_mod *mod)
{
	if (!base)
		check_errors(NUL, "set_obj.c", "base");
		base->o.x = 0;
		base->o.y = mod->dist;
		base->o.z = 0;
		base->o.col = NULL;
		if (!(base->o.col = init_color(NULL, WHITE)))
			check_errors(MALLOC, "set_obj.c", "o.col");
		base->i.x = 1;
		base->i.y = mod->dist;
		base->i.z = 0;
		base->i.col = NULL;
		if (!(base->i.col = init_color(NULL, RED)))
			check_errors(MALLOC, "set_obj.c", "i.col");
		base->j.x = 0;
		base->j.y = mod->dist + 1;
		base->j.z = 0;
		base->j.col = NULL;
		if (!(base->j.col = init_color(NULL, BLUE)))
			check_errors(MALLOC, "set_obj.c", "j.col");
		base->k.x = 0;
		base->k.y = mod->dist;
		base->k.z = 1;
		base->k.col = NULL;
		if (!(base->k.col = init_color(NULL, BLUE)))
			check_errors(MALLOC, "set_obj.c", "k.col");
}

void	get_persp(t_vertx **sm, t_vertx *gm, t_mod *mod)
{
	int		k;
	float	dist_so;
	float	dtmp;

	k = -1;
	(void)k;
	(void)gm;
	if (!mod)
		check_errors(NUL, "set_obj.c", "mod");
	if (!(*sm = (t_vertx*)malloc(sizeof(t_vertx) * (mod->scale * mod->scale + 1))))
		check_errors(NUL, "set_obj.c", "sm");
	sm[0][mod->scale * mod->scale].end = 1;
	dist_so = ((float)S_WIDTH / 2.) / (float)(sin((double)(FIELD / 2.)) / cos((double)(FIELD / 2.)));
//	printf("\033[33mdist_so = [%.2f] \n\033[0m", dist_so);/*_DEBUG_*/
	while (!gm[++k].end)
	{
		dtmp = (dist_so / (float)gm[k].y);
		sm[0][k].x = gm[k].x * dtmp;
		sm[0][k].y = sqrt(pow(gm[k].y, 2.) + pow(gm[k].z, 2.) + pow(gm[k].x, 2.));
		sm[0][k].z = gm[k].z * dtmp;
		sm[0][k].col = gm[k].col;
		sm[0][k].end = gm[k].end;
	}
}

void	get_s_map(t_vertx *sm, t_mod *mod)
{
	int		k;

	k = -1;
	if (!mod)
		check_errors(NUL, "set_obj.c", "mod");
	if (!sm)
		check_errors(NUL, "set_obj.c", "sm");
	while (!sm[++k].end)
	{
		sm[k].x += ((float)S_WIDTH / 2.);
		sm[k].z = sm[k].z * -1. + ((float)S_HEIGH / 2.);
	}
}

void	set_obj(t_mod *mod)
{
//	printf("i am set obj ::\n");/*_DEBUG_*/
//	printf("mod = [%p]\n", mod);/*_DEBUG_*/
	if (!mod)
		check_errors(NUL, "mod", "set_obj.c");
	map_to_mesh(mod->map, mod->obj, mod);
	obj_set_g_base(&(mod->obj->g_base), mod);
//	print_base(&(mod->obj->g_base));/*_DEBUG_*/
//	loc_to_glob(mod->obj, mod);
//	get_persp(&(mod->obj->s_mesh), mod->obj->g_mesh, mod);
//	ft_putcol(TXT_RED, "s_mesh :: \n");/*_DEBUG_*/
//	print_mesh_line(mod->obj->s_mesh);/*_DEBUG_*/
//	get_s_map(mod->obj->s_mesh);
}
