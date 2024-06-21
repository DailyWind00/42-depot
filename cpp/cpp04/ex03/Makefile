##------------------------------------##
NAME = AMateria

HEADERS =	AMateria.hpp \
			Character.hpp \
			Cure.hpp \
			Ice.hpp \
			Fire.hpp \
			MateriaSource.hpp \
			ICharacter.hpp \
			IMateriaSource.hpp #
SRCS =	AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		Fire.cpp \
		MateriaSource.cpp \
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
