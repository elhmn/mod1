/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 20:33:07 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/23 18:32:24 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** draw things in a window... (mostly lines)
*/

static void	draw_vertical(t_lst *a, t_lst *b, t_env *e)
{
	int		y;
	char	rev;

	rev = a->y_pix > b->y_pix ? 1 : 0;
	y = a->y_pix;
	while (y != b->y_pix)
	{
		mlx_pixel_put(e->mlx, e->win, a->x_pix, y, clr(a, b, e));
		rev ? y-- : y++;
	}
}

static void	draw_rev(t_lst *a, t_lst *b, t_env *e)
{
	double	alpha;
	int		beta;
	int		x;
	int		y;
	char	rev;

	rev = a->y_pix > b->y_pix ? 1 : 0;
	alpha = (double)(b->y_pix - a->y_pix) / (double)(b->x_pix - a->x_pix);
	beta = (b->x_pix * a->y_pix - a->x_pix * b->y_pix) / (b->x_pix - a->x_pix);
	y = a->y_pix;
	while (y != b->y_pix)
	{
		x = (int)((y - beta) / alpha);
		mlx_pixel_put(e->mlx, e->win, x, y, clr(a, b, e));
		rev ? y-- : y++;
	}
}

void	draw_line(t_lst *a, t_lst *b, t_env *e)
{
	double	alpha;
	int		beta;
	int		x;
	int		y;
	char	rev;

	if (a->x_pix == b->x_pix)
		draw_vertical(a, b, e);
	if (a->x_pix == b->x_pix)
		return ;
	rev = a->x_pix > b->x_pix ? 1 : 0;
	alpha = (double)(b->y_pix - a->y_pix) / (double)(b->x_pix - a->x_pix);
	if (alpha > 1 || alpha < -1)
	{
		draw_rev(a, b, e);
		return ;
	}
	beta = (b->x_pix * a->y_pix - a->x_pix * b->y_pix) / (b->x_pix - a->x_pix);
	x = a->x_pix;
	while (x != b->x_pix)
	{
		y = (int)(alpha * x + beta);
		mlx_pixel_put(e->mlx, e->win, x, y, clr(a, b, e));
		rev ? x-- : x++;
	}
}

void	draw(t_env *e)
{
	t_lst	*tmp;
	t_lst	*swap;

	tmp = ft_llast(&e->first_l);
	while (tmp && tmp->prev)
	{
		if (tmp->y == tmp->prev->y)
			draw_line(tmp, tmp->prev, e);
		swap = tmp->prev;
		while (swap)
		{
			if (swap->x == tmp->x && (swap->y - 1) == tmp->y)
			{
				draw_line(tmp, swap, e);
				break ;
			}
			swap = swap->prev;
		}
		tmp = tmp->prev;
	}
}
