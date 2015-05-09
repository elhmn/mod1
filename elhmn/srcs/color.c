/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:33:40 by bmbarga           #+#    #+#             */
/*   Updated: 2015/05/05 05:45:15 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"
#include <stdio.h>/*_DEBUG_*/

t_color	*init_color(t_color *color, t_uint col)
{
	if (!color)
		if (!(color = (t_color*)malloc(sizeof(t_color))))
			check_errors(MALLOC, "color", "color.c");
	color->color = col;
	color->r = (col & MASK_R) >> (8 * 2);
	color->g = (col & MASK_G) >> 8;
	color->b = (col & MASK_B);
	color->alpha = 0;
	return (color);
}

void	set_color(t_color *col, t_uint r, t_uint g, t_uint b)
{
	if (col)
	{
		col->r = r;
		col->g = g;
		col->b = b;
		col->alpha = 0;
		col->color = rgb_to_color(col->r, col->g, col->b);
	}
}

t_uint	rgb_to_color(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int color;

	color = 0;
	r = (r << 8 * 2);
	g = (g << 8);
	color = r | g | b;
	return (color);
}



t_color	*degrad_col(t_color *Ci, t_color *Cf, float Zi, float Zf, float Zn)
{
	t_color *result;
	float	r;			//raison Ci-Cn
	float	Rz;			//raison Rz Zi-Zn
	float	Gz;			//raison Gz Zi-Zn
	float	Bz;			//raison Bz Zi-Zn
	t_uint	Rn;
	t_uint	Gn;
	t_uint	Bn;

	r = RC;
	Rz = ((Zf - Zi) / (Cf->r - Ci->r)) * r;
	Gz = ((Zf - Zi) / (Cf->g - Ci->g)) * r;
	Bz = ((Zf - Zi) / (Cf->b - Ci->b)) * r;
	Rn = (t_uint)(r * (Zn - Zi) / Rz + Ci->r);
	Gn = (t_uint)(r * (Zn - Zi) / Gz + Ci->g);
	Bn = (t_uint)(r * (Zn - Zi) / Bz + Ci->b);

	result = NULL;
	if (!(result = init_color(NULL, 0)))
		check_errors(MALLOC, "color.c", "result");
	set_color(result, Rn, Gn, Bn);
	return (result);
}

static void		aux_low_light(t_color *color, t_uint inc)
{
	if ((int)color->r - (int)inc > 0)
		color->r -= inc;
	else
		color->r = 0;
	if ((int)color->g - (int)inc > 0)
		color->g -= inc;
	else
		color->g = 0;
	if (((int)color->b - (int)inc) > 0)
		color->b -= inc;
	else
		color->b = 0;
}

void			low_light(t_color *color, unsigned int inc, int sign)
{
	if (color)
	{
		if (sign > 0)
		{
			if ((int)color->r + (int)inc < 256)
				color->r += inc;
			else
				color->r = 255;
			if ((int)color->g + (int)inc < 256)
				color->g += inc;
			else
				color->g = 255;
			if ((int)color->b + (int)inc < 256)
				color->b += inc;
			else
				color->b = 255;
		}
		else
			aux_low_light(color, inc);
		color->color = rgb_to_color(color->r, color->g, color->b);
	}
}

void	print_color(t_color *color)
{
	if (color)
	{
		printf("color->col = [%d]\n", color->color);
		printf("color->r = [%d]\n", color->r);
		printf("color->g = [%d]\n", color->g);
		printf("color->b = [%d]\n", color->b);
		printf("color->a = [%d]\n", color->alpha);
	}
}
