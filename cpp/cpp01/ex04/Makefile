##------------------------------------##
NAME = 	Sed_is_for_losers

SRCS =	main.cpp #
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
##------------------------------------##

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(wildcard tests/*.replace)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
