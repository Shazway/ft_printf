SRCS_PRINTF		=	srcs/ft_printf.c srcs/ft_parsing.c

INCLUDES		=	-Iincludes								\
					-Ilibft

NAME			=	libftprintf.a
SRCS			=	$(SRCS_PRINTF)


OBJS			=	$(SRCS:.c=.o)
CC				=	gcc
RM				=	@rm -f

LIBFT			=	libft/libft.a

FLAGS			=	-Wall -Werror -Wextra $(INCLUDES)

.c.o:
					@$(CC) $(FLAGS) -c $< -o $@

$(NAME):			clear_screen $(OBJS) start_message $(LIBFT)
					@if [ "$?" = "clear_screen start_message" ]; then echo -n "\033[1A\033[30C\033[0;33mAlready done\033[15D\033[1B\033[1A\033[2D\033[1;32m✓\033[26D\033[1B\033[0m";else echo -n "\033[1A\033[25C\033[1;32m✓\033[26D\033[1B\033[0m"; fi
					ar rc $(NAME) $(OBJS)
					ranlib $(NAME)
$(LIBFT):
					@make -C libft -f Makefile
					mv $(LIBFT) ./$(NAME)


all:				$(NAME)

bonus:				re

clear_screen:
					@clear

clean:
					@clear
					@make -s -C libft -f Makefile clean
					@echo "\033[0;33mCleaning \033[1;31m$(NAME)\033[0;33m's objects\033[0m"
					$(RM) $(OBJS)

fclean:				clean
					@make -s -C libft -f Makefile fclean
					@echo "\033[0;33mRemoving \033[1;31m$(NAME)\033[0;33m.\033[0m"
					$(RM) $(NAME)

start_message:
					@echo "\033[0;33mMaking \033[1;31m$(NAME)\033[0;33m\t\t\033[1;30m[\033[1;31mX\033[1;30m]\033[0m"

re:					fclean $(OBJS) start_message $(LIBFT)
					@if [ "$?" = "fclean start_message" ]; then echo -n "\033[1A\033[30C\033[0;33mAlready done\033[15D\033[1B\033[1A\033[2D\033[1;32m✓\033[26D\033[1B\033[0m";else echo -n "\033[1A\033[25C\033[1;32m✓\033[26D\033[1B\033[0m"; fi
					ar rc $(NAME) $(OBJS)
					ranlib $(NAME)
.PHONY:				all clean fclean re
