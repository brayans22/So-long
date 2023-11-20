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

static void	collectable_action(t_game *game, int mov, int direction)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player.pos_x;
	pos_y = game->player.pos_y;
	if (direction == UP_OR_DOWN)
	{
		game->map[pos_x + mov][pos_y] = POSITION;
		game->player.pos_x += mov;
	}
	else
	{
		game->map[pos_x][pos_y + mov] = POSITION;
		game->player.pos_y += mov;
	}
	game->map[pos_x][pos_y] = EMPTY;
	game->player.remaining_collectables--;
	game->player.total_movements++;
}

static void	empty_action(t_game *game, int mov, int direction)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player.pos_x;
	pos_y = game->player.pos_y;
	if (direction == UP_OR_DOWN)
	{
		game->map[pos_x + mov][pos_y] = POSITION;
		game->player.pos_x += mov;
	}
	else
	{
		game->map[pos_x][pos_y + mov] = POSITION;
		game->player.pos_y += mov;
	}
	game->player.total_movements++;
	game->map[pos_x][pos_y] = EMPTY;
}

static void	move_up_down(t_game *game, int mov)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player.pos_x;
	pos_y = game->player.pos_y;
	if (game->map[pos_x + mov][pos_y] == COLLECTABLE)
		collectable_action (game, mov, UP_OR_DOWN);
	else if (game->map[pos_x + mov][pos_y] == EMPTY)
		empty_action(game, mov, UP_OR_DOWN);
	else if (game->map[pos_x + mov][pos_y] == EXIT)
	{
		if (game->player.remaining_collectables == 0)
		{
			game->player.total_movements++;
			display_message(WON_MESSAGE, 11);
			free_game(game);
		}
		else
			display_message(FAIL_EXIT_MESSAGE, 49);
	}
}

static void	move_left_right(t_game *game, int mov)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player.pos_x;
	pos_y = game->player.pos_y;
	if (game->map[pos_x][pos_y + mov] == COLLECTABLE)
		collectable_action(game, mov, LEFT_OR_RIGHT);
	else if (game->map[pos_x][pos_y + mov] == EMPTY)
		empty_action(game, mov, LEFT_OR_RIGHT);
	else if (game->map[pos_x][pos_y + mov] == EXIT)
	{
		if (game->player.remaining_collectables == 0)
		{
			game->player.total_movements++;
			display_message(WON_MESSAGE, 11);
			free_game(game);
		}
		else
			display_message(FAIL_EXIT_MESSAGE, 49);
	}
}

int	controls(int k, t_game *game)
{
	if (k == COMMAND_ESC)
		free_game(game);
	if (k == COMMAND_S)
		move_up_down(game, 1);
	else if (k == COMMAND_W)
		move_up_down(game, -1);
	else if (k == COMMAND_A)
		move_left_right(game, -1);
	else if (k == COMMAND_D)
		move_left_right(game, 1);
	if (k == COMMAND_S || k == COMMAND_W || k == COMMAND_A || k == COMMAND_D)
	{
		display_message(TOTAL_MOVEMENTS_MESSAGE, 19);
		ft_putnbr(game->player.total_movements);
		display_message("\n", 1);
		add_images_window(game);
	}
	else
		display_message(INVALID_KEY_MESSAGE, 18);
	return (1);
}
