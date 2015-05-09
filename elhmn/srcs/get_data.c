/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:39:52 by bmbarga           #+#    #+#             */
/*   Updated: 2015/04/24 18:20:19 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "header.h"
#include "check_errors.h"
#include <stdlib.h>

void	get_data(t_mod *mod, char *file)
{
	if (!(mod->tops = read_file(file)))
		check_errors(NUL, "get_data.c", "mod->tops");
	print_list(mod->tops);/*_DEBUG_*/
	ft_putendl("je suis get_data.c");/*_DEBUG_*/
}
