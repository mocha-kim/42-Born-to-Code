# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 15:07:43 by sunhkim           #+#    #+#              #
#    Updated: 2021/01/30 20:05:34 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

INC_PATH	= ./includes
SRC_PATH	= ./srcs
OBJ_PATH	= ./objs

INCS		= -I $(INC_PATH)
SRCS		= $(addprefix $(SRC_PATH)/, $(SRC_LIST))
OBJS		= $(SRCS:.c=.o)

SRC_LIST	= ft_printf.c ft_printf_utils.c ft_printf_utils2.c \
			  ft_printf_flags.c ft_printf_cs.c ft_printf_d.c ft_printf_u.c \
			  ft_printf_p.c ft_printf_x.c

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

.c.o:
	$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
