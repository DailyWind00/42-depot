NAME      := libftprintf.a
CFLAGS     := -Wall -Wextra -Werror

SRC      := ft_isalpha.c \
			 ft_isalnum.c \
			 ft_isdigit.c \
			 ft_isascii.c \
			 ft_isprint.c \
			 ft_strlen.c \
			 ft_memset.c \
			 ft_bzero.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_strlcpy.c \
			 ft_strlcat.c \
			 ft_toupper.c \
			 ft_tolower.c \
			 ft_strchr.c \
			 ft_strrchr.c \
			 ft_strncmp.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_strnstr.c \
			 ft_atoi.c \
			 ft_calloc.c \
			 ft_strdup.c \
			 ft_substr.c \
			 ft_strjoin.c \
			 ft_strtrim.c \
			 ft_split.c \
			 ft_itoa.c \
			 ft_strmapi.c \
			 ft_striteri.c \
			 ft_putchar_fd.c \
			 ft_putstr_fd.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 ft_printf.c \
			 ft_printf_num.c \
			 ft_printf_hex.c \
			 ft_printf_text.c \
			 ft_count_utils.c \
			 get_next_line.c \
			 get_next_line_utils.c \
			 ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstadd_back.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c \
			 ft_lstmap.c \
			 ft_isonly.c

BONUS	:= ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \


OBJ      := $(SRC:.c=.o)
ARFLAGS   := rcs
RM		    := rm -f
BONUSOBJ	:= $(BONUS:.c=.o)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus:	$(OBJ) $(BONUSOBJ)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(BONUSOBJ)

all:		$(NAME)

clean:
			$(RM) $(OBJ) $(BONUSOBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
