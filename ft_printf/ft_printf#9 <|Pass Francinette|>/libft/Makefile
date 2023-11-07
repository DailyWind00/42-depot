# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 16:37:38 by mgallais          #+#    #+#              #
#    Updated: 2023/10/26 15:41:44 by mgallais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC 		  = ft_isalpha.c\
                ft_isdigit.c\
                ft_isalnum.c\
                ft_isascii.c\
                ft_isprint.c\
                ft_toupper.c\
                ft_tolower.c\
                ft_bzero.c\
                ft_memset.c\
                ft_memcpy.c\
                ft_memmove.c\
                ft_memchr.c\
                ft_memcmp.c\
                ft_strlen.c\
                ft_strlcpy.c\
                ft_strlcat.c\
                ft_strchr.c\
                ft_strrchr.c\
                ft_strncmp.c\
                ft_strnstr.c\
                ft_atoi.c\
                ft_calloc.c\
                ft_strdup.c\
                ft_substr.c\
                ft_strjoin.c\
                ft_strtrim.c\
                ft_split.c\
                ft_itoa.c\
                ft_strmapi.c\
                ft_striteri.c\
                ft_putchar_fd.c\
                ft_putendl_fd.c\
                ft_putnbr_fd.c\
                ft_putstr_fd.c\

BONUS = ft_lstnew.c\
        ft_lstadd_front.c\
        ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\

OBJS = ${SRC:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC        = gcc
RM        = rm -f

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus:    ${OBJS} ${OBJSBONUS}
	ar rcs ${NAME} ${OBJS} ${OBJSBONUS}

clean:
	${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all
