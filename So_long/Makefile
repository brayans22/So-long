NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx
FT_PRINT	=	ft_printf/libftprintf.a
HEADERS		=	-I ./headers -I ./ft_printf/Includes -I ./mlx -I ./get_next_line
LIB			=	-L ./ft_printf -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

SRC			=	src/graphic.c \
			src/element.c \
			src/file.c \
			src/game.c \
			src/map.c \
			src/so_long.c \
			src/util.c \
			src/map_validator.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(FT_PRINT) $(OBJ)
	$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
	@echo " [ .. ] | ⏳ Compiling minilibx.. ⏳"
	@make -C mlx
	@echo " [ OK ✅ ] | ⌛ Minilibx ready! ⌛"

$(FT_PRINT):
	@echo " [ .. ] | ⏳ Compiling ft_printf.. ⏳ "
	@make -C ft_printf
	@echo " [ OK ✅ ] | ⌛ ft_printf ready! ⌛   "

clean:
	@make clean -C ft_printf
	@rm -rf $(OBJ)
	@echo "object files removed. 🚮"

fclean: clean
	@make fclean -C ft_printf
	@rm -f $(NAME)
	@echo "binary file removed. 🚮"

re: fclean all

.PHONY: all clean fclean re