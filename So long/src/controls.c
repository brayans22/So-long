/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:55:28 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/11/18 19:46:05 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/game.h"
#include "../headers/constants.h"

static void	move_up(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player.pos_x;
	pos_y = game->player.pos_y;
	if (game->map[pos_x - 1][pos_y] == COLLECTABLE)
	{
		game->player.remaining_collectables--;
		game->player.total_movements++;
		game->map[pos_x - 1][pos_y] = POSITION;
		game->map[pos_x][pos_y] = EMPTY;
		game->player.pos_x--;
	}
	else if (game->map[pos_x - 1][pos_y] == EMPTY)
	{
		game->player.total_movements++;
		game->map[pos_x - 1][pos_y] = POSITION;
		game->map[pos_x][pos_y] = EMPTY;
		game->player.pos_x--;
	}
}

int	controls(int command, t_game *game)
{

	if (command == 53)
	{
		//end_game();
	}
	else if (command == 13)
	{
		move_up(game);
		//w
	}
	else if (command == 1)
	{
		//s
	}
	else if (command == 0)
	{
		//a
	}
	else if (command == 2)
	{	
		//d
	}
	if (command)
		add_images_window(game);
	return (1);
}
