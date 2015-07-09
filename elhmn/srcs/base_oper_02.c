#include "mod1.h"
#include "check_errors.h"

void	rot_base_z(t_base *base, float rot)
{	
	float	o_x;
	float	o_y;
	float	i_x;
	float	i_y;
	float	j_x;
	float	j_y;
	float	k_x;
	float	k_y;
	float	tmpx;
	float	tmpy;

	if (!base)
		error(NUL, "base_oper_02.c", "base", TXT_YELLOW);
	o_x = base->o.x;
	o_y = base->o.y;
	i_x = base->i.x;
	i_y = base->i.y;
	j_x = base->j.x;
	j_y = base->j.y;
	k_x = base->k.x;
	k_y = base->k.y;

/*ROTATION*/

	base->o.x = o_x * (float)cos((double)rot) - o_y * (float)sin((double)rot);
	base->o.y = o_x * (float)sin((double)rot) + o_y * (float)cos((double)rot);
	base->i.x = i_x * (float)cos((double)rot) - i_y * (float)sin((double)rot);
	base->i.y = i_x * (float)sin((double)rot) + i_y * (float)cos((double)rot);
	base->j.x = j_x * (float)cos((double)rot) - j_y * (float)sin((double)rot);
	base->j.y = j_x * (float)sin((double)rot) + j_y * (float)cos((double)rot);
	base->k.x = k_x * (float)cos((double)rot) - k_y * (float)sin((double)rot);
	base->k.y = k_x * (float)sin((double)rot) + k_y * (float)cos((double)rot);

	tmpx = base->o.x;
	tmpy = base->o.y;
	base->o.x = o_x - tmpx + base->o.x;
	base->o.y = o_y - tmpy + base->o.y;

	base->i.x = o_x - tmpx + base->i.x;
	base->i.y = o_y - tmpy + base->i.y;
	base->j.x = o_x - tmpx + base->j.x;
	base->j.y = o_y - tmpy + base->j.y;
	base->k.x = o_x - tmpx + base->k.x;
	base->k.y = o_y - tmpy + base->k.y;
}

void	rot_base_y(t_base *base, float rot)
{	
	float	o_x;
	float	o_z;
	float	i_x;
	float	i_z;
	float	j_x;
	float	j_z;
	float	k_x;
	float	k_z;
	float	tmpx;
	float	tmpz;

	if (!base)
		error(NUL, "base_oper_02.c", "base", TXT_YELLOW);
	o_x = base->o.x;
	o_z = base->o.z;
	i_x = base->i.x;
	i_z = base->i.z;
	j_x = base->j.x;
	j_z = base->j.z;
	k_x = base->k.x;
	k_z = base->k.z;

/*ROTATION*/

	base->o.x = o_x * (float)cos((double)rot) - o_z * (float)sin((double)rot);
	base->o.z = o_x * (float)sin((double)rot) + o_z * (float)cos((double)rot);
	base->i.x = i_x * (float)cos((double)rot) - i_z * (float)sin((double)rot);
	base->i.z = i_x * (float)sin((double)rot) + i_z * (float)cos((double)rot);
	base->j.x = j_x * (float)cos((double)rot) - j_z * (float)sin((double)rot);
	base->j.z = j_x * (float)sin((double)rot) + j_z * (float)cos((double)rot);
	base->k.x = k_x * (float)cos((double)rot) - k_z * (float)sin((double)rot);
	base->k.z = k_x * (float)sin((double)rot) + k_z * (float)cos((double)rot);

	tmpx = base->o.x;
	tmpz = base->o.z;
	base->o.x = o_x - tmpx + base->o.x;
	base->o.z = o_z - tmpz + base->o.z;

	base->i.x = o_x - tmpx + base->i.x;
	base->i.z = o_z - tmpz + base->i.z;
	base->j.x = o_x - tmpx + base->j.x;
	base->j.z = o_z - tmpz + base->j.z;
	base->k.x = o_x - tmpx + base->k.x;
	base->k.z = o_z - tmpz + base->k.z;
}

void	rot_base_x(t_base *base, float rot)
{	
	float	o_y;
	float	o_z;
	float	i_y;
	float	i_z;
	float	j_y;
	float	j_z;
	float	k_y;
	float	k_z;
	float	tmpy;
	float	tmpz;

	if (!base)
		error(NUL, "base_oper_02.c", "base", TXT_YELLOW);
	o_y = base->o.y;
	o_z = base->o.z;
	i_y = base->i.y;
	i_z = base->i.z;
	j_y = base->j.y;
	j_z = base->j.z;
	k_y = base->k.y;
	k_z = base->k.z;

/*ROTATION*/

	base->o.y = o_y * (float)cos((double)rot) - o_z * (float)sin((double)rot);
	base->o.z = o_y * (float)sin((double)rot) + o_z * (float)cos((double)rot);
	base->i.y = i_y * (float)cos((double)rot) - i_z * (float)sin((double)rot);
	base->i.z = i_y * (float)sin((double)rot) + i_z * (float)cos((double)rot);
	base->j.y = j_y * (float)cos((double)rot) - j_z * (float)sin((double)rot);
	base->j.z = j_y * (float)sin((double)rot) + j_z * (float)cos((double)rot);
	base->k.y = k_y * (float)cos((double)rot) - k_z * (float)sin((double)rot);
	base->k.z = k_y * (float)sin((double)rot) + k_z * (float)cos((double)rot);

	tmpy = base->o.y;
	tmpz = base->o.z;
	base->o.y = o_y - tmpy + base->o.y;
	base->o.z = o_z - tmpz + base->o.z;

	base->i.y = o_y - tmpy + base->i.y;
	base->i.z = o_z - tmpz + base->i.z;
	base->j.y = o_y - tmpy + base->j.y;
	base->j.z = o_z - tmpz + base->j.z;
	base->k.y = o_y - tmpy + base->k.y;
	base->k.z = o_z - tmpz + base->k.z;
}
