# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 23:42:45 by bmbarga           #+#    #+#              #
#    Updated: 2015/04/25 12:52:14 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GWC = gcc -Wall -Wextra -Werror

NAME = libft.a

SRCS =	ft_isprint.c	ft_isalnum.c	ft_isdigit.c	ft_isalpha.c  \
		ft_islower.c	ft_isupper.c	ft_isascii.c	ft_toupper.c  \
		ft_tolower.c	ft_atoi.c		ft_memcmp.c		ft_memchr.c   \
		ft_strlen.c		ft_strcpy.c		ft_strncpy.c	ft_strncat.c  \
		ft_strcat.c		ft_strlcat.c	ft_strchr.c		ft_strrchr.c  \
		ft_strstr.c		ft_strnstr.c	ft_strcmp.c		ft_strncmp.c  \
		ft_strdup.c		ft_putchar.c	ft_putstr.c		ft_putchar_fd.c \
		ft_putstr_fd.c	ft_putendl.c	ft_putendl_fd.c	ft_putnbr.c   \
		ft_putnbr_fd.c	ft_memalloc.c	ft_memdel.c		ft_strnew.c   \
		ft_strdel.c		ft_strclr.c		ft_striter.c	ft_striteri.c \
		ft_strmap.c		ft_strmapi.c	ft_strequ.c		ft_strnequ.c  \
		ft_strsub.c		ft_strjoin.c	ft_strtrim.c	ft_memcpy.c   \
		ft_memccpy.c	ft_memmove.c	ft_memset.c		ft_bzero.c    \
		ft_itoa.c		ft_strsplit.c	ft_lstlast.c	ft_lstdel.c	  \
		ft_lstiter.c ft_lstadd.c ft_lstaddlast.c ft_lstlen.c ft_lstat.c \
		ft_lstisempty.c ft_lstislast.c ft_ladd.c ft_laddlast.c ft_lat.c \
		ft_ldellink.c ft_lfirst.c\
		ft_lisfirst.c ft_linser.c ft_lisempty.c ft_lclean.c\
		ft_lislast.c ft_lisn.c ft_liter.c ft_llast.c ft_llen.c ft_lrplc.c\
		ft_lswap.c ft_lstinser.c ft_lstrplc.c ft_lstisn.c ft_lstdellink.c\
		ft_lstnew.c	ft_lstmap.c	ft_lstdelone.c ft_lstfind.c\
		ft_lnew.c	ft_lfree.c 	ft_lfind.c ft_realloc.c \
		ft_debugstr.c ft_debugnbr.c \
		ft_putstr_clr.c		ft_putchar_clr.c	ft_putendl_clr.c	\
		ft_isspace.c	ft_putnbr_clr.c		ft_putcol.c \



OBJ = $(SRCS:.c=.o)

INCLUDES = -I ../includes

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRCS) 
	$(GWC) -c $(INCLUDES) $(SRCS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
