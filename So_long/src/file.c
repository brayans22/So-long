#include "../headers/file.h"

static int update_tfile(t_file **file, char *line, int total_lines)
{
    t_file *aux;
    int i;

    if (total_lines > 1 && line != NULL)
    {
        i = -1;
        aux = *file;
        *file = (t_file *)malloc(sizeof(t_file) * total_lines);
        if (!*file)
        {   
            free(aux);
            free(line);
            return (print_message(ERROR_MEMORY, 34));
        }
        while (++i < total_lines - 1)
            (*file)[i] = aux[i];
        free(aux);
    }
    if (line != NULL)
    {
        (*file)[total_lines - 1].line = line;
        (*file)[total_lines - 1].len = ft_strlen(line);
        return (SUCCESSFUL);
    }
    return (print_message(ERROR_MEMORY, 34));
}

static int read_file(t_file **file, char *line, int fd, int *total_lines)
{
    int update_status;

    update_status = update_tfile(file, line, *total_lines);
    if (update_status == ERROR)
        return (print_message(ERROR_MEMORY, 34));
    while (line != NULL && update_status != ERROR)
    {
        line = get_next_line(fd);
        if (line != NULL)
        {
            (*total_lines)++;
            update_status = update_tfile(file, line, *total_lines);
            if (update_status == ERROR)
            {
                free(line);
                return (print_message(ERROR_MEMORY, 34));
            }
        }
    }
    // QUIERE DECIR QUE NO ES UN MAPA VALIDO, COMO MINIMO DEBE TENER 3 LINEAS O MAS.....
    if ((*total_lines) < 3)
        return (print_message(ERROR_INVALID_MAP, 35));
    if (is_valid_border((*file)[(*total_lines) - 1].line, *total_lines) == ERROR)
        return (print_message(ERROR_INVALID_BORDER, 29));
    return (SUCCESSFUL);
}

int process_file(char *path_file)
{
    char    *line;
    t_file  *file;
    int     fd;
    int     total_lines;

    total_lines = 1;
    file = NULL;
    fd = open(path_file, O_RDONLY);
    if (fd == ERROR)
        return (print_message(ERROR_OPEN_FILE, 34));
    line = get_next_line(fd);
    if (is_valid_border(line, 1) == ERROR)
        return (print_message(ERROR_INVALID_BORDER, 29));
    file = (t_file *)malloc(sizeof(t_file) * total_lines);
    if (!file)
    {
        free(line);
        return (print_message(ERROR_MEMORY, 34));
    } 
    if (read_file(&file, line, fd, &total_lines) == ERROR)
        return (ERROR);
    if (close(fd) == ERROR)
        return (print_message(ERROR_CLOSE_FILE, 38));
    for (int i = 0; i < total_lines; i++)
    {
        printf("Len: %i\n", file[i].len);
        printf("%s", file[i].line);
    }
    printf("\n");
    return (SUCCESSFUL);
}