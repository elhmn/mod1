/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 04:58:45 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/13 20:41:24 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retourne l’adresse du premier élément dont la donnée est
** "égale" à la donnée de référence
*/

#include "libft.h"

t_lst *ft_lfind(t_lst **alst, int z)
{
	t_lst	*tmp;

	if (!alst || !z)
		return (NULL);
	tmp = *alst;
	while (tmp)
	{
		if (z == tmp->z)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
