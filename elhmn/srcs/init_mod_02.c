/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mod_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 20:12:23 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/08 18:35:04 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "check_errors.h"

void	init_map(float **map, t_mod *mod)
{
	int		i;
	int		j;

	j = -1;
	ft_putcol_endl(TXT_YELLOW, "je suis init_map()"); /*_DEBUG_*/
	if (!mod)
		error(NUL, "init_mod.c", "mod", TXT_YELLOW);
	if (!map || !*map)
		error(NUL, "init_mod.c", "map", TXT_YELLOW);
	while (++j < mod->scale)
	{
		i = -1;
		while (++i < mod->scale)
			map[i][j] = 0.;
	}
}

void	set_map(t_mod *mod)
{
	int		i;

	i = 0;
	if (!mod)
		error(NUL, "init_mod.c", "mod", TXT_YELLOW);
	if (!(mod->map = (float**)malloc(sizeof(float*) * ((int)mod->scale))))
		error(MALLOC, "init_mod.c", "mod->map", TXT_YELLOW);
	mod->map[(int)mod->scale] = NULL;
	while (i < (int)mod->scale)
	{
		if (!(mod->map[i] = (float*)malloc(sizeof(float) * (int)mod->scale)))
			error(MALLOC, "init_mod.c", "mod->map[i]", TXT_YELLOW);
		i++;
	}
}

float	**init_imgtab(void)
{
	float	**tab;
	int		i;
	int		j;

	i = -1;
	tab = NULL;
	if (!(tab = (float**)malloc(sizeof(float*) * (S_HEIGH))))
		error(MALLOC, "init_mod.c", "tab", TXT_YELLOW);
	while (++i < S_HEIGH)
	{
		if (!(tab[i] = (float*)malloc(sizeof(float) * S_WIDTH)))
			error(MALLOC, "init_mod.c", "tab[i]", TXT_YELLOW);
	}
	i = -1;
	while (++i < S_HEIGH)
	{
		j = -1;
		while (j++ < S_WIDTH)
			tab[i][j] = 0.;
	}
	return (tab);
}

int		tops_len(t_mod *mod)
{
	int		len;
	t_list	*ls;

	len = 0;
	if (!(ls = mod->tops))
		error(NUL, "mod->tops", "init_mod.c", TXT_YELLOW);
	while (ls)
	{
		len++;
		ls = ls->next;
	}
	return (len);
}

t_top	*tops(t_mod *mod)
{
	t_top		*tops;
	t_list		*ls;
	int			i;

	i = 0;
	if (!(ls = mod->tops))
		error(NUL, "mod->tops", "init_mod.c", TXT_YELLOW);
	tops = (t_top*)malloc(sizeof(t_top) * (tops_len(mod) + 1));
	if (!tops)
		error(MALLOC, "tops", "init_mod.c", TXT_YELLOW);
	while (ls)
	{
		tops[i].vertx.x = (float)ls->x;
		tops[i].vertx.y = (float)ls->y;
		tops[i].vertx.z = -5555555.;
		tops[i].vertx.end = 0;
		tops[i].ring = NULL;
		ls = ls->next;
		i++;
	}
	tops[i].vertx.end = 1;
	return (tops);
}
