# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/21 17:36:17 by bmbarga           #+#    #+#              #
#    Updated: 2015/06/11 19:33:48 by bmbarga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mod1

SRC =	main.c get_data.c data_error.c init_mod.c map_builder.c real_time.c \
		destroy_mod.c get_all.c check_errors.c fun_err_01.c read.c \
		print.c fail.c failn.c event_handle_01.c debug_01.c \
		draw.c color.c print_map.c print_scene.c \
		set_obj.c base_oper_01.c base_oper_02.c \
		init_rain_tools.c dynamic_wave.c \
		init_wave_tools.c init_mod_02.c \
		real_wave.c real_rain.c real_up.c real_void.c\
		init_lm.c set_gbase.c draw_obj.c real_up_tools.c\
		set_lm.c

OBJ = $(SRC:.c=.o)

OBJDIR = ./objs/

SRCDIR = ./srcs/

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJS = $(addprefix $(OBJDIR), $(OBJ))

INCHOME = -I ./includes/ -I /usr/include/X11

INC = -I ./includes/

LIB42 = -L ./

LIBHOME = -L /usr/lib64/X11

LIBFT = -L ./libft/

LIBS = -lft -lX11 -lXext -lmlx -lm

LIBMAC = -lft -lm  -framework OpenGL -framework Appkit -lmlx

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	$(CC) $(FLAGS) $(LIBFT) $(LIB42) -o $(NAME) $(OBJS) $(LIBMAC)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -g $(INC) -c $(SRCS)
	mv $(OBJ) $(OBJDIR)

home: obj
	make -C ./libft/
	$(CC) $(FLAGS) $(LIBFT) $(LIBHOME) -o $(NAME) $(OBJS) $(LIBS)

obj: $(SRCS)
	$(CC) $(FLAGS) -g $(INCHOME) -c $(SRCS)
	mv $(OBJ) $(OBJDIR)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJ)
	make clean -C ./libft/

fclean: clean
	make fclean -C ./libft/
	rm $(NAME)

re:  fclean all
