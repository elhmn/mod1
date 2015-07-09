/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:39:52 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/06 21:09:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"
#include "header.h"
#include "check_errors.h"
#include <stdlib.h>

void	get_data(t_mod *mod, char *file)
{
	ft_putcol_endl(TXT_GREEN, "je suis get_data.c");/*_DEBUG_*/
	if (!(mod->tops = read_file(file)))
		error(NUL, "get_data.c", "mod->tops", TXT_YELLOW);
}
