/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 09:01:00 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/24 11:13:57 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** printing list to stdout... mostly for debugging purpose
*/

#include "mod1.h"
#include "header.h"

void	print_list(t_list *alst)
{
	t_list	*tmp;
	int		i;

	tmp = alst;
	i = 1;
	while (tmp)
	{
		ft_debugnbr("link", i);
		ft_debugnbr("x", tmp->x);
		ft_debugnbr("y", tmp->y);
		ft_debugnbr("z", tmp->z);
		ft_putendl("");
		tmp = tmp->next;
		i++;
	}
}
