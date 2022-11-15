# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 19:22:01 by badriah           #+#    #+#              #
#    Updated: 2022/02/22 20:59:14 by balnahdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c check.c create.c helper.c revrot.c rot.c swpsh.c algo3.c \
		sorting.c algo5.c algo_identifier.c algo100.c calmov100.c calmov500.c \
		algo500.c free.c\

OBJ = ${SRC:.c=.o}

CC	= gcc
RM	= rm -f

CFLAG =  -Wall -Werror -Wextra

all: 
	${MAKE} -C ./libft
	cp ./libft/libft.a ./libft.a 
	${CC} ${CFLAG} ${SRC} libft.a -o push_swap

clean: 
	${MAKE} clean -C ./libft
	${RM} ${OBJ}

fclean: clean
	${RM} push_swap ./libft.a ./libft/libft.a 

re: fclean all
