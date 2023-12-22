# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:32:34 by mgallais          #+#    #+#              #
#    Updated: 2023/12/22 14:08:29 by mgallais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client

CFLAGS = -Wall -Wextra -Werror -Iinclude -g
LDFLAGS = -Llib -lftprintf
CC = cc

SERVER_SRC = serveur.c\
			 serveur_utils.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)


all: $(SERVER_NAME) $(CLIENT_NAME)

%.o:		%.c
			$(CC) -c $< -o $@

$(SERVER_NAME):	$(SERVER_OBJ)
			$(CC) -o $(SERVER_NAME) $(SERVER_OBJ) $(CFLAGS) $(LDFLAGS)

$(CLIENT_NAME):	$(CLIENT_OBJ)
			$(CC) -o $(CLIENT_NAME) $(CLIENT_OBJ) $(CFLAGS) $(LDFLAGS)

clean:
			$(RM) -f $(SERVER_OBJ)
			$(RM) -f $(CLIENT_OBJ)

fclean:		clean
			$(RM) -f $(SERVER_NAME)
			$(RM) -f $(CLIENT_NAME)

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

