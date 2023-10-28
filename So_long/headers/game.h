#ifndef GAME_H
# define GAME_H

/* Includes */
# include "constants.h"
# include "map.h"
# include "position.h"
# include <stdio.h>

/* Structs */
typedef struct s_player
{
    char code;
    int total_movements;
    t_position position; 
}t_player;

typedef struct s_game
{
    int     status;
    t_map   *map;
    t_player *player;
}t_game;

/* Protypes */
int get_game_status(t_game game);
int initialize_game(t_game *game);

#endif //GAME_H