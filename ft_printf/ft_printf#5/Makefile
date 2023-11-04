# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 15:13:20 by mgallais          #+#    #+#              #
#    Updated: 2023/11/04 18:54:40 by mgallais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

SRC = src/ft_printf.c \
      src/char.c \
      src/str.c \
      src/vptr.c \
      src/dec.c \
      src/hex.c \
      src/unbr.c \
      src/inbr.c

OBJS = ${SRC:.c=.o}

CC = cc
LD = ld
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I./include
LIBS = libft.a
LIBRARIES = -lft -lc -lm

all: ${NAME}

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}
	$(LD) -o ${NAME} ${OBJS} -L. $(LIBRARIES)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
