/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 17:02:22 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/07 16:47:26 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

void	init_l_base(t_base *l_base)
{
	if (!l_base)
		error(NUL, "init_scene.c", "l_base", TXT_YELLOW);
	l_base->i.x = 1.;
	l_base->i.y = 0.;
	l_base->i.z = 0.;
	l_base->i.end = 0;
	l_base->i.col = NULL;
	l_base->j.x = 0.;
	l_base->j.y = 1.;
	l_base->j.z = 0.;
	l_base->j.end = 0;
	l_base->j.col = NULL;
	l_base->k.x = 0.;
	l_base->k.y = 0.;
	l_base->k.z = 1.;
	l_base->k.end = 0;
	l_base->k.col = NULL;
}

void	init_g_base(t_base *g_base)
{
	if (!g_base)
		error(NUL, "init_scene.c", "g_base", TXT_YELLOW);
	g_base->i.x = 1.;
	g_base->i.y = 0.;
	g_base->i.z = 0.;
	g_base->i.end = 0;
	g_base->i.col = NULL;
	g_base->j.x = 0.;
	g_base->j.y = 1.;
	g_base->j.z = 0.;
	g_base->j.end = 0;
	g_base->j.col = NULL;
	g_base->k.x = 0.;
	g_base->k.y = 0.;
	g_base->k.z = 1.;
	g_base->k.end = 0;
	g_base->k.col = NULL;
}

void	init_centers(t_base *l_base, t_base *g_base)
{
	if (!l_base || !g_base)
		error(NUL, "init_scene.c", "bases", TXT_YELLOW);
	l_base->o.x = 0.;
	l_base->o.y = 0.;
	l_base->o.z = 0.;
	l_base->o.end = 0;
	l_base->o.col = NULL;
	g_base->o.x = 0.;
	g_base->o.y = 0.;
	g_base->o.z = 0.;
	g_base->o.end = 0;
	g_base->o.col = NULL;
}

void		init_scene(t_mod *mod)
{
	ft_putcol(TXT_YELLOW, "i am init_scene\n");
	init_centers(&(mod->glob.l_base), &(mod->glob.g_base));
	init_g_base((&(mod->glob.g_base)));
	init_l_base((&(mod->glob.l_base)));
}
