#ifndef FILE_H
# define FILE_H

/* Includes */
# include "constants.h"
# include "map_validator.h"
# include "../get_next_line/get_next_line.h"
# include "util.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/* Structs */
typedef struct s_file
{
    char *line;
    unsigned int len;
}t_file;

/* Protypes */
int process_file(char *path_file);

#endif //FILE_H