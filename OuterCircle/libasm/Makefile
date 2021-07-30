NAME		= libasm.a

SRCS		= ft_strlen.s ft_strcpy.s ft_strcmp.s \
				ft_write.s ft_read.s ft_strdup.s
OBJS		= $(SRCS:.s=.o)

ASM			= nasm
FLAGS		= -f macho64
TEST		= test

.s.o:
			$(ASM) $(FLAGS) $<

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS) $(BONUS_OBJS)

fclean:		clean
			rm -rf $(NAME) $(TEST)

re:			fclean $(NAME)

test:		$(NAME)
			gcc -Wall -Werror -Wextra -L. -lasm -o $(TEST) test.c
			./$(TEST) < Makefile

.PHONY: 	all clean fclean re
