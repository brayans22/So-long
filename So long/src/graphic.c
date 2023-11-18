#include "../headers/game.h"

int	ft_destroy(t_igraphic *igraphic)
{
	mlx_destroy_window(igraphic->mlx_ptr, igraphic->win_ptr);
	free(igraphic->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	select_img(t_game *game, int width, int height, \
		int (*f)(void*, void*, void*, int, int))
{
	void	*img;

	img = game->graphic.img_floor;
	if (game->map[height][width] == WALL)
		img = game->graphic.img_wall;
	else if (game->map[height][width] == COLLECTABLE)
	{
		game->player.remaining_collectables++;
		img = game->graphic.img_collectable;
	}
	else if (game->map[height][width] == POSITION)
	{
		game->player.pos_y = width;
		game->player.pos_x = height;
		img = game->graphic.img_player;
	}
	else if (game->map[height][width] == EXIT)
		img = game->graphic.img_exit;
	f(game->graphic.mlx_ptr, game->graphic.win_ptr, img, \
			width * 48, height * 48);
}

void	add_images_window(t_game *game)
{
	unsigned int	height;
	unsigned int	width;
	
	game->player.remaining_collectables = 0;
	height = 0;
	while (height < game->height_map)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] != LINE_BREAK)
				select_img(game, width, height, \
						&mlx_put_image_to_window);
			width++;
		}
		height++;
	}
}

void	add_images_game(t_igraphic *igraphic)
{
	int	pos_x;
	int	pos_y;
	int	f;

	
	igraphic->img_collectable = mlx_xpm_file_to_image \
				    (igraphic->mlx_ptr,"images/collectable.xpm" \
				     , &pos_x, &pos_y);
	igraphic->img_exit = mlx_xpm_file_to_image
			(igraphic->mlx_ptr,"images/exit.xpm", &pos_x, &pos_y);
	igraphic->img_floor = mlx_xpm_file_to_image
			(igraphic->mlx_ptr, "images/original.xpm", &pos_x, &pos_y);
	igraphic->img_wall = mlx_xpm_file_to_image
			(igraphic->mlx_ptr, "images/wall.xpm", &pos_x, &pos_y);
	igraphic->img_player = mlx_xpm_file_to_image
			(igraphic->mlx_ptr,"images/si.xpm",&pos_x , &pos_y);
}
