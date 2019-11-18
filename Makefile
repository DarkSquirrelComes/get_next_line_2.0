NAME=get_next_line.a

SRC = get_next_line.c

OBJ = $(subst .c,.o,$(SRC))

CFLAGS = -Wall -Werror -Wextra

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
