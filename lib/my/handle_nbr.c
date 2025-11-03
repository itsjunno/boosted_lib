/*
** EPITECH PROJECT, 2025
** flag
** File description:
** i
*/
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/my.h"
#include <stdio.h>

static int length_nb(int nb)
{
    int i = 0;

    if (nb < 0)
        i = 1;
    for (; nb; i++) {
        nb = nb / 10;
    }
    return i;
}

static void print_padding(int padding, bool zero_padding)
{
    char c = ' ';

    if (padding <= 0)
        return;
    if (zero_padding == true)
        c = '0';
    for (int i = 0; i < padding; i++)
        my_putchar(c);
}

static void case_left_justify(struct_data_t *data, int nb_print,
    int precision, int width)
{
    if (data->format.left_justify == true) {
        if (data->format.plus == true && nb_print > 0)
            my_putchar('+');
        print_padding(precision, true);
        my_put_nbr(nb_print);
        if (precision == 0 && data->format.plus == true)
            width -= 1;
        print_padding(width, data->format.zero_padding);
    }
}

static void case_no_left_justify(struct_data_t *data, int nb_print,
    int precision, int width)
{
    if (data->format.left_justify == false) {
        if (precision == 0 && data->format.plus == true)
            width -= 1;
        print_padding(width, data->format.zero_padding);
        print_padding(precision, true);
        if (data->format.plus == true && nb_print > 0)
            my_putchar('+');
        my_put_nbr(nb_print);
    }
}

int handle_nbr(struct_data_t *data)
{
    int nb_print = va_arg(data->ap, int);
    int len_nb = length_nb(nb_print);
    int precision = (len_nb < data->format.precision_value) ?
        data->format.precision_value - len_nb : 0;
    int width = (data->format.width_value > data->format.precision_value) ?
        data->format.width_value - precision - len_nb : 0;

    if (precision == 0 && width == 0) {
        if (data->format.plus == true && nb_print > 0)
            my_putchar('+');
        my_put_nbr(nb_print);
        return 1;
    }
    case_left_justify(data, nb_print, precision, width);
    case_no_left_justify(data, nb_print, precision, width);
    return 1;
}
