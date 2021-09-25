# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 19:42:16 by sunhkim           #+#    #+#              #
#    Updated: 2021/09/25 16:49:07 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

OBJS	= $(SRCS:.c=.o)
SRCS	= main.c philosophers.c init.c parse.c threads.c check.c timer.c utils.c

CFLAGS	= -Wall -Wextra -Werror -pthread

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME) : Created

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
