#include "../headers/util.h"

static int is_format_ber(char *format_path)
{
    char *format_ber;

    format_ber = BER_FORMAT;
    while ((*format_path) == (*format_ber) && (*format_path) && (*format_ber))
    {
        format_path++;
        format_ber++;
    }
    return ((*format_ber) == NULL_CHARACTER && (*format_path) == NULL_CHARACTER);
}

int display_error_message(char *message, size_t len)
{
    write(1, message, len);
    return (ERROR);
}

int is_valid_path(char *path)
{
    size_t len;

    len = ft_strlen(path);
    return (len > 4 && is_format_ber(path + len - 4));
}