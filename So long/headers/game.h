#ifndef GAME_H
# define GAME_H

/* Includes */
# include "constants.h"
# include "file.h"
# include "graphic.h"
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
    int             status;
    unsigned int    width_map;
    unsigned int    height_map;
    char            **map;
    t_igraphic      graphic; 
    t_player        *player;
}t_game;

/* Protypes */
int get_game_status(t_game game);
int initialize_game(t_game *game, char** map, int width_map, int height_map);
#endif //GAME_H