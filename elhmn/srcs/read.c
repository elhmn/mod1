/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 08:12:25 by mcanal            #+#    #+#             */
/*   Updated: 2015/06/13 20:57:40 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** read the *.mod1 map and fill a linked list with its content
*/

#include "mod1.h"
#include "header.h"
#include "check_errors.h"
#include <unistd.h>

static int		check_map(char *map, char *file)
{
	(void)file;
	if (!map)
		error(NUL, "map", "read.c", TXT_YELLOW);
	while (*map)
	{
		if (*map != '(' && *map != ')' && *map != ','\
			&& !ft_isdigit(*map) && !ft_isspace(*map))
			return (0);
		map++;
	}
	return (1);
}

static void		fill_list(char *map, t_list **alst)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (*map)
	{
		while (*(map - 1) != '(' && *map)
			map++;
		x = (int)(ft_atoi(map));
		while (*(map - 1) != ',' && *map)
			map++;
		y = (int)(ft_atoi(map++));
		while (*(map - 1) != ',' && *map)
			map++;
		ft_lstadd(alst, ft_lstnew(x, y, (int)(ft_atoi(map))));
		while (*map != '(' && *map)
			map++;
	}
}

t_list			*read_file(char *file)
{
	int		file_fd;
	char	*map;
	t_list	*alst;

	map = NULL;
	alst = NULL;
	if ((file_fd = open(file, O_RDONLY)) < 0)
		return (failn("Map not found."));
	if (!get_all(file_fd, &map))
		return (failn("Reading map failed."));
	if (!check_map(map, file))
		return (failn("Invalid map."));
	fill_list(map + 1, &alst);
	ft_memdel((void*)&map);
	close(file_fd);
	return (alst);
}
