/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:53:14 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/11/18 19:37:13 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/game.h"

static void	initialize_player(t_player *player)
{
	player->total_movements = 0;
	player->pos_x = -1;
	player->pos_y = -1;
	player->remaining_collectables = 0;
}

int	initialize_game(t_game *game, char **map, int width_map, int height_map)
{
	if (!game || !map)
		return (ERROR);
	game->width_map = width_map;
	game->height_map = height_map;
	game->map = map;
	game->graphic.mlx_ptr = mlx_init();
	if (!game->graphic.mlx_ptr)
		return (ERROR);
	game->graphic.win_ptr = mlx_new_window(game->graphic.mlx_ptr,
			game->width_map * 48, game->height_map * 48, "So long");
	if (!game->graphic.win_ptr)
		return (ERROR);
	add_images_game(&game->graphic);
	initialize_player(&game->player);
	return (SUCCESSFUL);
}

static void	free_map(char **map, int height)
{
	int				i;

	if (map != NULL)
	{
		i = 0;
		while (i < height)
			free(map[i++]);
		free(map);
	}
}

int	free_game(t_game *game)
{
	if (game->graphic.mlx_ptr)
		free(game->graphic.mlx_ptr);
	free_map(game->map, game->height_map);
	exit(0);
}

/*
	if (game->graphic.img_collectable)
		mlx_destroy_image(game->graphic.win_ptr, game->graphic.img_collectable);
	if (game->graphic.img_exit)
		mlx_destroy_image(game->graphic.win_ptr, game->graphic.img_exit);
	if (game->graphic.img_floor)
		mlx_destroy_image(game->graphic.win_ptr, game->graphic.img_floor);
	if (game->graphic.img_player)
		mlx_destroy_image(game->graphic.win_ptr, game->graphic.img_player);
	if (game->graphic.img_wall)
		mlx_destroy_image(game->graphic.win_ptr, game->graphic.img_wall);
	if (game->graphic.win_ptr)
		mlx_destroy_window(game->graphic.mlx_ptr, game->graphic.win_ptr);
	*/