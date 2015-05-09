/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 05:25:28 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/13 08:36:59 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retourne l’adresse du premier élément dont la donnée est
** "égale" à la donnée de référence
*/

#include "libft.h"

t_list *ft_lstfind(t_list **alst, int z)
{
	t_list	*tmp;

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
