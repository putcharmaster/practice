# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 15:26:44 by sanhwang          #+#    #+#              #
#    Updated: 2024/05/06 12:00:14 by sanhwang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = server client
SRCS = client.c server.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all:	$(NAME)

server:	server.c
	$(CC) $(CFLAGS) server.c -o server

client:	client.c
	$(CC) $(CFLAGS) client.c -o client

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
