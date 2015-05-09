#include "mod1.h"
#include "check_errors.h"

void	init_cam(t_mod *mod)
{
	t_cam *cam;

	cam = NULL;
	if (!mod)
		check_errors(NUL, "init_cam.c", "mod");
	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		check_errors(NUL, "init_cam.c", "cam");
	cam->l_mesh = NULL;
	cam->g_mesh = NULL;
	cam->s_mesh = NULL;
	init_l_base(&(cam->l_base));
	init_g_base(&(cam->g_base));
	mod->cam = cam;
}
