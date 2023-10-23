#include "../headers/get_next_line.h"
#include "../headers/element.h"
#include "../headers/juego.h"

#include <stdio.h>


int start_program(char *path)
{
    int file_status;
    int program_status;
    char game_status;

    file_status = process_file(path);
    if (file_status == ERROR)
        return (ERROR);
    while (game_status() == PLAYING)
    {

    }
    return (0);
}


int main(int argc, char **argv)
{
    if (argc == 2)
        return (start_program(argv[1]));
    else if (argc < 2)
        perror(ERROR_FEW_ARGUMENTS);
    else
        perror(ERROR_MANY_ARGUMENTS);
    return (0);
}
