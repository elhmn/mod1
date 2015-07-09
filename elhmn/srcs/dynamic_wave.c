/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_wave.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 19:48:37 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/06 16:56:44 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"
#include <stdio.h> /*_DEBUG_*/

void	dynamic_wave(t_mod *mod)
{
	if (!mod)
		error(NUL, "mod", "dynamic_wave.c", TXT_YELLOW);
	if (!mod->wave)
	{
		printf("init wave\n");
		if (!(mod->wave = (t_obj*)malloc(sizeof(t_obj))))
			error(NUL, "mod->wave", "dynamic_wave.c", TXT_YELLOW);
		mod->wave->l_mesh = NULL;
		mod->wave->s_mesh = NULL;
		mod->wave->g_mesh = NULL;
	}
	if (!mod->wave->l_mesh)
	{
		printf("init wave->l_mesh\n");
		if (!(mod->wave->l_mesh = (t_vertx*)malloc(sizeof(t_vertx) * (mod->scale * mod->scale + 1))))
			error(NUL, "dynamic_wave.c", "mod->wave->l_mesh", TXT_YELLOW);
		mod->wave->l_mesh[mod->scale * mod->scale].end = 1;
	}
	if (!mod->bol)
	{
		init_wave_meshes(mod);
		mod->bol = 1;
	}
	else
		set_wave_meshes(mod);
	init_wave_bases(mod);	
}
