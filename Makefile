# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gade-oli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 19:33:19 by gade-oli          #+#    #+#              #
#    Updated: 2024/10/10 19:20:13 by gade-oli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colors----------------------------------------------------------

RED 	= '\033[1;31m'
GREEN   = '\033[1;32m'
BLUE    = '\033[1;34m'
RESET   = '\033[0;0m'

#variables-------------------------------------------------------

NAME = push_swap
BONUS = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

# Removed libft dependency

SRC = main.c \
	parser.c \
	utils.c \
	utils2.c \
	utils3.c \
	utils4.c \
	utils5.c \
	movements.c \
	sort.c
BIN = $(SRC:%.c=bin/%.o)

#recipes---------------------------------------------------------

all:	$(NAME)

bin/%.o: %.c
	@echo $(BLUE)"compiling binaries..."$(RESET)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(BIN)
	$(CC) $(CFLAGS) $(BIN) -o $@
	@echo $(GREEN)"$(NAME) compiled!"$(RESET)

clean:
	rm -rf $(BIN) $(BIN_BONUS) .bonus
	@echo $(RED)"binaries deleted"$(RESET)

fclean: clean
	rm -rf $(NAME) $(BONUS) bin/
	@echo $(RED)"$(NAME) deleted!"$(RESET)

re:	fclean all

bonus: .bonus

.bonus: $(BIN_BONUS)
	$(CC) $(CFLAGS) $(BIN_BONUS) -o $(BONUS)
	@echo $(GREEN)"$(BONUS) compiled!"$(RESET)
	@touch .bonus

.PHONY: all clean fclean re bonus
