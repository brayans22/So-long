#Directories So Long
SRC_DIR			= ./src/
INCLUDES_DIR	= ./headers/

#OBJECTS SO LONG
OBJS_SO_LONG = $(SRCS_SO_LONG:.c=.o)
SRCS_SO_LONG = $(addprefix $(SRC_DIR), 								\
file.c game.c get_next_line.c get_next_line_utils.c  				\
graphic.c map_validator.c map.c so_long.c util.c main.c				\
)

#GCC & Makefile & Name
NAME = so_long
CC = gcc
MAKE_FILE = Makefile
SO_LONG_HEADER_FILE = /headers/so_long.c
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

#SYS OPERATIVE
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

all : _mlx $(NAME)

$(NAME) : $(MAKE_FILE) $(OBJS_SO_LONG) $(MLX_PATH)
	@$(CC) $(CFLAGS) $(OBJS_SO_LONG) $(MLX_PATH) $(GNOME_FLAGS) -o $(NAME) 
	@echo " Compilation of so_long is ok"

%.o : %.c $(SO_LONG_HEADER_FILE) $(MAKE_FILE)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES_DIR)

clean :
	@make clean -C $(GNOME_PATH)
	@rm -f $(OBJS_SO_LONG)
	@echo " have been deleted ❌"

fclean : clean
	@make clean -C $(GNOME_PATH)
	@rm -f $(NAME)
	@echo " All has been deleted "

re: fclean all

_mlx :
	@make -C $(GNOME_PATH)

.PHONY:	all test clean fclean re
