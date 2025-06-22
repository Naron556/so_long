CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = ./get_next_line.c ./get_next_line_utils.c


OBJ = $(SRC:.c=.o)

NAME = libgnl.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -Iget_next_line.h -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus