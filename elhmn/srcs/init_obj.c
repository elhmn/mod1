#include "mod1.h"
#include "check_errors.h"

void	init_obj(t_mod *mod)
{
	t_obj *obj;

	obj = NULL;
	if (!mod)
		check_errors(NUL, "init_cam.c", "mod");
	if (!(obj = (t_obj*)malloc(sizeof(t_obj))))
		check_errors(NUL, "init_obj.c", "obj");
	obj->l_mesh = NULL;
	obj->g_mesh = NULL;
	obj->s_mesh = NULL;
	init_l_base(&(obj->l_base));
	init_g_base(&(obj->g_base));
	mod->obj = obj;
}
