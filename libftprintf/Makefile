NAME = libftprintf.a

SRC = ft_printf.c /ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c \
	  ft_putptr.c ft_putunsigned.c ft_strlen.c ft_strchr.c \
	  ft_strlcpy.c ft_strjoin.c ft_strdup.c ft_itoa.c

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
