/*
** EPITECH PROJECT, 2025
** flag
** File description:
** c
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

int handle_char(struct_data_t *data)
{
    if (data->format.width_value <= 0) {
        my_putchar((char)va_arg(data->ap, int));
        return 1;
    }
    if (data->format.width_value > 0 &&
        data->format.left_justify == false) {
        print_padding(data->format.width_value - 1);
        my_putchar((char)va_arg(data->ap, int));
        return data->format.width_value;
    }
    if (data->format.width_value > 0 &&
        data->format.left_justify == true) {
        my_putchar((char)va_arg(data->ap, int));
        print_padding(data->format.width_value - 1);
        return data->format.width_value;
    }
    return 0;
}
