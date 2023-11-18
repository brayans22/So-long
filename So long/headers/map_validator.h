#ifndef MAP_VALIDATOR_H
# define MAP_VALIDATOR_H

/* Includes */
# include <stdlib.h>
# include <stdio.h>
# include "constants.h"
# include "get_next_line.h"
# include "util.h"

/* Protypes */
int is_valid_line(char *line, int type, int *total_exits, int *total_positions, size_t len_first_line);

#endif //MAP_VALIDATOR_H