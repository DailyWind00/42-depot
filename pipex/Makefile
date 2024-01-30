# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:32:34 by mgallais          #+#    #+#              #
#    Updated: 2024/01/29 14:58:27 by mgallais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror -Iinclude -g
LDFLAGS = -Llib -lftprintf
CC = cc

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC)  $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			cd lib; make
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

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
			@sh ~/better_norminette.sh

.PHONY: all clean fclean re test norminette

