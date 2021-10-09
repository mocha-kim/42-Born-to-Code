# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 19:40:18 by sunhkim           #+#    #+#              #
#    Updated: 2021/10/09 19:41:18 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fixed

SRCS			= main.cpp Fixed.cpp
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