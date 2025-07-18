NAME = libftprintf.a

SRC = *.h, */*.h, *.c, */*.c ft_printf.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all = $(NAME)

$(NAME) = $(OBJ)
	ar rcs $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
