/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_up_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 17:16:25 by bmbarga           #+#    #+#             */
/*   Updated: 2015/07/03 11:30:36 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"
#include <stdio.h>/*_DEBUG_*/
#include "debug.h"/*_DEBUG_*/

static void	new_trans(t_obj  ***trans)
{
	if (!(*trans = (t_obj**)malloc(sizeof(t_obj*) * TRANS_NBR)))
		error(MALLOC, "trans", "real_up_tools.c", TXT_YELLOW);
}

void	init_trans(t_mod *mod, t_initlm initlm)
{
	int		i;

	i = -1;
	if (!mod)
		error(NUL, "mod", "real_up_tools.c", TXT_YELLOW);
	if (!mod->trans)
		new_trans(&(mod->trans));
	if (!mod->trans)
		error(NUL, "mod->trans", "real_up_tools.c", TXT_YELLOW);
	mod->ind_lvl = 0;
	while (++i < TRANS_NBR)
	{
		mod->trans[i] = NULL;
		mod->h = i;
		init_obj(mod, (t_obj**)(mod->trans + i), initlm, NULL);
		set_gbase_trans(mod, mod->trans[i]);
		mod->ind_lvl++;
	}
}
