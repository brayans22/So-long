/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:40:29 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/11/18 18:29:22 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file.h"

char	**free_case(char **lines, char *line, char *next_line, int total_lines)
{
	if (lines != NULL)
	{
		while (total_lines-- > 0)
			free(lines[total_lines]);
		free(lines);
	}
	if (next_line != NULL)
		free(next_line);
	if (line != NULL)
		free(line);
	return (NULL);
}

static char	**add_newline(char **lines, char *line, size_t total_lines)
{
	char	**new_lines;
	size_t	i;

	new_lines = (char **)malloc(sizeof(char *) * (total_lines + 1));
	if (!new_lines)
	{
		display_message(ERROR_MEMORY, 20);
		return (free_case(lines, line, NULL, total_lines));
	}
	i = 0;
	while (i < total_lines)
	{
		new_lines[i] = lines[i];
		i++;
	}
	free(lines);
	new_lines[i] = line;
	return (new_lines);
}

static char	**check_lines(char *line, int fd, size_t *total_lines,
		t_validator *v)
{
	int		t;
	char	*next;
	char	**lines;

	if (!line)
		return (NULL);
	lines = (char **)malloc(sizeof(char *) * 1);
	if (!lines)
		return (free_case(lines, line, NULL, *total_lines));
	lines[(*total_lines)++] = line;
	line = get_next_line(fd);
	t = MIDDLE_LINE;
	while (line != NULL)
	{
		next = get_next_line(fd);
		if (next == NULL)
			t = LAST_LINE;
		else if (!is_valid_line(line, t, v, ft_strlen((const char *)lines[0])))
			return (free_case(lines, line, next, *total_lines));
		lines = add_newline(lines, line, (*total_lines)++);
		if (!lines)
			return (free_case(lines, line, next, *total_lines));
		line = next;
	}
	return (lines);
}

static int	open_fd(char *path_file)
{
	int	fd;

	fd = open(path_file, O_RDONLY);
	if (fd <= ERROR)
		display_message(ERROR_OPEN_FILE, 33);
	return (fd);
}

char	**process_file(char *path_file, char **lines, size_t *total_lines)
{
	char		*line;
	t_validator	v;
	int			fd;

	v.total_exits = 0;
	v.total_positions = 0;
	fd = open_fd(path_file);
	if (fd <= ERROR)
		return (NULL);
	line = get_next_line(fd);
	if (!is_valid_line(line, FIRST_LINE, &v, ft_strlen((const char *)line)))
		return (free_case(lines, line, NULL, *total_lines));
	lines = check_lines(line, fd, total_lines, &v);
	if (!lines)
		return (NULL);
	if ((*total_lines) <= 2 || !is_valid_line(lines[(*total_lines) - 1],
			LAST_LINE, &v,
			ft_strlen((const char *)lines[0])))
		return (free_case(lines, NULL, NULL, *total_lines));
	if (close(fd) == ERROR)
	{
		display_message(ERROR_CLOSE_FILE, 37);
		return (free_case(lines, NULL, NULL, *total_lines));
	}
	return (lines);
}
