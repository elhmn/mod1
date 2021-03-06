/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 03:02:52 by bmbarga           #+#    #+#             */
/*   Updated: 2014/04/20 16:50:46 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f) (char *))
{
	char	*tmp;

	tmp = s;
	while (s && *tmp && f)
	{
		f(tmp);
		tmp++;
	}
}
