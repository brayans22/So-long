/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:54:42 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/11/18 18:54:15 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file.h"

static int	check_elements(char *line, t_validator *v)
{
	int		result;
	char	c;

	result = TRUE;
	while ((*line) != NULL_CHARACTER && result && v->total_exits <= 1
		&& v->total_positions <= 1)
	{
		c = *line;
		if (c == EXIT)
			v->total_exits++;
		else if (c == POSITION)
			v->total_positions++;
		else if (c != COLLECTABLE && c != WALL && c != EMPTY && c != LINE_BREAK
				&& c != NULL_CHARACTER)
		{
			result = FALSE;
			display_error_message(ERROR_INVALID_SYMBOL, 43);
		}
		line++;
	}
	return (result);
}

static int	check_counter(char *line, t_validator *v, int type)
{
	int	result;

	result = check_elements(line, v);
	if ((v->total_exits == 0 || v->total_positions == 0)
		&& type == LAST_LINE)
	{
		display_error_message(ERROR_FEW_ELEM, 39);
		result = FALSE;
	}
	else if ((v->total_exits > MAX_EXITS || v->total_positions > MAX_POSITIONS)
		&& type == MIDDLE_LINE)
	{
		display_error_message(ERROR_MORE_ELEM, 58);
		result = FALSE;
	}
	return (result);
}

static int	is_valid_border(char *line, int type)
{
	char	*aux;

	aux = line;
	if (!line)
		return (FALSE);
	while ((*line) == WALL && (*line) != NULL_CHARACTER)
		line++;
	if (type == FIRST_LINE)
		return ((*line) == LINE_BREAK && *((line + 1)) == NULL_CHARACTER);
	else if (type == LAST_LINE)
		return ((*line) == NULL_CHARACTER);
	return (aux[0] == WALL && aux[ft_strlen(aux) - 2] == WALL);
}

int	is_valid_line(char *line, int type, t_validator *v,
		size_t len_first_line)
{
	int	result;

	result = TRUE;
	if ((type == MIDDLE_LINE || type == LAST_LINE))
	{
		if ((type == LAST_LINE && len_first_line - 1 != ft_strlen(line))
			|| (type == MIDDLE_LINE && len_first_line != ft_strlen(line)))
		{
			display_error_message("Error\n no es cuadrado\n", 22);
			result = FALSE;
		}
		else if (!check_counter(line, v, type))
			result = FALSE;
		else if (!is_valid_border(line, type))
		{
			display_error_message(ERROR_INVALID_BORDER, 28);
			result = FALSE;
		}
	}
	else if (type == FIRST_LINE && !is_valid_border(line, type))
	{
		display_error_message(ERROR_INVALID_BORDER, 28);
		result = FALSE;
	}
	return (result);
}

int	is_rectangle_map(int widht, int height)
{
	return (widht > 0 && height > 0 && widht != height);
}
