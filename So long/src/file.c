#include "../headers/file.h"

char **free_case(char **lines, char *line, char *next_line, 
                unsigned int total_lines, int case_free)
{
    if (case_free == FREE_LINES_MATRIX || case_free == FREE_MATRIX_AND_LINE || case_free == FREE_ALL)
    {
        if (lines != NULL)
        {
            while (total_lines-- > 0)
		        free(lines[total_lines]);
	        free(lines);
        }
    }
    if ((case_free == FREE_LINE_AND_NEXT || case_free == FREE_ALL) && next_line != NULL)
        free(next_line);
    if ((case_free == FREE_LINE || case_free == FREE_LINES_MATRIX || case_free == FREE_ALL) 
        && line != NULL)
    {
        free(line);
    }
	return (NULL);
}

static char **add_newline(char **lines, char *line, size_t total_lines)
{
    char    **new_lines;
    size_t  i;

    new_lines = (char **)malloc(sizeof(char *) * (total_lines + 1));
    if (!new_lines)
    {
        display_error_message(ERROR_MEMORY, 20);
        return (free_case(lines, line, NULL, total_lines, FREE_MATRIX_AND_LINE));
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

static char **check_lines(char *line, int fd, size_t *total_lines, int *total_exits, int *total_positions)
{   
    int     type_line;
    char    *next;
    char    **lines;

    if (!line)
        return (NULL);
    lines = (char **)malloc(sizeof(char *) * 1);
    if (!lines)
        return (free_case(lines, line, NULL, *total_lines, FREE_LINE));
    lines[(*total_lines)++] = line;
    line = get_next_line(fd);
    type_line = MIDDLE_LINE;
    while (line != NULL)
    {
        next = get_next_line(fd);
        if (next == NULL)
            type_line = LAST_LINE;
        else if (!is_valid_line(line, type_line, total_exits, total_positions, ft_strlen((const char *)lines[0])) && next != NULL)
            return(free_case(lines, line, next, *total_lines, FREE_ALL));
        lines = add_newline(lines, line, (*total_lines)++);
        if (!lines)
            return (free_case(lines, line, next, (*total_lines)--, FREE_LINE_AND_NEXT));
        line = next;
    }
    return (lines);
}

static int open_fd(char *path_file)
{
    int fd;

    fd = open(path_file, O_RDONLY);
    if (fd <= ERROR)
        display_error_message(ERROR_OPEN_FILE, 33);
    return (fd);
}

char **process_file(char *path_file, char **lines, size_t *total_lines)
{
    char    *line;
    int     total_exits;
    int     total_positions;
    int     fd;
    
    fd = open_fd(path_file);
    if (fd <= ERROR)
        return (NULL);
    (*total_lines) = 0;
    line = get_next_line(fd);
    if (!is_valid_line(line, FIRST_LINE, 0, 0, ft_strlen((const char *)line)))
        return (free_case(lines, line, NULL, *total_lines, FREE_LINE));
    lines = check_lines(line, fd, total_lines, &total_exits, &total_positions);
    if (!lines)
        return (NULL);
    if ((*total_lines) <= 2 || !is_valid_line(lines[(*total_lines) - 1], LAST_LINE, 
        &total_exits, &total_positions, ft_strlen((const char *)lines[0])))
        return (free_case(lines, NULL, NULL, *total_lines, FREE_LINES_MATRIX));
    if (close(fd) == ERROR)
    {
        display_error_message(ERROR_CLOSE_FILE, 37);
        return (free_case(lines, NULL, NULL, *total_lines, FREE_LINES_MATRIX));
    }
    return (lines);
}
