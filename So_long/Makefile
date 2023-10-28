NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.gen
FT_PRINT	=	ft_printf/libftprintf.a
HEADERS		=	-I ./headers -I ./ft_printf/Includes -I ./mlx -I ./get_next_line
LIB			=	-L ./ft_printf -L 
MLX_FLAGS   =	./mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/graphic.c 							\
      			src/element.c 							\
      			src/file.c 								\
      			src/game.c 								\
      			src/map.c 								\
      			src/so_long.c 							\
      			src/util.c 								\
      			src/map_validator.c 					\
				get_next_line/get_next_line.c     		\
				get_next_line/get_next_line_utils.c 		


ifeq ($(shell uname), Linux)
MLX_FLAGS	= ./mlx -lmlx -lXext -lX11 -lm -lbsd
endif

all:		$(MLX) $(FT_PRINT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX):
	@echo " [ .. ] | ⏳ Compiling minilibx.. ⏳"
	@make -s -C mlx
	@echo " [ OK ✅ ] | ⌛ Minilibx ready! ⌛"

$(FT_PRINT):
	@echo "  ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ ░ "		
	@echo " [ .. ] | ⏳ Compiling ft_printf.. ⏳"
	@make -s -C ft_printf
	@echo " [ OK ✅ ] | ⌛ ft_printf ready! ⌛"

obj:
	@mkdir -p obj

obj/%.o:	src/%.c 
			$(CC) $(FLAGS) $(HEADERS) -o $@ -c $<

obj/%.o:	get_next_line/%.c 
			$(CC) $(FLAGS) $(HEADERS) -o $@ -c $<

clean:
	@make -s $@ -C ft_printf
	@rm -rf $(OBJ) obj
	@echo "object files removed. 🚮"

fclean:		clean
	@make -s $@ -C ft_printf
	@rm -rf $(NAME)
	@echo "binary file removed. 🚮"

re:			fclean all

.PHONY:		all clean fclean re