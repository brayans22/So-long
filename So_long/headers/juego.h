
#ifndef JUEGO_H
#define JUEGO_H

#include "../headers/map.h"

typedef struct s_juego
{
    int total_movements_player;
    int status;
    t_map map;
}					t_juego;

#endif //JUEGO_H
