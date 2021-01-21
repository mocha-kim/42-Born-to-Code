# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 15:07:43 by sunhkim           #+#    #+#              #
#    Updated: 2021/01/20 18:09:31 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIB_PATH	= ./libft
INC_PATH	= ./includes
SRC_PATH	= ./srcs
OBJ_PATH	= ./objs

LIB			= ./libft/libft.a
INCS		= -I $(INC_PATH)
SRCS		= $(addprefix $(SRC_PATH)/, $(SRC_LIST))
OBJS		= $(SRCS:.c=.o)

SRC_LIST	= 

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

.c.o:
	$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	make all -C $(LIBFT)/
	cp $(LIB) ./$(NAME)
	ar rc $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re:		fclean all

.PHONY: all clean fclean re
