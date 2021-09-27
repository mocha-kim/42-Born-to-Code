# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 18:31:03 by sunhkim           #+#    #+#              #
#    Updated: 2021/09/27 18:48:12 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= megaphone

SRCS			= megaphone.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
CXXFLAGS		= -Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test