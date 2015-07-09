#include "mod1.h"
#include "check_errors.h"

void	move_base_up(t_base *base)
{
	if (!base)
		error(NUL, "base_oper_01.c", "base", TXT_YELLOW);
	base->o.z += VEL_Z;
	base->i.z += VEL_Z;
	base->j.z += VEL_Z;
	base->k.z += VEL_Z;
}

void	move_base_down(t_base *base)
{
	if (!base)
		error(NUL, "base_oper_01.c", "base", TXT_YELLOW);
	base->o.z -= VEL_Z;
	base->i.z -= VEL_Z;
	base->j.z -= VEL_Z;
	base->k.z -= VEL_Z;
}

void	move_base_left(t_base *base)
{
	if (!base)
		error(NUL, "base_oper_01.c", "base", TXT_YELLOW);
	base->o.x -= VEL_X;
	base->i.x -= VEL_X;
	base->j.x -= VEL_X;
	base->k.x -= VEL_X;
}

void	move_base_right(t_base *base)
{
	if (!base)
		error(NUL, "base_oper_01.c", "base", TXT_YELLOW);
	base->o.x += VEL_X;
	base->i.x += VEL_X;
	base->j.x += VEL_X;
	base->k.x += VEL_X;
}

void	move_base_in(t_base *base)
{
	if (!base)
		error(NUL, "base_oper_01.c", "base", TXT_YELLOW);
	base->o.y -= ZOOM_IN;
	base->i.y -= ZOOM_IN;
	base->j.y -= ZOOM_IN;
	base->k.y -= ZOOM_IN;
}

void	move_base_out(t_base *base)
{
	if (!base)
		error(NUL, "base_oper_01.c", "base", TXT_YELLOW);
	base->o.y += ZOOM_OUT;
	base->i.y += ZOOM_OUT;
	base->j.y += ZOOM_OUT;
	base->k.y += ZOOM_OUT;
}
