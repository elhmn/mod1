/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 03:39:14 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/23 18:35:46 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDIT_H

# define EDIT_H

/*
** lst1 struct
*/
typedef struct s_list	t_list;
struct	s_list
{
	int		x;
	int		y;
	int		z;
	t_list	*next;
};

/*
** lst2 struct
*/
typedef struct s_lst	t_lst;
struct	s_lst
{
	int		x;
	int		y;
	int		z;
	int		x_pix;
	int		y_pix;
	t_lst	*next;
	t_lst	*prev;
};

/*
** lst1
*/
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list	*ft_lstfind(t_list **alst, int z);
t_list	*ft_lstnew(int x, int y, int z);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** lst2
*/
t_lst	*ft_lnew(int x, int y, int z);
t_lst	*ft_lfind(t_lst **alst, int z);
void	ft_lfree(t_lst **lst);

#endif
