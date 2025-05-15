NAME    := push_swap
SRC     := main.c parser.c utils.c utils2.c utils3.c utils4.c movements.c sort.c
OBJ     := $(SRC:.c=.o)

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g3

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all