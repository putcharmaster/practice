# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangha <sangha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 17:54:16 by sanhwang          #+#    #+#              #
#    Updated: 2024/06/14 23:57:36 by sangha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = ./src/main.c ./src/input.c ./src/sort.c ./src/rotate.c ./src/rev_rotate.c\
       ./src/push.c ./src/ft_atol.c ./src/free.c ./src/finder.c ./src/algo.c\
	   ./src/extra.c ./src/ft_split.c ./src/error.c ./src/swap.c ./src/move.c\
	   ./src/cheap.c ./src/target.c ./src/best.c ./src/dumb.c 
OBJS = $(SRCS:.c=.o)

# Clean command
RM = rm -rf

# Default target
all: $(NAME)

# Linking the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compiling the object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJS)

# Clean object files and the executable
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
