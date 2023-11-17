#ifndef FILE_H
# define FILE_H

/* Includes */
# include "constants.h"
# include "map_validator.h"
# include "get_next_line.h"
# include "util.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/* Structs */
typedef struct s_file
{
    char    *line;
    size_t  len;
}t_file;

/* Protypes */
char **process_file(char *path_file, char **lines, size_t *total_lines);
char **free_case(char **lines, char *line, char *next_line,
                 unsigned int total_lines, int case_free);

#endif //FILE_H