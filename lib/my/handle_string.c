/*
** EPITECH PROJECT, 2025
** my_handle_string.c
** File description:
** handles strings in my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/my.h"

static void print_padding(int padding)
{
    for (int i = 0; i < padding; i++)
        my_putchar(' ');
}

static int print_limited_string(char const *str, int chars_to_print)
{
    for (int i = 0; i < chars_to_print; i++)
        my_putchar(str[i]);
    return chars_to_print;
}

static int calculate_chars_to_print(char const *str, int precision)
{
    int str_len = my_strlen(str);

    if (precision >= 0)
        return (precision < str_len) ? precision : str_len;
    return str_len;
}

static int calculate_padding(int width, int chars_to_print)
{
    return (width > chars_to_print) ? width - chars_to_print : 0;
}

int my_putstr_formatted(char const *str, int width, int precision,
    bool left_justify)
{
    int chars_to_print;
    int padding;
    int total = 0;

    if (str == NULL)
        str = "(null)";
    chars_to_print = calculate_chars_to_print(str, precision);
    padding = calculate_padding(width, chars_to_print);
    if (!left_justify)
        print_padding(padding);
    total = padding + print_limited_string(str, chars_to_print);
    if (left_justify)
        print_padding(padding);
    return total;
}

int handle_string(struct_data_t *data)
{
    char *str = va_arg(data->ap, char *);

    return my_putstr_formatted(str, data->format.width_value,
        data->format.precision_value,
        data->format.left_justify);
}
