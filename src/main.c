#include "../headers/get_next_line.h"
#include "../headers/game.h"
#include "../headers/file.h"

static void play_turn(t_game* game)
{
    //display_game(*game);
    //make_movement(game);
}

static void play_game (t_game *game)
{
    while (get_game_status(*game) == PLAYING) 
        play_turn(game);
    //if (get_game_status(*game) == ENDGAME)  
        //Libero la memoria.
}

static int start_program(char *path_file)
{
    t_game *game;
    
    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
    {
        perror(ERROR_MEMORY);
        return (ERROR);
    }
    process_file(path_file);
    //initialize_game(game, path_file);
    //play_game(game);
    //free(game);
    //display_result
}

int main(int argc, char **argv)
{
    start_program("map.txt");
    /*
    if (argc == 2)
        return (start_program(argv[1]));
    else if (argc < 2)
        perror(ERROR_FEW_ARGUMENTS);
    else
        perror(ERROR_MANY_ARGUMENTS);
    */
    return (0);
}
