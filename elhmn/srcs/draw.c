/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:13:51 by bmbarga           #+#    #+#             */
/*   Updated: 2015/05/15 05:54:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "debug.h"
#include "check_errors.h"

void		pixel_put_img(t_mod *mod, int x, int y, t_color *col, char *img)
{
	int		size;
	t_lay	lay;
	int		b;

	lay = *(mod->lay);
	if (col && img)
	{
		size = lay.line;
		b = lay.bpp / 8;
//		printf("bpp = [%d]\n", lay.bpp);
		x *= b;
		if (size > 0 && (y < S_HEIGH && y >= 0)
				&& (x >= 0 && x + lay.bpp / 8 < lay.line))
		{
			img[(y * (size)) + x + 0] = col->b;
			img[(y * (size)) + x + 1] = col->g;
			img[(y * (size)) + x + 2] = col->r;
			img[(y * (size)) + x + 3] = col->alpha;
		}
	}
}
