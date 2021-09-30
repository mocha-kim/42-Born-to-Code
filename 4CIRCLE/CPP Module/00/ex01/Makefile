# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 19:00:05 by sunhkim           #+#    #+#              #
#    Updated: 2021/09/30 20:39:23 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= phonebook

SRCS			= main.cpp contact.cpp phonebook.cpp 
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