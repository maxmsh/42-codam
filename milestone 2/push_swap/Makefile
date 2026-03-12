# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 21:56:31 by mmosheuv          #+#    #+#              #
#    Updated: 2026/02/19 03:56:02 by mmosheuv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

SRCS = helpers.c \
	   input.c \
	   main.c \
	   operations.c \
	   radix.c \
	   sort.c \
	   split.c \
	   stack.c \
	   utils.c


OBJS = $(SRCS:.c=.o)

all = $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	make $(NAME)

.PHONY: all clean fclean re