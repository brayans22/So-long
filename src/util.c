#include "../headers/util.h"

int print_message(char *message, size_t len)
{
    if (!message)
        return (ERROR);
    write(1, message, len);
    return (ERROR);
}