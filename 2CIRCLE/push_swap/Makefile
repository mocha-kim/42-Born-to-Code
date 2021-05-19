NAME		= push_swap

INC_PATH	= ./includes
SRC_PATH	= ./srcs
LFT_PATH	= ./libft

INCS		= -I $(INC_PATH)
SRCS		= 
OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= libft.a

.c.o:
		$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS)
	@echo $(NAME) : Created

$(MLX):
	@$(MAKE) -C $(LFT_PATH)

all:	$(NAME)


clean:
	@$(MAKE) -C $(LFT_PATH) clean
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME) $(LFT_PATH)/$(LIBFT)

re:		fclean all

.PHONY: all clean fclean re
