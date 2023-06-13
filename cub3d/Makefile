# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 12:26:28 by pealexan          #+#    #+#              #
#    Updated: 2023/06/13 14:37:45 by pealexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COLORS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COMMANDS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CC = cc
RM = rm -rf
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CFLAGS	= -Wall -Wextra -Werror -g#-fsanitize=address
MK		= --no-print-directory
LIBFT	= ./libft/libft.a
MLX		= ./minilibx-linux/libmlx_Linux.a
EXTRA 	= -lXext -lX11

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS			= inc
SRCS			= src
LIBFT_PATH		= libft
MLX_PATH		= minilibx-linux
#_SUBFOLDERS	= commands debug executor parser signals utils 
VPATH			= $(SRCS) $(addprefix $(SRCS)/, $(_SUBFOLDERS))
OBJ_DIR			= bin

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
NAME			= cub3d
_FILES			= main
OBJS			= $(_FILES:%=%.o)
TARGET			= $(addprefix $(OBJ_DIR)/, $(OBJS))


#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(OBJ_DIR) $(TARGET)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(YELLOW)$(LIBFT)$(RESET)"
	$(MAKE) $(MK) -C $(LIBFT_PATH)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(PURPLE)$(MLX)$(RESET)"
	$(MAKE) $(MK) -C $(MLX_PATH)

#	echo "[$(CYAN) Linking $(RESET)] $(GREEN)LIBFT + $(PURPLE)MINILIBX$(RESET)"
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(EXTRA) $(YELLOW)$(LIBFT) $(PURPLE)$(MLX)$(RESET)"
	$(CC) $(CFLAGS) $(TARGET) -o $(NAME) -I $(DEPS) $(EXTRA) $(LIBFT) $(MLX)

	echo "$(GREEN)Done.$(RESET)"

$(OBJ_DIR)/%.o : %.c
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) clean $(MK) -C $(LIBFT_PATH)
	$(MAKE) clean $(MK) -C $(MLX_PATH)

	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(OBJ_DIR)$(RESET)"
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean $(MK) -C $(LIBFT_PATH)

	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

re: fclean all

.SILENT:

.PHONY: libft all bonus clean fclean re run r leaks
