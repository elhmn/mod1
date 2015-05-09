/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:33:17 by bmbarga           #+#    #+#             */
/*   Updated: 2015/04/28 20:00:57 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "header.h"
#include "debug.h" /*_DEBUG_*/

#include <stdio.h> /*_DEBUG_*/

/*
** - ALGO BASIQUE 3 (with maths) ::
** 1- determiner les pts en utilisant le polynome de lagrange
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

/*TO_DO :: CHECKER LES DIVISIONS PAR ZERO ET CORRIGER CE SEGFAULT BIZZARE*/

int		main(int ac, char **av)
{
	t_mod		mod;
	char		*file;

	file = ft_strsub(av[1], 0,  ft_strlen(av[1]));
//	ft_putcol(TXT_YELLOW, "je suis main.c. :D\n\n"); /*_DEBUG_*/
	if (ac == 1)
		ft_putendl("Hey !! I need a non binary file.");
	else if (ac == 2)
	{
//		data_error(&mod);// NYI
		init_mod(&mod, file);
//		ft_putendl(file); /*_DEBUG_*/
//		print_map(mod.map); /*_DEBUG_*/
//		ft_putcol(TXT_RED, "l_mesh :: \n");/*_DEBUG_*/
//		print_mesh_line(mod.obj->l_mesh);/*_DEBUG_*/
//		ft_putcol(TXT_RED, "g_mesh :: \n");/*_DEBUG_*/
//		print_mesh_line(mod.obj->g_mesh);/*_DEBUG_*/
//		ft_putcol(TXT_RED, "s_mesh :: \n");/*_DEBUG_*/
//		print_mesh_line(mod.obj->s_mesh);/*_DEBUG_*/
		mlx_loop(mod.e.mlx); /** loop **/
		free(file);
		destroy_mod(&mod);
	}
	else
		ft_putendl("Too much arguments.");
	return (0);
}
