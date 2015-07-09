/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 19:23:58 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/13 21:54:15 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"
#include "debug.h"

void	draw_obj(t_mod *mod, t_obj *obj, char *img)
{
	int		k;
	float	ret;
	float	**tab;
	t_vertx	*sm;

	k = -1;
	tab = mod->img_tab;
	if (!mod)
		error(NUL, "draw_obj.c", "mod", TXT_YELLOW);
	if (!obj->s_mesh)
		error(NUL, "draw_obj.c", "sm", TXT_YELLOW);
	sm = obj->s_mesh;
	while (sm[++k].end != 1)
	{
		if ((int)sm[k].x < S_WIDTH  && (int)sm[k].x >= 0 && (int)sm[k].z < S_HEIGH && (int)sm[k].z >= 0)
		{
			if (((ret = tab[(int)sm[k].z][(int)sm[k].x]) > sm[k].y) || !ret)
			{
				pixel_put_img(mod, (int)sm[k].x, (int)sm[k].z, sm[k].col, img);
				if (mod->pt_surf)
					tab[(int)sm[k].z][(int)sm[k].x] = sm[k].y;
			}
		}
	}
}
