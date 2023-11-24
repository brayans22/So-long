#include "../headers/constants.h"
#include "../headers/game.h"

static int	is_valid_around_player(char **map, int x, int y)
{
	if (map[x][y] == POSITION && (map[x][y + 1] == COLLECTABLE \
	|| map[x][y + 1] == EMPTY || map[x - 1][y] == COLLECTABLE \
	|| map[x - 1][y] == EMPTY || map[x][y - 1] == COLLECTABLE \
	|| map[x][y - 1] == EMPTY || map[x + 1][y] == COLLECTABLE \
	|| map[x + 1][y] == EMPTY))
		return (TRUE);
	return (FALSE);
}

static void	mark_foot_player(char **map, int x, int y, int *c)
{
	if (map[x][y] == COLLECTABLE || map[x][y] == EMPTY)
	{
		if (map[x][y] == COLLECTABLE)
			(*c)--;
		map[x][y] = POSITION;
	}
}

static int	found_path_to_exit(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if ((map[x][y] == EXIT && map[x][y + 1] == POSITION)
			|| (map[x][y] == EXIT && map[x][y - 1] == POSITION)
			|| (map[x][y] == EXIT && map[x - 1][y] == POSITION)
			|| (map[x][y] == EXIT && map[x + 1][y] == POSITION))
				return (TRUE);
			y++;
		}
		x++;
	}
	return (FALSE);
}

static int	flood_fill(t_game *game, char **map_cpy, int collect)
{
	int	x;
	int	y;

	x = 0;
	while (x < (int)game->height_map)
	{
		y = 0;
		while (map_cpy[x][y] != NULL_CHARACTER)
		{
			if (is_valid_around_player(map_cpy, x, y))
			{
				mark_foot_player(map_cpy, x, y - 1, &collect);
				mark_foot_player(map_cpy, x - 1, y, &collect);
				mark_foot_player(map_cpy, x, y + 1, &collect);
				mark_foot_player(map_cpy, x + 1, y, &collect);
				x = 0;
			}
			y++;
		}
		x++;
	}
	if (collect == 0 && found_path_to_exit(map_cpy))
		return (TRUE);
	return (FALSE);
}

int	check_pathmap(t_game *game, char **map_cpy)
{
	int	status;

	if (!map_cpy)
	{
		free_game(game);
		display_message(ERROR_MEMORY, 19);
		return (ERROR);
	}
	if (!game)
	{
		free_case(map_cpy, NULL, NULL, game->height_map);
		display_message(ERROR_MEMORY, 19);
		return (ERROR);
	}
	status = flood_fill(game, map_cpy, game->player.remaining_collectables);
	if (status == FALSE)
		display_message(ERROR_INVALID_PATH, 44);
	free_case(map_cpy, NULL, NULL, game->height_map);
	return (status);
}
