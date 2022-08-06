# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 11:44:31 by snunez            #+#    #+#              #
#    Updated: 2022/08/07 01:24:31 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address

SRC_DIR = ./src

SRCS = so_long.c check_map.c check_game.c events.c events2.c print_map.c

OBJS = $(addprefix $(SRC_DIR)/, ${SRCS:.c=.o})

NAME = so_long

UNAME := $(shell uname -s)

LIBFT_PATH = ./libft/

LIBFT = -L$(LIBFT_PATH) $(LIBFT_PATH)libft.a

ifeq ($(UNAME),Darwin)
	MLX_PATH = minilibx_opengl/
	MINILIBX:= -L $(MLX_PATH) $(MLX_PATH)libmlx.a -lmlx -framework OpenGL -framework AppKit
else
	MLX_PATH = minilibx_linux/
	MINILIBX:= -L $(MLX_PATH) $(MLX_PATH)libmlx.a -lmlx -lXext -lX11
endif

$(NAME) :	slibft mlx $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBFT) -o $(NAME)

run:
	./$(NAME) map.ber
all:	$(NAME)

slibft:
		make -C $(LIBFT_PATH)

mlx:
		make -C $(MLX_PATH)

clean:
		make clean -sC $(LIBFT_PATH)
		make clean -sC $(MLX_PATH)
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY = all clean fclean re

