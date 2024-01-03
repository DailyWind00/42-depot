# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:32:34 by mgallais          #+#    #+#              #
#    Updated: 2024/01/03 10:38:41 by mgallais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -Iinclude -g
MLXFLAGS = ./MLX42/libmlx42.a -I./MLX42/include -ldl -lglfw -pthread -lm
LDFLAGS = -Llib -lftprintf
CC = cc

SRC = $(wildcard *.c) $(wildcard checking/*.c)
OBJ = $(SRC:.c=.o)

%.o:		%.c
			$(CC) $(CFLAGS) -I./MLX42/include -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(MLXFLAGS) $(LDFLAGS)

all:		$(NAME)

clean:
			$(RM) -f $(OBJ)

fclean:		clean
			$(RM) -f $(NAME)

re:			fclean all

test:
			@make re
			@make clean
			@clear
#			@sh ~/better_norminette.sh
#			@sleep 2
#			@clear
			@echo "\033[1;92mDONE !"

.PHONY: all clean fclean re

