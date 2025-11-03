/*
** EPITECH PROJECT, 2025
** handle_scientific
** File description:
** handles the %f and %F
*/

#include <stdarg.h>
#include <stdbool.h>
#include "../../include/my.h"

#include <stdarg.h>
#include <stdbool.h>
#include "../../include/my.h"

static void print_sign(struct_data_t *data, double value)
{
    if (value < 0) {
        my_putchar('-');
        return;
    }
    if (data->format.plus) {
        my_putchar('+');
        return;
    }
    if (data->format.space)
        my_putchar(' ');
}

static void print_float_number(struct_data_t *data, double value)
{
    int precision = (data->format.precision_value < 0) ? 6 :
        data->format.precision_value;
    long int_part;
    double frac_part;
    int digit;

    if (value < 0)
        value = -value;
    int_part = (long)value;
    frac_part = value - int_part;
    my_put_nbr(int_part);
    if (precision > 0 || data->format.hash) {
        my_putchar('.');
        for (int i = 0; i < precision; i++) {
            frac_part *= 10.0;
            digit = (int)frac_part;
            my_putchar(digit + '0');
            frac_part -= digit;
        }
    }
}

static void print_float_formatted(struct_data_t *data, double value)
{
    print_sign(data, value);
    print_float_number(data, value);
}

static int calculate_float_length(struct_data_t *data, double value)
{
    int precision = (data->format.precision_value < 0) ? 6 :
        data->format.precision_value;
    int len = 0;
    long int_part;

    if (value < 0 || data->format.plus || data->format.space)
        len++;
    if (value < 0)
        value = -value;
    int_part = (long)value;
    if (int_part == 0)
        len++;
    while (int_part > 0) {
        len++;
        int_part /= 10;
    }
    if (precision > 0 || data->format.hash)
        len += 1 + precision;
    return len;
}

static void print_padding_chars(int count)
{
    for (int i = 0; i < count; i++)
        my_putchar(' ');
}

int handle_float_with_value(struct_data_t *data, double value)
{
    int output_len = calculate_float_length(data, value);
    int padding = (data->format.width_value > output_len) ?
        data->format.width_value - output_len : 0;

    if (!data->format.left_justify)
        print_padding_chars(padding);
    print_float_formatted(data, value);
    if (data->format.left_justify)
        print_padding_chars(padding);
    return output_len + padding;
}

int handle_float(struct_data_t *data)
{
    double value = va_arg(data->ap, double);

    return handle_float_with_value(data, value);
}
