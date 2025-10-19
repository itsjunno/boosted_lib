/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** ᕕ( ᐛ )ᕗ
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/my_struct.h"
#include "../../include/my_macro.h"
#include "../../include/my.h"

int initialise_struct(struct_data_t *data, const char *format)
{
    data->char_written = 0;
    my_strcpy(data->fmt_copy, format);
    return SUCCESS;
}

int my_printf(char const *format, ...)
{
    struct_data_t data;

    va_start(data.ap, format);
    if (initialise_struct(&data, format))
        return ERROR;
    for (; *data.fmt_copy; *data.fmt_copy++) {
        if (*data.fmt_copy == '%' && format_parser(&data) == true) {
                return 0;
        } else {
            my_putchar(*data.fmt_copy);
        }
    }
}
