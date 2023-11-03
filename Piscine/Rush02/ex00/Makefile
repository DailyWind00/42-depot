SRC_PATH = ./src/*
INCLUDES_PATH = ./includes/*
SRC = $(SRC_PATH)$(wildcard *.c)
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes
NAME = rush-02
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES_PATH) -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean all
