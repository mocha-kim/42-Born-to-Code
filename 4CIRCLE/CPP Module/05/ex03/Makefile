# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 21:15:35 by sunhkim           #+#    #+#              #
#    Updated: 2021/10/20 15:36:27 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= bureaucrat

SRCS			= main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp \
				  RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
CXXFLAGS		= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME) *_shrubbery

re:				fclean $(NAME)

.PHONY:			all clean fclean re