NAME := so_long
CC := gcc
FLAGS := -Wall -Wextra -Werror -IHeaders/
SRCS := src/*.c
GET_NEXT_LINE := get_next_line/*.c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX) 
			$(CC) $(FLAGS) $(SRCS) $(GET_NEXT_LINE) $(LIBRARY) -o $(NAME)

clean:

fclean: clean 
			make clean -C $(MINILIBX)
			rm -rf $(NAME)

re: fclean all

.PHONY: make re clean fclean