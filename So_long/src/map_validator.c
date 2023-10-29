#include "../headers/map_validator.h"

int is_valid_border(char *line, int count_lines)
{
    if (!line)
        return (display_error_message(ERROR_INVALID_BORDER));
    while ((*line) == WALL && (*line))
        line++;
    if ((*line) == LINE_BREAK && *((line + 1)) == NULL_CHARACTER && count_lines == 1)
        return (TRUE);
    else if ((*line) == NULL_CHARACTER && count_lines > 1)
        return (TRUE);
    return (ERROR);
}
