NAME = pipex
INCLUDES_PATH	= ./includes
LIBFT_PATH = ./libft
LIB = libft/libft.a
CC	= cc
CFLAGS	= -Wall -Werror -Wextra -g3

SRCS = ./sources/main.c			\
	./sources/error_messages.c	\
	./sources/validations.c	\

OBJS	= $(SRCS:%.c=%.o)

all:	$(NAME) ${LIB}

$(NAME):	${LIB} $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@ -L $(LIBFT_PATH) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -lft

%.o:		%.c
			$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -I $(LIBFT_PATH) -o $@ -c $<

${LIB}:
			make -C libft

run:	$(NAME)
		./pipex infile.txt "ls -l" "wc -l" outfile

clean:
			$(MAKE) clean -C $(LIBFT_PATH)
			rm -f $(OBJS)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_PATH)
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re