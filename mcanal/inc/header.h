/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/23 18:31:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/

# define HEADER_H
# define WIN_SIZE 800
# define MAX_SIZE 20000
# define RED 25
# define DEBUG { ft_putstr_clr(__func__, "r"); ft_putstr_clr(" (", "r"); ft_putstr_clr(__FILE__, "red"); ft_putstr_clr(") - line: ", "r"); ft_putnbr_clr(__LINE__, "r"); ft_putendl(""); } //debug

/*
** include
*/
# include "../libft/inc/libft.h"
# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/*
** struct def
*/

typedef struct s_env	t_env;
struct	s_env
{
	void	*mlx;
	void	*win;
	t_list	*alst;
};

/*
** prototypes
*/

t_list		*read_file(char *file);
int			key_hook(int key, t_env *e);
int			mouse_hook(int button, int x, int y, t_env *e);
int			expose_hook(t_env *e);
void		draw_line(t_lst *a, t_lst *b, t_env *e);
void		draw(t_env *e);
void		print_list(t_list *alst); //debug

#endif
