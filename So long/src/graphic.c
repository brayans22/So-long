#include "../headers/graphic.h"

int ft_destroy(t_igraphic *igraphic)
{
    mlx_destroy_window(igraphic->mlx_ptr, igraphic->win_ptr);
    //mlx_destroy_display(igraphic->mlxptr);
    free(igraphic->mlx_ptr);
    exit(EXIT_SUCCESS);
    return (0);
}

void add_images_game(t_igraphic *igraphic)
{
    int pos_x, pos_y;
    igraphic->img_collectable = mlx_xpm_file_to_image(igraphic->mlx_ptr, "images/moneda.xpm", &pos_x, &pos_y);
    igraphic->img_exit = mlx_xpm_file_to_image(igraphic->mlx_ptr, "images/moneda.xpm", &pos_x, &pos_y);
    igraphic->img_floor = mlx_xpm_file_to_image(igraphic->mlx_ptr, "images/moneda.xpm", &pos_x, &pos_y);
    igraphic->img_wall = mlx_xpm_file_to_image(igraphic->mlx_ptr, "images/moneda.xpm", &pos_x, &pos_y);
    igraphic->img_player = mlx_xpm_file_to_image(igraphic->mlx_ptr, "images/moneda.xpm", &pos_x, &pos_y);
}