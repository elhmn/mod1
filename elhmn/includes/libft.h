/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:46:18 by bmbarga           #+#    #+#             */
/*   Updated: 2015/06/06 19:10:11 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 8
# define MAX_NBR 2147483647
# define MIN_NBR -2147483648
# include <string.h>

# define CAR_CLR() printf("\033[H\033[2J")

# define TXT_BLACK		"30"
# define TXT_RED		"31"
# define TXT_GREEN		"32"
# define TXT_YELLOW		"33" 
# define TXT_BLUE		"34"
# define TXT_MAGENTA	"35"
# define TXT_CYAN		"36"
# define TXT_WHITE		"37" 
# define COL_RESET		"0"

# define BG_BLACK		"40"
# define BG_RED			"41"
# define BG_GREEN		"42"
# define BG_YELLOW		"43" 
# define BG_BLUE		"44" 
# define BG_MAGENTA		"45"
# define BG_CYAN		"46"
# define BG_WHITE		"47" 

int		ft_putcol(char *color, char *str);
int		ft_putcol_endl(char *color, char *str);

/*
 Efface l'écran et replace le curseur en haut à gauche
 #define clrscr() printf("\033[H\033[2J")

  Sélection de couleurs
 #define couleur(param) printf("\033[%sm",param)
  param devant être un const char *, vide (identique à "0") ou formé
  d'une où plusieurs valeurs séparées par des ; parmi
  0  réinitialisation         1  haute intensité (des caractères)
  5  clignotement             7  video inversé
  30, 31, 32, 33, 34, 35, 36, 37 couleur des caractères
  40, 41, 42, 43, 44, 45, 46, 47 couleur du fond
  les couleurs, suivant la logique RGB, étant respectivement
  noir, rouge, vert, jaune, bleu, magenta, cyan et blanc
*/

/*
** lst1 struct
*/

/*
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
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
** mcanal
*/

void	*fail(char *s);
void	*failn(char *s);
void	ft_debugstr(char *name, char *str);
void	ft_debugnbr(char *name, int nbr);
void	ft_putnbr_clr(int nbr, char *clr);
void	ft_putstr_clr(char const *s, char *clr);
void	ft_putendl_clr(char const *s, char *clr);
void	ft_putchar_clr(char c, char *clr);
void	*ft_realloc(void *old, size_t old_size, size_t new_size);

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
** First Part
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);

/*
** Second part
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_memprint(void *ptr, size_t size);
void				*my_memalloc(size_t size);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
int					ft_isspace(int c);

/*
** Part bonus
*/

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list	*ft_lstfind(t_list **alst, int z);
t_list	*ft_lstnew(int x, int y, int z);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

//t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del) (void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del) (void*, size_t));
void				ft_lstiter(t_list *lst, void (*f) (t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_end(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
t_lst	*ft_lnew(int x, int y, int z);
t_lst	*ft_lfind(t_lst **alst, int z);
void	ft_lfree(t_lst **lst);

/*
** lst1
*/
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstaddlast(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdellink(t_list **alst, t_list *lst);
void	ft_lstinser(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void	ft_lstrplc(t_list **alst, t_list *old, t_list *new);
int		ft_lstisempty(t_list **alst);
int		ft_lstislast(t_list **alst);
int		ft_lstisn(t_list **alst, t_list *lst);
int		ft_lstlen(t_list **alst);
t_list	*ft_lstlast(t_list **alst);
t_list	*ft_lstat(t_list **alst, size_t n);

/*
** lst2
*/
void	ft_ladd(t_lst **alst, t_lst *new);
void	ft_laddlast(t_lst **alst, t_lst *new);
void	ft_ldellink(t_lst *lst);
void	ft_linser(t_lst **alst, t_lst *new);
void	ft_liter(t_lst *lst, void (*f)(t_lst *elem));
void	ft_lrplc(t_lst *old, t_lst *new);
void	ft_lswap(t_lst *lst1, t_lst *lst2);
int		ft_lisempty(t_lst **alst);
int		ft_lisfirst(t_lst **alst);
int		ft_lislast(t_lst **alst);
int		ft_lisn(t_lst **alst, t_lst *lst);
int		ft_llen(t_lst **alst);
t_lst	*ft_lat(t_lst **alst, size_t n);
t_lst	*ft_lfirst(t_lst **alst);
t_lst	*ft_llast(t_lst **alst);
void	ft_lclean(t_lst **alst);

#endif
