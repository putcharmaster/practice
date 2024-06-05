# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 17:54:16 by sanhwang          #+#    #+#              #
#    Updated: 2024/06/05 19:05:03 by sanhwang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = ./src/main.c ./src/input.c ./src/sort.c ./src/rotate.c ./src/rev_rotate.c\
       ./src/push.c ./src/ft_atol.c ./src/free.c ./src/finder.c ./src/algo.c\
	   ./src/extra.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all:	$(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
