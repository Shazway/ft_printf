SRCS_PRINTF		=	srcs/ft_printf.c srcs/ft_parsing.c main.c

INCLUDES		=	-Iincludes								\
					-Ilibft

LD_FLAGS		=	-Llibft -lft

NAME			=	printf
SRCS			=	$(SRCS_PRINTF)



OBJS			=	$(SRCS:.c=.o)
CC				=	gcc
RM				=	@rm -f

LIBFT			=	libft/libft.a

FLAGS			=	-Wall -Werror -Wextra $(INCLUDES) -fsanitize=address -g

.c.o:
					@$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

$(NAME):			clear_screen $(LIBFT) start_message $(OBJS)
					@if [ "$?" = "clear_screen start_message" ]; then echo -n "\033[1A\033[30C\033[0;33mAlready done\033[15D\033[1B\033[1A\033[2D\033[1;32m✓\033[26D\033[1B\033[0m";else echo -n "\033[1A\033[25C\033[1;32m✓\033[26D\033[1B\033[0m"; fi
					@$(CC) $(OBJS) $(FLAGS) -o $(NAME) $(LD_FLAGS)

$(LIBFT):
					@make -s -C libft -f Makefile


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

re:					fclean $(LIBFT) start_message $(OBJS)
					@if [ "$?" = "fclean start_message" ]; then echo -n "\033[1A\033[30C\033[0;33mAlready done\033[15D\033[1B\033[1A\033[2D\033[1;32m✓\033[26D\033[1B\033[0m";else echo -n "\033[1A\033[25C\033[1;32m✓\033[26D\033[1B\033[0m"; fi
					@$(CC) $(OBJS) $(FLAGS) -o $(NAME) $(LD_FLAGS)

.PHONY:				all clean fclean re