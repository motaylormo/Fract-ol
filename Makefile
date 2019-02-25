# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 13:41:05 by mtaylor           #+#    #+#              #
#    Updated: 2019/02/23 22:18:29 by mtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror

## Libraries
LIBFT = ./libft/libft.a
LIBMLX = ./miniLibX/libmlx.a -framework OpenGL -framework AppKit
LIB = -I libft/ -I miniLibX/ $(LIBFT) $(LIBMLX)

SRCS = main.c \
	   graphics_structs.c \
	   math.c \
	   actions.c \
	   calc_screen.c threads.c display.c

INC = -I ./inc/

all : $(NAME)

$(NAME) :
	make -s -C ./libft
	make -s -C ./miniLibX
	gcc $(FLAGS) $(LIB) $(addprefix ./src/, $(SRCS)) $(INC) -o $(NAME)

clean :
	make -s -C ./libft clean
	make -s -C ./miniLibX clean

fclean : clean
	make -s -C ./libft fclean
	rm -f $(NAME)

re : fclean all
