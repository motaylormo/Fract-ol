# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 19:57:40 by mtaylor           #+#    #+#              #
#    Updated: 2019/02/23 15:06:56 by mtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes/

BASIC_SET = ft_memalloc.c ft_memdel.c \
			ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_strnew.c ft_strdel.c \
			ft_strclr.c \
			ft_strlen.c \
			ft_strdup.c ft_strjoin.c \
			ft_strcpy.c ft_strncpy.c \
			ft_strcat.c ft_strncat.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c \
			ft_strstr.c ft_strnstr.c \
			ft_strcmp.c ft_strncmp.c \
			ft_strequ.c ft_strnequ.c \
			ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
			ft_strsub.c \
			ft_strtrim.c ft_strsplit.c \
			ft_atoi.c ft_itoa.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c \
			ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
EXTRAS_SET = ft_atoibase.c ft_itoabase.c \
			 ft_strchrindex.c \
			 get_next_line.c \
			 ft_dtoa.c
CFILES = $(BASIC_SET) $(EXTRAS_SET)
OFILES = $(CFILES:.c=.o)


all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(CFILES) $(INCLUDES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
