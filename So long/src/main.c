/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:53:44 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/11/18 19:42:57 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file.h"
#include "../headers/game.h"
#include "../headers/get_next_line.h"
#include "../headers/util.h"
#include "../mlx_mac/mlx.h"

static int	start_program(char *path_file)
{
	t_game	game;
	size_t	total_lines;
	char	**map;

	total_lines = 0;
	map = NULL;
	map = process_file(path_file, map, &total_lines);
	if (!map)
		return (ERROR);
	for (size_t i = 0; i < total_lines; i++)
		printf("%s", map[i]);
	printf("/n");
	initialize_game(&game, map, ft_strlen(map[total_lines - 1]), total_lines);
	add_images_window(&game);
	mlx_key_hook(game.graphic.win_ptr, controls, &game);
	mlx_hook(game.graphic.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.graphic.mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && is_valid_path(argv[1]))
		return (start_program(argv[1]));
	else if (argc < 2)
		return (display_error_message(ERROR_FEW_ARGUMENTS, 24));
	else if (argc > 2)
		return (display_error_message(ERROR_MANY_ARGUMENTS, 26));
	else
		return (display_error_message(ERROR_INVALID_FORMAT, 37));
	return (0);
}
