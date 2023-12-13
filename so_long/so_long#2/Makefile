# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:32:34 by mgallais          #+#    #+#              #
#    Updated: 2023/12/12 14:40:57 by mgallais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -Iinclude -g
MLXFLAGS = ./MLX42/libmlx42.a -I./MLX42/include -ldl -lglfw -pthread -lm
CC = cc

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

%.o:		%.c
			$(CC) -I./MLX42/include -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(MLXFLAGS)

all:		$(NAME)

clean:
			$(RM) -f $(OBJ)

fclean:		clean
			$(RM) -f $(NAME)

re:			fclean all

test:
			make re
			make clean
			clear
#			sh ~/better_norminette.sh
#			sleep 2
#			clear
			echo "\033[1;92mDONE !"

.PHONY: all clean fclean re

