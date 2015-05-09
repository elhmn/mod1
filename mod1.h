/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:35:16 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/23 16:05:35 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 1- Rediger les prototypes, fonctions principales du programmes.
** 2- Determiner les structures de donnees.
** 3- Attribution des taches.
*/

/*
** Structure globale du main du mod1 (main.c) ::
*/

/*
** 1- get_data											(bmbarga)
** 2- check data error									(bmbarga)
** 3- init t_mod mod									(bmbarga) (mcanal)
** 4- build map											(bmbarga)
** 5- simulation hydrodynamique (temps reel)			(mcanal)
** 		-- Affichage de l'aquarium (ou just map).		(mcanal) / (bmbarga
**  - Destroy t_mod datas								(mcanal) (bmbarga)
*/

#ifndef MOD1_H
# define MOD1_H

# include "libft.h"
# include <mlx.h>
# include "x.h"
# include <stdlib.h>

# define TRUE	1
# define FALSE	0

typedef struct	s_mod	t_mod;
typedef unsigned int	t_uint;

struct		s_mod
{
	void	*mlx;
	void	*win;
	int		**map;	// map de l'espace 3D
	int		**s_map; // coordonnee a l'ecran
};

/*
** get_data.c
*/

void	get_data(t_mod *mod, char *file);

/*
** data_error.c
*/

void	data_error(t_mod *mod);

/*
** init_mod.c
*/

void	init_mod(t_mod *mod);

/*
** map_builder.c
*/

void	map_builder(t_mod *mod);

/*
** real_time.c
*/

/*
** 0- Est une fonction de loop:
** 1- affichage de la map a l'ecran.
** 2- gere les evenements.
** 3- gere l'ecoulement de l'eau
*/

void	real_time(t_mod *mod);

/*
** destroy_mod.c
*/

void	destroy_mod(t_mod *mod);

#endif
