# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 15:43:36 by sunhkim           #+#    #+#              #
#    Updated: 2022/04/07 16:17:52 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#    design sources from : https://pixelfrog-assets.itch.io/kings-and-pigs     #
# **************************************************************************** #

NAME		= so_long

INC_PATH	= ./includes
SRC_PATH	= ./srcs
MMS_PATH	= ./mlx_beta
MLX_PATH	= ./mlx

INCS		= -I $(INC_PATH)
SRCS		= $(SRC_PATH)/main.c \
			  $(SRC_PATH)/gnl.c $(SRC_PATH)/utils.c $(SRC_PATH)/utils2.c\
			  $(SRC_PATH)/parsing.c
OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -O3 -Wall -Wextra -Werror
MLXFLAGS	= -Lmlx -lm -Lmlx_beta -lmlx -framework OpenGL -framework AppKit
MMS			= libmlx.dylib
MLX			= libm.a

.c.o:
		$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(NAME):	$(MLX) $(OBJS) $(MMS)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) -L $(MLX_PATH) $(MLXFLAGS) $(OBJS)
	@echo $(NAME) : Created

$(MLX):
	@$(MAKE) -C mlx
	mv $(MLX_PATH)/libmlx.a $(MLX_PATH)/$(MLX)

$(MMS):
	@$(MAKE) -C mlx_beta
	cp $(MMS_PATH)/$(MMS) .

all:	$(NAME)

clean:
	@$(MAKE) -C mlx clean
	@$(MAKE) -C mlx_beta clean
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS) $(MMS) $(MLX_PATH)/$(MLX)

re:		fclean all

.PHONY: all clean fclean re
