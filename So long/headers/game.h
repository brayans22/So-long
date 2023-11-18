
#ifndef GAME_H
# define GAME_H

/* Includes */
# include "constants.h"
# include "../mlx_linux/mlx.h"
# include "file.h"
# include <stdio.h>

/* Structs */
typedef struct s_player
{
    int total_movements;
    int remaining_collectables;
    unsigned int pos_x;
    unsigned int pos_y;
} t_player;

typedef struct s_igraphic
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_exit;
    void    *img_collectable;
    void    *img_wall;
    void    *img_player;
    void    *img_floor;
} t_igraphic;

typedef struct s_game
{
    unsigned int    width_map;
    unsigned int    height_map;
    char            **map;
    t_igraphic      graphic;
    t_player        player;
} t_game;

/* Prototypes */
int initialize_game(t_game *game, char** map, int width_map, int height_map);
int ft_destroy(t_igraphic *igraphic);
void add_images_game(t_igraphic *igraphic);
void add_images_window(t_game *game);

#endif // GAME_H