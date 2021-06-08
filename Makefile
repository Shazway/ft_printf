SRCS_MEM	=	libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_memmove.c libft/ft_memchr.c libft/ft_memcmp.c
SRCS_STR	=	libft/ft_strchr.c libft/ft_strdup.c libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_strlen.c
SRCS_PUTFD	=	libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c
SRCS_IS		=	libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_toupper.c libft/ft_tolower.c
SRCS_TO		=	libft/ft_atoi.c libft/ft_itoa.c
SRCS_MALLOC	=	libft/ft_calloc.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_strmapi.c
SRCS_BONUS	=	${SRCS} libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c
SRCS_PRINTF	=	ft_parse.c ft_printf.c
SRCS		=	${SRCS_MEM} ${SRCS_STR} ${SRCS_PUTFD} ${SRCS_IS} ${SRCS_TO} ${SRCS_MALLOC} ${SRCS_PRINTF}

OBJS	=	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

CC		=	gcc
RM		=	rm -f
NAME	=	printf.a

FLAGS	=	-Wall -Werror -Wextra

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${RM} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:	${OBJS_BONUS}
			ar rc ${NAME} ${OBJS_BONUS}
			ranlib ${NAME}

.PHONY:		all clean fclean re
