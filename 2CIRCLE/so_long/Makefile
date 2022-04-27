# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 15:43:36 by sunhkim           #+#    #+#              #
#    Updated: 2022/04/27 00:10:00 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#    design sources from : https://pixelfrog-assets.itch.io/kings-and-pigs     #
# **************************************************************************** #

NAME		= so_long

INC_PATH	= ./includes
SRC_PATH	= ./srcs
MLX_PATH	= ./mlx

INCS		= -I $(INC_PATH)
SRCS		= $(SRC_PATH)/main.c $(SRC_PATH)/gnl.c $(SRC_PATH)/memory.c \
			  $(SRC_PATH)/utils.c $(SRC_PATH)/utils2.c $(SRC_PATH)/utils3.c \
			  $(SRC_PATH)/parsing.c $(SRC_PATH)/game.c $(SRC_PATH)/move.c
OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -O3 -Wall -Wextra -Werror
MLXFLAGS	= -Lmlx -lm -framework OpenGL -framework AppKit
MLX			= libm.a

.c.o:
		$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(NAME):	$(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) -L $(MLX_PATH) $(MLXFLAGS) $(OBJS)
	@echo $(NAME) : Created

$(MLX):
	@$(MAKE) -C mlx
	mv $(MLX_PATH)/libmlx.a $(MLX_PATH)/$(MLX)

all:	$(NAME)

clean:
	@$(MAKE) -C mlx clean
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS) $(MLX_PATH)/$(MLX)

re:		fclean all

.PHONY: all clean fclean re
