# Directories
SRC_DIR = ./src/
INCLUDES_DIR = ./headers/

# Objects
SRCS_SO_LONG = $(addprefix $(SRC_DIR), \
	file.c graphic.c game.c get_next_line.c get_next_line_utils.c \
	map_validator.c so_long.c util.c main.c  \
)
OBJS_SO_LONG = $(SRCS_SO_LONG:.c=.o)

# GCC & Makefile & Name
NAME = so_long
CC = gcc
MAKE_FILE = Makefile
SO_LONG_HEADER_FILE = $(INCLUDES_DIR)so_long.h

# Debug
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

# System
UNAME = $(shell uname -s)

ifeq ($(UNAME), DARWIN)
	GNOME_FLAGS = -framework OpenGL -framework Appkit -l z
	GNOME_PATH = ./mlx_mac/
	MLX_PATH = $(GNOME_PATH)/libmlx.dylib
else
	GNOME_FLAGS = -lXext -lX11 -lm -lbsd
	GNOME_PATH = ./mlx_linux/
	MLX_PATH = $(GNOME_PATH)/libmlx.a
endif

# Compilation flags
FLAGS = -I $(INCLUDES_DIR) -I $(GNOME_PATH) $(CFLAGS)

# Targets
all : _mlx $(NAME)

$(NAME) : $(MAKE_FILE) $(OBJS_SO_LONG) $(MLX_PATH)
	@$(CC) $(FLAGS) $(OBJS_SO_LONG) $(MLX_PATH) $(GNOME_FLAGS) -o $(NAME)
	@echo " [ OK ✅ ] | ⌛ So long ready! ⌛   "

%.o : %.c $(SO_LONG_HEADER_FILE) $(MAKE_FILE)
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@make clean -C $(GNOME_PATH)
	@rm -f $(OBJS_SO_LONG)
	@echo "object files removed. 🚮"

fclean : clean
	@make clean -C $(GNOME_PATH)
	@rm -f $(NAME)
	@echo "binary file removed. 🚮"

re : fclean all

_mlx :
	@make -C $(GNOME_PATH)

.PHONY: all clean fclean re _mlx