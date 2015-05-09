/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 08:12:25 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 01:57:36 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** read the *.mod1 map and fill a linked list with its content
*/

#include "header.h"

static char		check_map(char *map, char *file) //TODO
{
//	if (!file || ft_strstr(file, ".mod1"))
//		return (0);
	file = file;
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

	*alst = NULL;
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

	if ((file_fd = open(file, O_RDONLY)) < 0)
		return (failn("Map not found."));
	if (!get_all(file_fd, &map))
		return (failn("Reading map failed."));
	if (!check_map(map, file))
		return (failn("Invalid map."));
	fill_list(map + 1, &alst);
	ft_debugstr("map", map); //debug
	print_list(alst);	//debug
	ft_memdel((void *)&map);
	close(file_fd);
	return (alst);
}
