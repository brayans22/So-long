/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:54:57 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/11/18 19:34:09 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

/* Includes */
# include "constants.h"
# include "../mlx_mac/mlx.h"
# include "file.h"
# include <stdio.h>

/* Structs */
typedef struct s_player
{
	int				total_movements;
	int				remaining_collectables;
	unsigned int	pos_x;
	unsigned int	pos_y;
}t_player;

typedef struct s_igraphic
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_exit;
	void	*img_collectable;
	void	*img_wall;
	void	*img_player;
	void	*img_floor;
}t_igraphic;

typedef struct s_game
{
	unsigned int	width_map;
	unsigned int	height_map;
	char			**map;
	t_igraphic		graphic;
	t_player		player;
}t_game;

/* Prototypes */
int		initialize_game(t_game *game, int width_map, int height_map);
void	add_images_game(t_igraphic *igraphic);
void	add_images_window(t_game *game);
int		controls(int command, t_game *game);
int		free_game(t_game *game);
int		check_pathmap(t_game *game, char **map_cpy);

#endif // GAME_H
