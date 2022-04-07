NAME		= so_long

INC_PATH	= ./includes
SRC_PATH	= ./srcs
MMS_PATH	= ./mlx_beta
MLX_PATH	= ./mlx
BNS_PATH	= ./bonus

INCS		= -I $(INC_PATH)
SRCS		= $(SRC_PATH)/
OBJS		= $(SRCS:.c=.o)

BNS_SRCS	= $(BNS_PATH)/
BNS_OBJS	= $(BNS_SRCS:.c=.o)

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

$(BONUS):	$(MLX) $(BNS_OBJS) $(MMS)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) -L $(MLX_PATH) $(MLXFLAGS) $(BNS_OBJS)
	@echo $(NAME) : Created

all:	$(NAME)

bonus:	$(BONUS)

clean:
	@$(MAKE) -C mlx clean
	@$(MAKE) -C mlx_beta clean
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS) $(MMS) $(MLX_PATH)/$(MLX)

re:		fclean all

.PHONY: all clean fclean re
