/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:37:32 by bmbarga           #+#    #+#             */
/*   Updated: 2015/07/02 14:25:21 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "debug.h"
#include "check_errors.h"
#include "time.h"
#include <stdio.h> /*_DEBUG_*/

int		key_release(int key, t_mod *mod)
{
//	ft_putcol_endl(TXT_YELLOW, "key_release ::");/*_DEBUG*/
	if (!mod)
		error(NUL, "event_handle_01.c", "mod", TXT_YELLOW);
	if (key == K_ESCAPE)
	{
		destroy_mod(mod);
		exit(0);
	}
//	print_type("key", &key, INT); /*_DEBUG_*/
	mod->refresh = 1;
	return (0);
}

int		mouse_hook(int button, int x, int y, t_mod *mod)
{
//	ft_putcol_endl(TXT_YELLOW, "mouse_hook ::");/*_DEBUG_*/
	if (!mod)
		error(NUL, "event_handle_01.c", "mod", TXT_YELLOW);
	(void)x;
	(void)y;
	(void)button;
//	print_type("button", &button, INT);/*_DEBUG_*/
//	print_type("x", &x, INT);/*_DEBUG_*/
//	print_type("y", &y, INT);/*_DEBUG_*/
	mod->refresh = 1;
	return (0);
}

void	reset_ring_vel(t_mod *mod)
{
	int		e;
	int		i;

	e = -1;
	if (!mod)
		error(NUL, "event_handle_01.c", "mod", TXT_YELLOW);
	if (!mod->z_tops)
		error(NUL, "event_handle_01.c", "mod->z_tops", TXT_YELLOW);
	while (mod->z_tops[++e].vertx.end != 1)
	{
		if (!mod->z_tops[e].ring)
			break;
		i = -1;
		while (++i < mod->z_tops[e].div)
		{
			mod->z_tops[e].ring[i].st = i * (mod->z_tops[e].vertx.z / mod->z_tops[e].div);
			mod->z_tops[e].ring[i].r_vel = 1;
		}
	}
}

int		key_press(int key, t_mod *mod)
{
	if (!mod)
		error(NUL, "event_handle_01.c", "mod", TXT_YELLOW);
	print_type("key", &key, INT);/*_DEBUG_*/
	if (key == K_LEFT)
	{
		move_base_left(&(mod->obj->g_base));
	//	update_sm(mod, mod->obj);
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_RIGHT)
	{
		move_base_right(&(mod->obj->g_base));
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_DOWN)
	{
		move_base_down(&(mod->obj->g_base));
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_UP)
	{
		move_base_up(&(mod->obj->g_base));
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_PLUS)
	{
		move_base_in(&(mod->obj->g_base));
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_MOINS)
	{
		move_base_out(&(mod->obj->g_base));
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_1)
	{
		rot_base_z(&(mod->obj->g_base), ROT);
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_ENTER)
	{
		if (mod->st_lm)
			mod->st_lm = 0;
		else
			mod->st_lm = 1;
	}

	if (key == K_BP)
	{
		set_gbase_surf(mod, mod->obj);
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_2)
	{
		rot_base_z(&(mod->obj->g_base), -ROT);
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_4)
	{
		rot_base_y(&(mod->obj->g_base), ROT);
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_5)
	{
		rot_base_y(&(mod->obj->g_base), -ROT);
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_7)
	{
		rot_base_x(&(mod->obj->g_base), ROT);
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_8)
	{
		rot_base_x(&(mod->obj->g_base), -ROT);
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_W)
	{
		mod->obj->g_base.k.z += 0.01; //1 / K_SCALE;
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_S)
	{
		mod->obj->g_base.k.z -= 0.01; //1 / K_SCALE;
		mod->upd_sm = 1;
		mod->pt_surf = 1;
	}
	if (key == K_U1)
	{
		if (mod->ecoul == VOID)
		{
			del_trans(&(mod->trans));
			init_trans(mod, init_lm_trans_up);
			mod->upd_sm = 1;
			mod->ind_h = 0;
			mod->pt_surf = 1;
			mod->st_lm = 1;
			mod->check = 0;
			mod->ecoul = UP;
		}
	}
	if (key == K_U2)
	{
		mod->ecoul = VOID;
		mod->pt_surf = 1;
	}
	if (key == K_TAB)
	{
		if (mod->slowMo)
			mod->slowMo = 0;
		else
			mod->slowMo = 1;
	}
	if (key == K_U3)
	{
		if (mod->ecoul == VOID)
		{
			del_rain(mod);
			del_plane(mod);
			init_obj(mod, &(mod->rain), init_lm_rain, set_gbase_trans);
 			mod->upd_sm = 1;
 			mod->pt_surf = 1;
	  		mod->st_lm = 1;
  			mod->check = 0;
			gen_part(mod, mod->rain->l_mesh);
			mod->ecoul = RAIN;
		}
	}
	if (key == K_U4)
	{
		if (mod->ecoul == VOID)
		{
			/*
			clear_img(mod, mod->img2);
			mod->pos = 0;
			mod->bol = 0;
			*/
			del_trans(&(mod->trans));
			init_trans(mod, init_lm_trans_wave);
			mod->upd_sm = 1;
			mod->ind_h = 0;
			mod->pt_surf = 1;
			mod->st_lm = 1;
			mod->check = 0;
			mod->ecoul = WAVE;
		}
	}
	mod->refresh = 1;
	return (0);
}

int		motion_notify(int x, int y, t_mod *mod)
{
//	ft_putcol_endl(TXT_YELLOW, "motion_notify ::");/*_DEBUG*/
	if (!mod)
		error(NUL, "event_handle_01.c", "mod", TXT_YELLOW);
	(void)x;
	(void)y;
//	print_type("x", &x, INT);/*_DEBUG_*/
//	print_type("y", &y, INT);/*_DEBUG_*/
	mod->refresh = 1;
	return (0);
}

int		expose_hook(t_mod *mod)
{
	if (!mod)
		error(NUL, "event_handle_01.c", "mod", TXT_YELLOW);
	mod->refresh = 1;
	return (0);
}
