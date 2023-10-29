#include "../headers/map.h"

int initialize_map(t_map *map)
{
    map = (t_map *)malloc(sizeof(t_map));
    if (map != NULL)
    {
        map->total_elements = 0;
        map->max_col = 0;
        map->max_fil = 0;
        map->elements = NULL;
        return (SUCCESSFUL);
    }
    return (display_error_message(ERROR_MEMORY));
}