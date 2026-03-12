# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmosheuv <mmosheuv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 18:37:18 by mmosheuv          #+#    #+#              #
#    Updated: 2025/11/27 15:35:35 by mmosheuv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror 
CC = cc

SRCS = ft_isdigit.c \
	   ft_putchar_fd.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_isprint.c \
	   ft_putendl_fd.c \
	   ft_strlcat.c \
	   ft_substr.c \
	   ft_atoi.c \
	   ft_itoa.c \
	   ft_putnbr_fd.c \
	   ft_strlcpy.c \
	   ft_tolower.c \
	   ft_bzero.c \
	   ft_memchr.c \
	   ft_putstr_fd.c \
	   ft_strlen.c \
	   ft_toupper.c \
	   ft_calloc.c \
	   ft_memcmp.c \
	   ft_split.c \
	   ft_strmapi.c \
	   ft_isalnum.c \
	   ft_memcpy.c \
	   ft_strchr.c \
	   ft_strncmp.c \
	   ft_isalpha.c \
	   ft_memmove.c \
	   ft_strdup.c \
	   ft_strnstr.c \
	   ft_isascii.c \
	   ft_memset.c \
	   ft_striteri.c \
	   ft_strrchr.c



OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "##### Lib created #####"

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	@rm -f $(OBJ)
	@echo "##### Removed lib object files #####"
	
fclean: clean
	@rm -f $(NAME)
	@echo "##### Removed libft.a #####"

re: fclean all
.PHONY: all clean fclean re