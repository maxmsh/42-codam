# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 09:45:15 by mmosheuv          #+#    #+#              #
#    Updated: 2025/12/02 19:34:26 by mmosheuv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
INC = ft_printf.h
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = ft_printdigit.c \
	   ft_printstring.c \
	   ft_pointer_address.c \
	   ft_printformat.c \
	   ft_printf.c \
	   ft_printunsigned.c \
	   ft_printhex.c \
	   ft_printlong.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		cp libft/libft.a $(NAME)
		ar rcs $(NAME) $(OBJS)

%.o.:%.c $(INC)
		@$(CC) $(CFLAGS) -c $< - o $@

clean:
		$(MAKE) fclean -C ./libft
		@rm -f $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		@rm -f $(NAME)

re	:	fclean all

.PHONY: all clean fclean re