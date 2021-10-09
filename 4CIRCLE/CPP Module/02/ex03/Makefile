# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 19:42:02 by sunhkim           #+#    #+#              #
#    Updated: 2021/10/09 19:42:23 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= bsp

SRCS			= main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= clang++
FLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re