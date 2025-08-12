NAME = libft.a
SRC = $(wildcard ft*.c)
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ) libft.so

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

so: $(SRC)
	$(CC) $(CFLAGS) -fPIC -c $(SRC)
	$(CC) -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re so

