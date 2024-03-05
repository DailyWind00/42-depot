# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:32:34 by mgallais          #+#    #+#              #
#    Updated: 2024/03/05 16:41:46 by mgallais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror -I./include -g -pthread #-fsanitize=thread
CC = cc

SRC = $(wildcard ./src/*.c)
OBJ = $(SRC:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC)  $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			$(RM) -f $(OBJ)

fclean:		clean
			$(RM) -f $(NAME)

re:			fclean all

test:
			@make re
			@make clean
			@clear
			@echo "\033[1;92mDONE !"

norminette:
			@clear
			@sh ~/better_norminette.sh

.PHONY: all clean fclean re

