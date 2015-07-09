/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/20 12:03:26 by bmbarga           #+#    #+#             */
/*   Updated: 2015/05/20 19:49:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include <math.h>
#include <unistd.h>
#include "X.h"

#define HEIGH	400
#define WIDTH	800
#define COL		0x00FFFFFF

# define ABS(x) (x < 0) ? -x : x

typedef struct	s_draw
{
	int		ex;
	int		ey;
	int		incx;
	int		incy;
	int		dx;
	int		dy;
	int		color;
}				t_draw;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*bg;
	char	*img;
}				t_env;

typedef	struct	s_pt
{
	double	x;
	double	y;
	int		bol;
}				t_pt;

typedef struct	s_aret
{
	t_pt	a;
	t_pt	b;
	double	len;
	double	pente;
	double	p;// correspond a (y = ax + p)
	t_pt	vect;
}				t_aret;


static t_draw	*init_d(t_draw *d, t_pt a, t_pt b, int col)
{
	if (!d)
	{
		if (!(d = (t_draw*)malloc(sizeof(t_draw))))
		{
			perror("d malloc");
			return (0);
		}
	}
	d->dx = abs(b.x - a.x);
	d->dy = abs(b.y - a.y);
	d->incx = (b.x < a.x) ? -1 : 1;
	d->incy = (b.y < a.y) ? -1 : 1;
	d->ex = 2 * d->dx;
	d->ey = 2 * d->dy;
	d->color = col;
	return (d);
}

static void		draw_1(t_env *e, t_pt a, t_draw *d)
{
	int		fun_choice;
	int		i;

	i = 0;
	fun_choice = d->ey - d->dx;
	mlx_pixel_put(e->mlx, e->win, a.x, a.y, d->color);
	while (i < d->dx)
	{
		if (fun_choice < 0)
			fun_choice += d->ey;
		else
		{
			fun_choice += d->ey - d->ex;
			a.y += d->incy;
		}
		a.x += d->incx;
		i++;
	mlx_pixel_put(e->mlx, e->win, a.x, a.y, d->color);
	}
}

static void		draw_2(t_env *e, t_pt a, t_draw *d)
{
	int		fun_choice;
	int		i;

	i = 0;
	fun_choice = d->ex - d->dy;
	mlx_pixel_put(e->mlx, e->win, a.x, a.y, d->color);
	while (i < d->dy)
	{
		if (fun_choice < 0)
			fun_choice += d->ex;
		else
		{
			fun_choice += d->ex - d->ey;
			a.x += d->incx;
		}
		a.y += d->incy;
		i++;
	}
	mlx_pixel_put(e->mlx, e->win, a.x, a.y, d->color);
}

void			draw_line(t_env *e, t_pt a, t_pt b, int color)
{
	t_draw	*d;

	d = init_d(NULL, a, b, color);
	if (d->dx > d->dy)
		draw_1(e, a, d);
	else
		draw_2(e, a, d);
	free(d);
}

/*
** end draw line;
*/

void	init_aret(t_aret *ar, t_pt a, t_pt b)
{
	ar->a.x = a.x;
	ar->a.y = a.y;

	ar->b.x = b.x;
	ar->b.y = b.y;

	ar->len = sqrt(pow(ar->b.x - ar->a.x, 2) + pow(ar->b.y - ar->a.y, 2));
	ar->vect.x = ar->b.x - ar->a.x;
	ar->vect.y = ar->b.y - ar->a.y;
	ar->pente = (!ar->vect.x || !ar->vect.y) ? 0 : (ar->b.y - ar->a.y) / (ar->b.x - ar->a.x);
	ar->p = ar->a.y - ar->pente * ar->a.x;
}

void	put_aret(char *str, t_aret ar)
{
	printf("\nput--> %s :: \n", str);
	printf("ar.a.x = [%.2f] && ar.a.y = [%.2f]\n", ar.a.x, ar.a.y);
	printf("ar.b.x = [%.2f] && ar.b.y = [%.2f]\n", ar.b.x, ar.b.y);
	printf("ar.vect.x = [%.2f] && ar.vect.y = [%.2f]\n", ar.vect.x, ar.vect.y);
	printf("ar.len = [%.2f]\n", ar.len);
	printf("ar.pente = [%.2f]\n", ar.pente);
	printf("ar.p = [%.2f]\n", ar.p);
	printf("end_put --> %s :: \n\n", str);
}

double	dist(t_pt a, t_pt b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

int		aux_coll(t_aret ar, t_pt *p1, t_pt *p2, int i)
{
	t_pt	m;

	if (!ar.vect.y)
	{
		if (ar.a.y == (double)i)
		{
			p1->x = ar.a.x;
			p1->y = ar.a.y;
			p1->bol = 1;
			p2->x = ar.b.x;
			p2->y = ar.b.y;
			p2->bol = 1;
		}
	}
	else if (!ar.vect.x)
	{
		m.x = ar.a.x;
		m.y = (double)i;
		if ((int)(dist(ar.a, m) + dist(ar.b, m)) <= (int)ar.len)
		{
			if (!p1->bol)
			{
				p1->x = m.x;
				p1->y = m.y;
				p1->bol = 1;
			}
			else if (!p2->bol)
			{
				p2->x = m.x;
				p2->y = m.y;
				p2->bol = 1;
			}
		}
	}
	else
	{
		m.x = (double)((double)i - ar.p) / (double)ar.pente;
		m.y = (double)i;
		if ((int)(dist(ar.a, m) + dist(ar.b, m)) <= (int)ar.len)
		{
			if (!p1->bol)
			{
				p1->x = m.x;
				p1->y = m.y;
				p1->bol = 1;
			}
			else if (!p2->bol)
			{
				p2->x = m.x;
				p2->y = m.y;
				p2->bol = 1;
			}
//			printf("p1.x = [%.2f] && p1.y = [%.2f]\n", p1->x, p1->y);
//			printf("p2.x = [%.2f] && p2.y = [%.2f]\n\n", p2->x, p2->y);
		}
	}
	if (p1->bol && p2->bol)
			return (1);
	return (0);
}

int		collision(t_aret a1, t_aret a2, t_aret a3, t_aret a4, t_pt *p1, t_pt *p2, int i)
{
	(void)a3;
	(void)a1;
	
	if (aux_coll(a2, p1, p2, i))
	{
//		printf("a2 ::\n");
//			printf("p1.x = [%.2f] && p1.y = [%.2f]\n", p1->x, p1->y);
//			printf("p2.x = [%.2f] && p2.y = [%.2f]\n", p2->x, p2->y);
		return (1);
	}
	if (aux_coll(a3, p1, p2, i))
	{
//		printf("a3 ::\n");
//			printf("p1.x = [%.2f] && p1.y = [%.2f]\n", p1->x, p1->y);
//			printf("p2.x = [%.2f] && p2.y = [%.2f]\n", p2->x, p2->y);
		return (1);
	}
	if (aux_coll(a4, p1, p2, i))
	{
//		printf("a4 ::\n");
//			printf("p1.x = [%.2f] && p1.y = [%.2f]\n", p1->x, p1->y);
//			printf("p2.x = [%.2f] && p2.y = [%.2f]\n", p2->x, p2->y);
		return (1);
	}

	if (aux_coll(a1, p1, p2, i))
	{
//		printf("a1 ::\n");
//			printf("p1.x = [%.2f] && p1.y = [%.2f]\n", p1->x, p1->y);
//			printf("p2.x = [%.2f] && p2.y = [%.2f]\n", p2->x, p2->y);
		return (1);
	}
	return (0);
}

# define YEL 0x00FF0000

void	fill_polygone(t_env *e, t_pt a, t_pt b, t_pt c, t_pt d)
{
	t_aret	a1;
	t_aret	a2;
	t_aret	a3;
	t_aret	a4;
	t_pt	p1;
	t_pt	p2;
	int		i;

	i = -1;
	(void)i;
	init_aret(&a1, a, b);
//	put_aret("a1", a1);
	init_aret(&a2, a, c);
//	put_aret("a2", a2);
	init_aret(&a3, c, d);
//	put_aret("a3", a3);
	init_aret(&a4, b, d);
//	put_aret("a4", a4);
	while (++i < HEIGH)
	{
		p1.bol = 0;
		p2.bol = 0;
		if (collision(a1, a2, a3, a4, &p1, &p2, i))
		{
			printf("i = [%d]\n", i);
//			printf("p1.x = [%.2f] && p1.y = [%.2f]\n", p1.x, p1.y);
//			printf("p2.x = [%.2f] && p2.y = [%.2f]\n\n", p2.x, p2.y);
//			draw_line(e, p1, p2, YEL);
			if (p1.x < p2.x)
			{
				while (p1.x <= p2.x)
				{
					mlx_pixel_put(e->mlx, e->win, p1.x, i, YEL);
					p1.x++;
				}
			}
			else
			{
				while (p2.x <= p1.x)
				{
					mlx_pixel_put(e->mlx, e->win, p2.x, i, YEL);
					p2.x++;
				}
			}
			usleep(2000);
		}
	}
}


int		main(int ac, char **av)
{
	t_env	*e;
	t_pt	p;
	t_pt	a;
	t_pt	b;
	t_pt	c;
	t_pt	d;

	p.x = WIDTH / 2.;
	p.y = HEIGH / 2.;
	
	a.x = 50;
	a.y = 50;
	
	c.x = 100;
	c.y = (double)HEIGH / 3.;

	b.x = (double)WIDTH / 4.;
	b.y = 10;
	
	d.x = (double)HEIGH / 2.;
	d.y = (double)HEIGH / 2.;
	
	(void)av;
	e = NULL;
	if (!(e = (t_env*)malloc(sizeof(t_env))))
	{
		perror("env malloc");
		return (0);
	}
	e->mlx = NULL;
	e->win = NULL;
	if (ac)
	{
		if (!(e->mlx = mlx_init()))
		{
			perror("e->mlx malloc");
			return (0);
		}
		if (!(e->win = mlx_new_window(e->mlx, WIDTH, HEIGH, "test")))
		{
			perror("e->win malloc");
			return (0);
		}
//		printf("test 1\n");/*_DEBUG_*/
		fill_polygone(e, a, b, c, d);
		mlx_pixel_put(e->mlx, e->win, (int)p.x, (int)p.y, COL);
		mlx_pixel_put(e->mlx, e->win, (int)a.x, (int)a.y, COL);
		mlx_pixel_put(e->mlx, e->win, (int)b.x, (int)b.y, COL);
		mlx_pixel_put(e->mlx, e->win, (int)c.x, (int)c.y, COL);
		mlx_pixel_put(e->mlx, e->win, (int)d.x, (int)d.y, COL);
//		printf("test\n");/*_DEBUG_*/
		mlx_loop(e->mlx);
	}
	return (0);
}
