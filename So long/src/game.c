#include "../headers/game.h"

int initialize_game(t_game *game, char **map, int width_map, int height_map)
{
    if (!game || !map)
        return (ERROR);
    game->width_map = width_map;
    game->height_map = height_map;
    game->map = map;
    game->graphic.mlx_ptr = mlx_init();
    if (!game->graphic.mlx_ptr)
        return (ERROR);
    game->graphic.win_ptr = mlx_new_window(game->graphic.mlx_ptr, game->width_map * 40, 
                                           game->height_map * 40, "So-Long");
    if (!game->graphic.win_ptr);
        return (ERROR);
    add_images_game(&game->graphic);
    game->player = NULL;
    game->status = PLAYING;
    return (SUCCESSFUL);
}
