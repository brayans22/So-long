#include "../headers/map_validator.h"

int is_valid_border(char *line, int count_lines)
{
    int     i;

    if (!line)
    {
        perror(ERROR_INVALID_MAP);
        return (ERROR);
    }
    i = 0;
    while (line[i] == WALL)
        i++;
    if (line[i] == LINE_BREAK && line[i + 1] == NULL_CHARACTER && count_lines == 1)
        return (SUCCESSFUL);
    else if (line[i] == NULL_CHARACTER && count_lines > 1)
        return (SUCCESSFUL);
    return (ERROR);
}
