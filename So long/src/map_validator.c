#include "../headers/map_validator.h"
#include <stdio.h>

static int check_counter(char *line, int *total_exits, \
int *total_positions, int type)
{
    int result;

    result = TRUE;
    while ((*line) != NULL_CHARACTER && result && (*total_exits) <= 1 && (*total_positions) <= 1)
    {
        if ((*line) == EXIT)
            (*total_exits)++;
        else if ((*line) == POSITION)
            (*total_positions)++;
        else if ((*line) != WALL && (*line) != EMPTY && (*line) != LINE_BREAK && (*line) != COLLECTABLE)
        {
            display_error_message("Z", 1);
            result = FALSE;
            display_error_message(ERROR_INVALID_SYMBOL, 43);
        }
        line++;
    }
    if (((*total_exits) == 0 || (*total_positions) == 0) && type == LAST_LINE)
    {
        display_error_message(ERROR_FEW_ELEM, 39);
        result = FALSE;
    }
    else if (((*total_exits) > MAX_EXITS || (*total_positions) > MAX_POSITIONS) && type == MIDDLE_LINE)
    {
        display_error_message(ERROR_MORE_ELEM, 58);
        result = FALSE;
    }
    return (result);
}

static int is_valid_border(char *line, int type)
{
    char *aux;

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

int is_valid_line(char *line, int type, int *total_exits, int *total_positions, size_t len_first_line)
{
    int result;

    result = TRUE;
    if ((type == MIDDLE_LINE || type == LAST_LINE))
    {
        if ((type == LAST_LINE && len_first_line - 1 != ft_strlen(line) )
            || (type == MIDDLE_LINE && len_first_line != ft_strlen(line)))
        {
            display_error_message("Error\n la longitud de la linea es distinta de las anteriores", 60);
            result = FALSE;
        }
        else if (!check_counter(line, total_exits, total_positions, type))
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

int is_rectangle_map(int widht, int height)
{
    return (widht > 0 && height > 0 && widht != height);
}