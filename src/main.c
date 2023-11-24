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

static char	*ft_strdup(char *s, unsigned int len)
{
	char 			*cpy;
	unsigned int	i;

	cpy = (char *)malloc(len);
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == LINE_BREAK && s[i + 1] == NULL_CHARACTER)
		{
			cpy[i] = NULL_CHARACTER;
			return (cpy);
		}
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = NULL_CHARACTER;
	return (cpy);
}

static char	**get_cpymap(t_game *game, char **map, unsigned int total)
{
	char			**map_cpy;
	unsigned int 	i;

	map_cpy = (char **)malloc(sizeof(char *) * total);
	if (!map_cpy)
	{
		free_case(game->map, NULL, NULL, total);
		return (NULL);
	}
	i = 0;
	while (i < total)
	{
		map_cpy[i] = ft_strdup(map[i], ft_strlen(map[0]));
		if (!map_cpy[i])
		{
			free_game(game);
			free_case(map_cpy, NULL, NULL, i);
			return (NULL);
		}
		i++;
	}
	return (map_cpy);
}

static int	start_program(char *path_file)
{
	t_game	game;
	size_t	total_lines;
	char	**map_cpy;
	int		status_check;

	total_lines = 0;
	game.map = NULL;
	map_cpy = NULL;
	game.map = process_file(path_file, game.map, &total_lines);
	if (!game.map || total_lines <= 0)
		return (ERROR);
	initialize_game(&game, ft_strlen(game.map[total_lines - 1]), total_lines);
	add_images_window(&game);
	map_cpy = get_cpymap(&game, game.map, total_lines);
	status_check = check_pathmap(&game, map_cpy);
	if (status_check == ERROR || status_check == FALSE)
		return (ERROR);
	mlx_key_hook(game.graphic.win_ptr, controls, &game);
	mlx_hook(game.graphic.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.graphic.mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && is_valid_pathfile(argv[1]))
		return (start_program(argv[1]));
	else if (argc < 2)
		return (display_message(ERROR_FEW_ARGUMENTS, 24));
	else if (argc > 2)
		return (display_message(ERROR_MANY_ARGUMENTS, 26));
	else
		return (display_message(ERROR_INVALID_FORMAT, 37));
	return (0);
}
