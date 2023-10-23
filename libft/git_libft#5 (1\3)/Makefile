# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 16:37:38 by mgallais          #+#    #+#              #
#    Updated: 2023/10/18 16:58:44 by mgallais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAG = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AR = ar rc
RLIB = ranlib
HDR = -I libft.h
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RLIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
