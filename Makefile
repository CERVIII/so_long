# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 11:44:31 by snunez            #+#    #+#              #
#    Updated: 2023/09/25 10:18:41 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address -g3

SRC_DIR = ./src

SRCS =	so_long.c check_map.c check_game.c events.c events2.c print_map.c \
		check_path.c

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

all: $(NAME)
	@echo " \033[36m[ 🕹️  ] | READY TO PLAY!\033[0m"

.SILENT: $(OBJS)
$(NAME): $(OBJS)
	@echo "\033[36m" '╔═════════════════════════════════════════════════╗'	"\033[0m"
	@echo "\033[36m" '║\033[33m      _____ ____       __    ____  _   ________  \033[36m║'	"\033[0m" 
	@echo "\033[36m" '║\033[33m     / ___// __ \     / /   / __ \/ | / / ____/  \033[36m║'	"\033[0m" 
	@echo "\033[36m" '║\033[33m     \__ \/ / / /    / /   / / / /  |/ / / __    \033[36m║'	"\033[0m" 
	@echo "\033[36m" '║\033[33m    ___/ / /_/ /    / /___/ /_/ / /|  / /_/ /    \033[36m║'	"\033[0m" 
	@echo "\033[36m" '║\033[33m   /____/\____/____/_____/\____/_/ |_/\____/     \033[36m║'	"\033[0m" 
	@echo "\033[36m" '║\033[33m             /_____/                             \033[36m║'	"\033[0m"
	@echo "\033[36m" '╚═════════════════════════════════════════════════╝'	"\033[0m"
	@echo " \033[33m[ .. ] | Compiling minilibx..\033[0m"
	@make -C $(MLX_PATH) --silent
	@echo " \033[32m[ OK ] | ✅ Minilibx ready! ✅\033[0m"
	@echo " \033[33m[ .. ] | Compiling libft..\033[0m"
	@make bonus -C $(LIBFT_PATH) --silent
	@echo " \033[32m[ OK ] | ✅ Libft ready! ✅\033[0m"
	@echo " \033[33m[ .. ] | Compiling so_long..\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBFT) -o $(NAME)
	@echo " \033[32m[ OK ] | ✅ So_long ready! ✅\033[0m"

run:
	./$(NAME) map.ber

clean:
	@make clean -C $(LIBFT_PATH) --silent
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH) --silent
	@echo " \033[35m[ OK ] | 🧹 So_long clean! 🧹\033[0m"
#	@make clean -C $(MLX_PATH) --silent

re:	fclean all

.PHONY: 	all clean fclean re
.SILENT: $(OBJS)