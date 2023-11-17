#include "../headers/get_next_line.h"
#include "../headers/map_validator.h"
#include "../headers/util.h"
#include "../mlx_linux/mlx.h"
#include "../headers/game.h"
#include "../headers/file.h"

/*
    else if (!is_rectangle_map(ft_strlen(lines_fd[0]), (int)total_lines))
    {
        free_case(lines_fd, NULL, NULL, total_lines, FREE_LINES_MATRIX);
        return (ERROR);
    }
    */
    /*
    else if (!there_are_valid_path())
    {
        free_case(lines_fd, NULL, NULL, total_lines, FREE_LINES_MATRIX);
        return (ERROR);
    }
    */

static int start_program(char *path_file)
{
    t_game      game;
    size_t      total_lines;
    char        **map;

    total_lines = 0;
    map = NULL;
    map = process_file(path_file, map, &total_lines);
    if (!map)
        return (ERROR);
    for (size_t i = 0; i < total_lines; i++)
        printf("%s", map[i]);
    initialize_game(&game, map, ft_strlen(map[0]), total_lines);
    
	mlx_loop(game.graphic.mlx_ptr);
    
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2 /*&& is_valid_path(argv[1])*/)
    {
        return (start_program(argv[1]));
    }
    else if (argc < 2)
        return (display_error_message(ERROR_FEW_ARGUMENTS, 24));
    else if (argc > 2)
        return (display_error_message(ERROR_MANY_ARGUMENTS, 26));
    else
        return (display_error_message(ERROR_INVALID_FORMAT, 37));
    return (0);
}
