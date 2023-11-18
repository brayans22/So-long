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
