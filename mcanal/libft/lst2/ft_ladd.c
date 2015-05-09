/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ladd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 02:27:33 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/28 12:56:33 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ajoute l’élément new en tête de la liste. **alst pointe vers le premier
** élément de la liste. La fonction assume que liste possède au moins un
** élément.
*/

#include "libft.h"

void ft_ladd(t_lst **alst, t_lst *new)
{
	if (!new || !alst)
		return ;
	new->next = *alst;
	(*alst)->prev = new;
	new->prev = NULL;
	*alst = new;
}
