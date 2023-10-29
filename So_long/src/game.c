#include "../headers/game.h"


int initialize_game(t_game *game)
{
    if (game->status == 0)
        return 0;
    return (0);
    /*
    game->status = START;
    //initialize_map(game->map);
    if (!game->map)
    {
        return (ERROR);
    }
    */
    return (SUCCESSFUL);
}

int get_game_status(t_game game)
{
    if (game.status == 0)
        return 0;
    return (0);
}