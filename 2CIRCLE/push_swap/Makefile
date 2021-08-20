# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 12:30:33 by sunhkim           #+#    #+#              #
#    Updated: 2021/08/20 15:34:31 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

INC_PATH	= ./includes
SRC_PATH	= ./srcs

INCS		= -I $(INC_PATH)
SRCS		= $(SRC_PATH)/main.c $(SRC_PATH)/push_swap.c \
			  $(SRC_PATH)/push.c $(SRC_PATH)/rotate.c $(SRC_PATH)/swap.c \
			  $(SRC_PATH)/solve_small.c $(SRC_PATH)/solve.c \
			  $(SRC_PATH)/sort_a.c $(SRC_PATH)/sort_b.c \
			  $(SRC_PATH)/args.c $(SRC_PATH)/stack.c $(SRC_PATH)/utils1.c \
			  $(SRC_PATH)/utils2.c $(SRC_PATH)/utils3.c $(SRC_PATH)/utils4.c
OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS)
	@echo $(NAME) : Created

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
