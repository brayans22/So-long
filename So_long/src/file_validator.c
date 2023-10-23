#include "../headers/file_validator.h"

static int valid_line(char *line, int *count_lines)
{
    size_t len_line;
    size_t total_characters_wall;

    len_line = ft_strlen(line);
    total_characters_wall = 0;
    if ((*count_lines) == 1)
    {
        while (ft_strchr(line, WALL))
            total_characters_wall++;
        if (!(line[total_characters_wall] == LINE_BREAK && len_line + 1 == total_characters_wall))
        {
            perror(ERROR_INVALID_BORDER);
            return (ERROR);
        }
    }
    (*count_lines)++;
    return (SUCCESSFUL);
}

int process_file(char *path_file)
{
    char *line;
    int  fd;
    int  count_lines;

    fd = open(path_file, O_RDONLY);
    if (fd == ERROR)
        return (ERROR);
    line = get_next_line(fd);
    if (!line || (line && !ft_strchr(line, LINE_BREAK))
    {
        perror(ERROR_INVALID_MAP);
        return (ERROR);
    }
    count_lines = 1;
    while (line != NULL && check_file(fd, &count_lines) != ERROR)
    {
        free(line);
        line = get_next_line(fd);
    }
    if (count_lines < 3)
    {
        perror(ERROR_INVALID_MAP);
        return (ERROR);
    }
    if (close(fd) == ERROR)
        perror(ERROR_CLOSE_FILE);
    return (SUCCESSFUL);
}
