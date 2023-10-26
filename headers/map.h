#ifndef MAP_H
# define MAP_H

/* Includes */
# include <stdlib.h>
# include "constants.h"
# include "position.h"
# include "element.h"
# include <stdio.h>

/* Structs */
typedef struct s_map
{
    unsigned int max_fil;
    unsigned int max_col;
    unsigned int total_elements;
    t_element *elements;
}t_map;

/* Protypes */

#endif //MAP_H