##------------------------------------##
NAME = Serializer

HEADERS =	Serializer.hpp \
			Data.hpp #
SRCS =	Serializer.cpp \
		Data.cpp \
		main.cpp #
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
##------------------------------------##

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -I "$(HEADERS)"

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@ -I "$(HEADERS)"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
