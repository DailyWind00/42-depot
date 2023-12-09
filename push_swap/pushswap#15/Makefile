NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -Iinclude -g
LDFLAGS = -Llib -lftprintf

SRC = $(wildcard *.c) $(wildcard */*.c)
OBJ = $(SRC:.c=.o)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

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
