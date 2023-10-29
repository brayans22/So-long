NAME = libftprintf.a

FT_PRINTF =		Src/ft_putchar.c					\
				Src/ft_putstr.c 					\
				Src/ft_printf.c		    			\
				Src/format_char.c					\
				Src/format_digit.c					\
				Src/format_ptr.c					\
				Src/format_str.c					\
				Src/format_unsigned.c				
    
SRCS = 			${FT_PRINTF}

OBJS = 			${SRCS:.c=.o}

CFLAGS = 		-Wall -Werror -Wextra

%.o:%.c		Makefile Includes/ft_printf.h
			${CC} ${CFLAGS} -I ./ -c $< -o $@

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all: 		${NAME}

clean:
			rm -f ${OBJS}

fclean:	clean;
			rm -f ${NAME}

re:	fclean all

.PHONY: 	all clean fclean re
