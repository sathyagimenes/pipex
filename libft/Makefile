NAME	= libft.a
CFLAGS	= -Wall -Werror -Wextra -g3
CC		= gcc
AR		= ar rcs
RM		= rm -f
HEADER	= libft.h

SRCS	= ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c		\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_strcpy.c		\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_convert_to_base.c	\
		ft_printf.c		\

UTILS	= ./utils/printf_type_c.c	\
		./utils/printf_type_d_i.c	\
		./utils/printf_type_p.c		\
		./utils/printf_type_s.c		\
		./utils/printf_type_u.c		\
		./utils/printf_type_x.c		\
		./utils/printf_type_upperx.c

OBJS := ${SRCS:%.c=%.o}
OBJU := ${UTILS:%.c=%.o}

all:		${NAME}

${NAME}:	${OBJS} ${OBJU} ${HEADER}
			${AR} $@ $^

%.o: %.c ${HEADER}
			${CC} ${CFLAGS} -c -o $@ $<

clean:
			${RM} ${OBJS}
			${RM} ${OBJU}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
