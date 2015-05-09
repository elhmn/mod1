/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:37:32 by bmbarga           #+#    #+#             */
/*   Updated: 2015/05/04 22:23:47 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "debug.h"
#include "check_errors.h"
#include <stdio.h> /*_DEBUG_*/

int		key_release(int key, t_mod *mod)
{
//	ft_putcol_endl(TXT_YELLOW, "key_release ::");/*_DEBUG*/
	if (!mod)
		check_errors(NUL, "event_handle_01.c", "mod");
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
		check_errors(NUL, "event_handle_01.c", "mod");
	(void)x;
	(void)y;
	(void)button;
//	print_type("button", &button, INT);/*_DEBUG_*/
//	print_type("x", &x, INT);/*_DEBUG_*/
//	print_type("y", &y, INT);/*_DEBUG_*/
	mod->refresh = 1;
	return (0);
}

int		key_press(int key, t_mod *mod)
{
//	ft_putcol_endl(TXT_YELLOW, "key_press ::");/*_DEBUG*/
	if (!mod)
		check_errors(NUL, "event_handle_01.c", "mod");
//	print_type("key", &key, INT);/*_DEBUG_*/
	if (key == K_LEFT)
	{
		move_base_left(&(mod->obj->g_base));
	}
	if (key == K_RIGHT)
	{
		move_base_right(&(mod->obj->g_base));
	}
	if (key == K_DOWN)
	{
		move_base_down(&(mod->obj->g_base));
		//mod->obj->g_base.k.z += 0.1; //1 / K_SCALE;
	}
	if (key == K_UP)
	{
		move_base_up(&(mod->obj->g_base));
	//	mod->obj->g_base.k.z -= 0.1;//1 / K_SCALE;
	}
	if (key == K_PLUS)
	{
		move_base_in(&(mod->obj->g_base));
	}
	if (key == K_MOINS)
	{
		move_base_out(&(mod->obj->g_base));
	}
	if (key == K_1)
	{
		rot_base_z(&(mod->obj->g_base), ROT);
	}
	if (key == K_2)
	{
		rot_base_z(&(mod->obj->g_base), -ROT);
	}
	if (key == K_4)
	{
		rot_base_y(&(mod->obj->g_base), ROT);
	}
	if (key == K_5)
	{
		rot_base_y(&(mod->obj->g_base), -ROT);
	}
	if (key == K_7)
	{
		rot_base_x(&(mod->obj->g_base), ROT);
	}
	if (key == K_8)
	{
		rot_base_x(&(mod->obj->g_base), -ROT);
	}
	if (key == K_W)
	{
		mod->obj->g_base.k.z += 0.01; //1 / K_SCALE;
	}
	if (key == K_S)
	{
		mod->obj->g_base.k.z -= 0.01; //1 / K_SCALE;
	}
	mod->refresh = 1;
	return (0);
}

int		motion_notify(int x, int y, t_mod *mod)
{
//	ft_putcol_endl(TXT_YELLOW, "motion_notify ::");/*_DEBUG*/
	if (!mod)
		check_errors(NUL, "event_handle_01.c", "mod");
	(void)x;
	(void)y;
//	print_type("x", &x, INT);/*_DEBUG_*/
//	print_type("y", &y, INT);/*_DEBUG_*/
	mod->refresh = 1;
	return (0);
}

int		expose_hook(t_mod *mod)
{
//	ft_putcol_endl(TXT_YELLOW, "expose_hook ::");/*_DEBUG*/
	if (!mod)
		check_errors(NUL, "event_handle_01.c", "mod");
	mod->refresh = 1;
	return (0);
}
