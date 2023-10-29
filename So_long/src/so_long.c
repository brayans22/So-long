#include "../get_next_line/get_next_line.h"
#include "../headers/graphic.h"
#include "../mlx/mlx.h"
#include "../headers/game.h"
#include "../headers/file.h"

static int start_program(char *path_file)
{
    //t_game      game;
    t_igraphic  igraphic;

    if (process_file(path_file) == ERROR)
        return (ERROR);
    igraphic.mlx_ptr = mlx_init();
    if (!igraphic.mlx_ptr)
        return (ERROR);
    mlx_loop(igraphic.mlx_ptr);

    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2 && is_valid_path(argv[1]))
        return (start_program(argv[1]));
    else if (argc < 2)
        return (display_error_message(ERROR_FEW_ARGUMENTS));
    else if (argc > 2)
        return (display_error_message(ERROR_MANY_ARGUMENTS));
    else
        return (display_error_message(ERROR_INVALID_FORMAT));
    return (0);
}
