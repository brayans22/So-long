#include "../get_next_line/get_next_line.h"
#include "../headers/graphic.h"
#include "../mlx/mlx.h"
#include "../headers/game.h"
#include "../headers/file.h"

/*
static void play_turn(t_game* game)
{
    if (game->status)
        return ;
    //display_game(*game);
    //make_movement(game);
}
*/

/*
static void play_game (t_game *game)
{
    while (get_game_status(*game) == PLAYING) 
        play_turn(game);
    if (game->status)
        return ;
    //if (get_game_status(*game) == ENDGAME)  
        //Libero la memoria.
}
*/

static int start_program(char *path_file)
{
    t_game *game;
    t_igraphic igraphic;
    
    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
    {
        perror(ERROR_MEMORY);
        return (ERROR);
    }
    process_file(path_file);
    //CHECK MAP
    //ABRO LA VENTANA
    igraphic.mlx_ptr = mlx_init();
    if (!igraphic.mlx_ptr)
        return (ERROR);
    //igraphic.win_ptr = mlx_new_window(igraphic.mlx_ptr, 900, 500, "so long");
    //if (!igraphic.win_ptr)
    //{
        //free(igraphic.mlx_ptr);
        //return (ERROR);
    //}
    //mlx_put_image_to_window(igraphic.mlx_ptr, igraphic.win_ptr, mlx_xpm_file_to_image(igraphic.mlx_ptr, "images/sr2c62ac69cb385 (convert.io).xpm", 0, 0), 50, 50);
    //mlx_destroy_window(igraphic.mlx_ptr, igraphic.win_ptr);
    mlx_loop(igraphic.mlx_ptr);
    //initialize_game(game, path_file);
    //play_game(game);
    //free(game);
    //display_result
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        return (start_program(argv[1]));
    else if (argc < 2)
        perror(ERROR_FEW_ARGUMENTS);
    else
        perror(ERROR_MANY_ARGUMENTS);
    return (0);
}
