# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 10:23:26 by mlagrang          #+#    #+#              #
#    Updated: 2022/01/03 14:24:37 by mlagrang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c srcs/mandelbrot.c srcs/julia.c srcs/burning_ship.c srcs/color.c srcs/draw.c srcs/init.c srcs/command.c srcs/ft_itoa.c

HEADERS	= ft_fractol.h

OBJS	= ${SRCS:.c=.o}

NAME	= fractol

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

CFLAGS	= -Ofast -framework OpenGL -framework AppKit -g -lmlx -Lmlx

all:
		gcc ${CFLAGS} ${FLAGS} ${SRCS} -o ${NAME}

ex:		re
		./${NAME}

m:		re
		./${NAME} mandelbrot

j:		re
		./${NAME} julia

b:		re
		./${NAME} burning_ship

l:
		gcc -fsanitize=address ${CFLAGS} ${SRCS} -o ${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re bonus l m j b ex