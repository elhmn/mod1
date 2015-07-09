/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:33:17 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/13 21:52:28 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "header.h"
#include "check_errors.h"

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

int		main(int ac, char **av)
{
	t_mod		*mod;
	char		*file;

	if (ac == 1)
		ft_putcol_endl(TXT_RED, "Hey !! I need a non binary file.");
	else if (ac == 2)
	{
		file = ft_strsub(av[1], 0,  ft_strlen(av[1]));
		if (!(mod = (t_mod*)malloc(sizeof(t_mod))))
			error(MALLOC, "main.c", "mod", TXT_YELLOW);
		init_mod(mod, file);
		free(file);
		mlx_loop(mod->e.mlx);
	}
	else
		ft_putcol_endl(TXT_RED, "Too much arguments.");
	return (0);
}
