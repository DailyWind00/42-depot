# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 15:13:20 by mgallais          #+#    #+#              #
#    Updated: 2023/11/04 16:17:29 by mgallais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = ./src/

SRC = 

OBJS = ${SRC:.c=.o}

CC        = gcc
RM        = rm -f

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o: $(SRC_PATH)%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I includes

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
