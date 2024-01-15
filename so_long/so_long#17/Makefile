# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:32:34 by mgallais          #+#    #+#              #
#    Updated: 2024/01/15 11:46:00 by mgallais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -Iinclude -g
MLXFLAGS = ./MLX42/libmlx42.a -I./MLX42/include -ldl -lglfw -pthread -lm
LDFLAGS = -Llib -lftprintf
CC = cc

SRC = $(wildcard *.c) $(wildcard checking/*.c) $(wildcard game/*.c)
OBJ = $(SRC:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC)  $(CFLAGS) -I./MLX42/include -c $< -o $@

$(NAME):	$(OBJ)
			cd lib; make
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(MLXFLAGS) $(LDFLAGS)

clean:
			cd lib; make clean
			$(RM) -f $(OBJ)

fclean:		clean
			cd lib; make fclean
			$(RM) -f $(NAME)

re:			fclean all

test:
			@make re
			@make clean
			@clear
			@echo "\033[1;92mDONE !"

norminette:
			@clear
#			@sh ~/better_norminette.sh
			@norminette -R CheckDefine include
			@norminette -R CheckForbiddenSourceHeader main.c
			@norminette -R CheckForbiddenSourceHeader checking
			@norminette -R CheckForbiddenSourceHeader game
			@norminette -R CheckForbiddenSourceHeader lib

.PHONY: all clean fclean re

