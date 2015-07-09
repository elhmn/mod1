/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:51:34 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/30 18:55:34 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

void	on_window(t_mod *mod, int buf1, int buf2, int buf3)
{
	mlx_clear_window(mod->e.mlx, mod->e.win);
	if (buf1)
		mlx_put_image_to_window(mod->e.mlx, mod->e.win, mod->buf1, 0, 0);
	if (buf2)
		mlx_put_image_to_window(mod->e.mlx, mod->e.win, mod->buf2, 0, 0);
	if (buf3)
		mlx_put_image_to_window(mod->e.mlx, mod->e.win, mod->buf3, 0, 0);
}

void	update_sm(t_mod *mod, t_obj *obj)
{
	if (!mod || !obj)
		error(NUL, "mod || mod->obj", "real_time.c", TXT_YELLOW);
	loc_to_glob(mod, obj);
	get_persp(mod, obj);
	get_sm(mod, obj);
}

/*
** Fonction de loop:
*/

int		real_time(t_mod *mod)
{
	if (!mod)
		error(NUL, "real_time.c", "mod", TXT_YELLOW);
	if (mod->refresh == 1)
	{
		if (mod->ecoul == VOID)
			real_void(mod);
		else if (mod->ecoul == UP)
			real_up(mod);
		else if (mod->ecoul == RAIN)
			real_rain(mod);
		else if (mod->ecoul == WAVE)
			real_wave(mod);
		if (mod->slowMo)
			usleep(100000);
	}
	return (0);
}
