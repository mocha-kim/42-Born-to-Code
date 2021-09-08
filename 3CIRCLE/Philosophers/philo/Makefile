# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 19:42:16 by sunhkim           #+#    #+#              #
#    Updated: 2021/09/08 19:08:53 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

OBJS = $(SRCS:.c=.o)
SRCS = main.c philosophers.c utils.c

CFLAGS		= -Wall -Wextra -Werror -pthread

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
