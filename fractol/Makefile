# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 16:27:25 by sanhwang          #+#    #+#              #
#    Updated: 2024/07/21 16:27:32 by sanhwang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
NAME = fractol
SRCS = ./src/main.c ./src/str_util.c ./src/ft_atof.c ./src/data_util.c \
	./src/render.c ./src/fractal.c
OBJS = $(SRCS:./src/%.c=./objs/%.o)
MLX_LIB = mlx
MLX_FLAGS = -L$(MLX_LIB) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

# Target to build the executable
all: $(NAME)

# Target to clone and build MiniLibX
$(MLX_LIB):
	if [ ! -d "$(MLX_LIB)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_LIB); \
	fi
	$(MAKE) -C $(MLX_LIB)

# Target to link object files into the executable
$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Pattern rule to compile .c files into .o files
./objs/%.o: ./src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(MLX_LIB) -c $< -o $@

# Target to clean object files
clean:
	rm -rf ./objs

# Target to clean everything
fclean: clean
	rm -f $(NAME)
	if [ -d "$(MLX_LIB)" ]; then \
		$(MAKE) clean -C $(MLX_LIB); \
		rm -rf $(MLX_LIB); \
	fi

# Target to rebuild everything
re: fclean all

.PHONY: all clean fclean re
