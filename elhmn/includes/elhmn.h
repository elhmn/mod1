/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elhmn.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:22:31 by bmbarga           #+#    #+#             */
/*   Updated: 2015/04/23 22:19:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELHMN_H
# define ELHMN_H

# include "mod1.h"

# define MAP_X_MAX		400
# define MAP_Z_MAX		400
# define MAP_Y_MAX		1000 // (opt)

# define UNIT			10 // (opt)
# define O_X			0
# define O_Y			0

/*
typedef struct s_coord	t_coord;
typedef struct s_base	t_base;
typedef struct s_pos	t_pos;
typedef struct s_pt		t_pt;

struct			s_pos
{
	double	x;
	double	y;
};

struct			s_pt
{
	double	x;
	double	y;
	double	z;
};

struct			s_coord
{
	t_pt	pt;
	t_pos	pos;
	int		end;
};


struct			s_base
{
	t_coord		o;
	t_coord		i;
	t_coord		j;
	t_coord		k;
};
*/
#endif
