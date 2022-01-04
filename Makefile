# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abayar <abayar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 17:19:00 by abayar            #+#    #+#              #
#    Updated: 2021/12/23 16:13:12 by abayar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c get_next_line.c get_next_line_utils.c so_long_utils.c

OBJ = ${SRC:.c=.o}

SIZE = -D BUFFER_SIZE=20

NAME = so_long.a

FLAGS = gcc -Wall -Wextra -Werror

all		: ${NAME}

${NAME}	: ${OBJ}

%.o 	: %.c
	${FLAGS} -c $< -o $@ ${SIZE}
	ar rc ${NAME} $@

exec	:
	gcc so_long.c so_long.a -lmlx -framework OpenGL -framework AppKit
	./a.out
	rm a.out

clean 	:
	rm -f ${OBJ}
	
fclean	: clean
	rm -f ${NAME}

re		: fclean  all