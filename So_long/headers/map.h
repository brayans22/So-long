#ifndef MAP_H
#define MAP_H

#include "../headers/element.h"

typedef struct s_map
{
    int max_fil;
    int max_col;
    t_element *elements;
}					t_map;

#endif //MAP_H
