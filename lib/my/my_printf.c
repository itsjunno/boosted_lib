/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** Test printf parser
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"


static void handle_regular_char(struct_data_t *data, int *pos)
{
    my_putchar(data->fmt_copy[*pos]);
    data->char_written++;
    (*pos)++;
}

static void handle_format_specifier(struct_data_t *data, int *pos)
{
    int chars = 0;

    if (parse_format(data, pos)) {
        chars = execute_specifier(data);
        data->char_written += chars;
        return;
    }
    handle_regular_char(data, pos);
}

int my_printf(const char *format, ...)
{
    struct_data_t data;
    int pos = 0;

    data.fmt_copy = (char *)format;
    data.char_written = 0;
    va_start(data.ap, format);
    while (data.fmt_copy[pos] != '\0') {
        if (data.fmt_copy[pos] == '%')
            handle_format_specifier(&data, &pos);
        else
            handle_regular_char(&data, &pos);
    }
    va_end(data.ap);
    return data.char_written;
}
