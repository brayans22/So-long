#ifndef ELEMENT_H
# define ELEMENT_H

/* Includes */
# include "constants.h"
# include "position.h"
# include <stdio.h>

/* Structs */
typedef struct s_element
{
    char code;
    int is_collectable;
    t_position position;
}t_element;

/* Protypes */


#endif //ELEMENT_H