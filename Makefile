NAME = pipex
BONUS_NAME = pipex_bonus
INCLUDES_PATH	= ./includes
LIBFT_PATH = ./libft
LIB = libft/libft.a
CC	= cc
CFLAGS	= -Wall -Werror -Wextra -g3

SRCS = ./sources/main.c			\
	./sources/utils.c			\
	./sources/error_messages.c	\
	./sources/validations.c

BONUS_SRCS = ./sources/pipex_bonus.c	\
	./sources/utils.c			\
	./sources/error_messages.c	\
	./sources/get_next_line.c

OBJS	= $(SRCS:%.c=%.o)

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

all:	$(NAME) ${LIB}

$(NAME):	${LIB} $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@ -L $(LIBFT_PATH) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -lft

%.o:		%.c
			$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -o $@ -c $<

${LIB}:
			make -C libft

run:	$(NAME)
		./pipex file1.txt "ls -l" "wc -l" outfile

$(BONUS_NAME):	${LIB} ${BONUS_OBJS}
				$(CC) $(CFLAGS) $(BONUS_OBJS) -o $@ -L $(LIBFT_PATH) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -lft

bonus: $(BONUS_NAME) ${LIB} $(BONUS_OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@ -L $(LIBFT_PATH) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -lft

clean:
			$(MAKE) clean -C $(LIBFT_PATH)
			rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_PATH)
			rm -f $(NAME) $(BONUS_NAME)

re:			fclean all

.PHONY:		all clean fclean re