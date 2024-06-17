# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangha <sangha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 20:17:27 by sanhwang          #+#    #+#              #
#    Updated: 2024/06/17 01:05:06 by sangha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = ./src/main.c ./src/input.c ./src/error.c ./src/radix.c ./src/until_five.c\
       ./src/utils.c ./src/push.c ./src/rotate.c ./src/swap.c ./src/rev_rotate.c\
	   ./src/finder.c ./src/index.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re