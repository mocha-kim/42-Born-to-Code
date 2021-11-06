# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 13:00:44 by sunhkim           #+#    #+#              #
#    Updated: 2021/11/06 22:08:54 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= mutantStack

SRCS			= main.cpp mutantstack.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
CXXFLAGS		= -Wall -Wextra -Werror #-fsanitize=address

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re