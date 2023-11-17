#ifndef GRAPHIC_H
# define GRAPHIC_H

/* Includes */
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

/* Structs */
typedef struct s_igraphic
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_exit;
    void    *img_collectable;
    void    *img_wall;
    void    *img_player;
    void    *img_floor;
}t_igraphic;

/* Protypes */
int     ft_destroy(t_igraphic *igraphic);
void    add_images_game(t_igraphic *igraphic);

#endif //GRAPHIC_H