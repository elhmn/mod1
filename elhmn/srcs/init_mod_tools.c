/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mod_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 15:32:21 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/06 16:58:27 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

void			set_base(t_mod *mod, t_base *base, int o_x, int o_y)
{
	if (!mod)
		error(NUL, "init_mod_tools.c", "mod", TXT_YELLOW);
	base->o.pos.x = o_x;
	base->o.pos.y = o_y;
	base->i.pos.x = o_x + UNIT;
	base->i.pos.y = o_y;
	base->j.pos.x = o_x;
	base->j.pos.y = o_y - UNIT / 2;
	base->k.pos.x = o_x + 10;
	base->k.pos.y = o_y + UNIT - UNIT / 4;
}

void		init_base(t_mod *mod, t_base *base)
{
	if (!mod)
		error(NUL, "init_mod_tools.c", "mod", TXT_YELLOW);
	if (base)
	{
		base->o.pt.x = 0;
		base->o.pt.y = 0;
		base->o.pt.z = 0;
		base->i.pt.x = 1;
		base->i.pt.y = 0;
		base->i.pt.z = 0;
		base->j.pt.x = 0;
		base->j.pt.y = 1;
		base->j.pt.z = 0;
		base->k.pt.x = 0;
		base->k.pt.y = 0;
		base->k.pt.z = 1;
		set_base(mod, base, O_X, O_Y);
	}
}
