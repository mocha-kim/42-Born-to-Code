# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 18:59:59 by sunhkim           #+#    #+#              #
#    Updated: 2021/10/06 23:38:23 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= replace

SRCS			= main.cpp Replace.cpp
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