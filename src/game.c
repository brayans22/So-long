#include "../headers/game.h"


int initialize_game(t_game *game)
{
    game->status = START;
    //initialize_map(game->map);
    if (!game->map)
    {
        return (ERROR);
    }

}

int get_game_status(t_game game)
{
    return 0;
}