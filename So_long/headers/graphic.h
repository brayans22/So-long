#ifndef GRAPHIC_H
# define GRAPHIC_H

/* Includes */
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

/* Structs */
typedef struct s_igraphic
{
    void *mlx_ptr;
    void *win_ptr;
}t_igraphic;

/* Protypes */
int ft_destroy(t_igraphic *igraphic);
int detect_key(int key_sysm, t_igraphic *igraphic);

#endif //GRAPHIC_H