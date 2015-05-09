#include "mod1.h"
#include "check_errors.h"

void	init_l_base(t_base *l_base)
{
	if (!l_base)
		check_errors(NUL, "init_scene.c", "l_base");
	l_base->i.x = 1.;
	l_base->i.y = 0.;
	l_base->i.z = 0.;
	l_base->i.end = 0;
	l_base->i.col = NULL;
	if (!(l_base->i.col = init_color(NULL, RED)))
		check_errors(MALLOC, "i.col", "init_scene.c");
	l_base->j.x = 0.;
	l_base->j.y = 1.;
	l_base->j.z = 0.;
	l_base->j.end = 0;
	l_base->j.col = NULL;
	if (!(l_base->j.col = init_color(NULL, GREEN)))
		check_errors(MALLOC, "j.col", "init_scene.c");
	l_base->k.x = 0.;
	l_base->k.y = 0.;
	l_base->k.z = 1.;
	l_base->k.end = 0;
	l_base->k.col = NULL;
	if (!(l_base->i.col = init_color(NULL, BLUE)))
		check_errors(MALLOC, "k.col", "init_scene.c");
}

void	init_g_base(t_base *g_base)
{
	if (!g_base)
		check_errors(NUL, "init_scene.c", "g_base");
	g_base->i.x = 1.;
	g_base->i.y = 0.;
	g_base->i.z = 0.;
	g_base->i.end = 0;
	g_base->i.col = NULL;
	if (!(g_base->i.col = init_color(NULL, RED)))
		check_errors(MALLOC, "i.col", "init_scene.c");
	g_base->j.x = 0.;
	g_base->j.y = 1.;
	g_base->j.z = 0.;
	g_base->j.end = 0;
	g_base->j.col = NULL;
	if (!(g_base->j.col = init_color(NULL, GREEN)))
		check_errors(MALLOC, "j.col", "init_scene.c");
	g_base->k.x = 0.;
	g_base->k.y = 0.;
	g_base->k.z = 1.;
	g_base->k.end = 0;
	g_base->k.col = NULL;
	if (!(g_base->k.col = init_color(NULL, BLUE)))
		check_errors(MALLOC, "k.col", "init_scene.c");
}

void	init_centers(t_base *l_base, t_base *g_base)
{
	if (!l_base || !g_base)
		check_errors(NUL, "init_scene.c", "bases");
	l_base->o.x = 0.;
	l_base->o.y = 0.;
	l_base->o.z = 0.;
	l_base->o.end = 0;
	l_base->o.col = NULL;
	if (!(l_base->o.col = init_color(NULL, WHITE)))
		check_errors(MALLOC, "o.col", "init_scene.c");
	g_base->o.x = 0.;
	g_base->o.y = 0.;
	g_base->o.z = 0.;
	g_base->o.end = 0;
	g_base->o.col = NULL;
	if (!(g_base->o.col = init_color(NULL, WHITE)))
		check_errors(MALLOC, "o.col", "init_scene.c");
}

void		init_scene(t_mod *mod)
{
	ft_putcol(TXT_YELLOW, "i am init_scene\n");
	init_centers(&(mod->glob.l_base), &(mod->glob.g_base));
	init_g_base((&(mod->glob.g_base)));
	init_l_base((&(mod->glob.l_base)));
}
