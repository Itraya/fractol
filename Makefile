# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrang <mlagrang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 10:23:26 by mlagrang          #+#    #+#              #
#    Updated: 2022/01/31 11:33:29 by mlagrang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c srcs/mandelbrot.c srcs/julia.c srcs/burning_ship.c srcs/color.c srcs/draw.c srcs/init.c srcs/command.c srcs/ft_itoa.c

HEADERS	= ft_fractol.h

OBJS	= ${SRCS:.c=.o}

NAME	= fractol

CC		= gcc

FLAGS	= -Wall -Wextra -Werror -Ofast

CFLAGS	= -framework OpenGL -framework AppKit -g -lmlx -Lmlx

%.o:	%.c ${HEADERS} Makefile
		${CC} ${FLAGS} -c $< -o $@

all:	mlx ${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${FLAGS} ${OBJS} -o ${NAME}

mlx:
		@make -C ./mlx/

m:		re
		./${NAME} mandelbrot

j:		re
		./${NAME} julia

b:		re
		./${NAME} burning_ship

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}
		@make -C ./mlx/ clean

re:		fclean all

.PHONY:	all clean fclean re bonus m j b ex mlx