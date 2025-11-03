/*
** EPITECH PROJECT, 2025
** handle_f_or_e.c
** File description:
** handles the flag %g and %G
*/

#include <stdarg.h>
#include <stdbool.h>
#include "../../include/my.h"

static int get_exponent(double value)
{
    int exponent = 0;

    if (value == 0.0)
        return 0;
    if (value < 0)
        value = -value;
    while (value >= 10.0) {
        value /= 10.0;
        exponent++;
    }
    while (value < 1.0) {
        value *= 10.0;
        exponent--;
    }
    return exponent;
}

static bool should_use_scientific(double value, int precision)
{
    int exponent = get_exponent(value);

    if (exponent < -4)
        return true;
    if (exponent >= precision)
        return true;
    return false;
}

static int count_decimal_places(double value)
{
    int count = 0;
    double frac_part;
    long int_part;

    if (value < 0)
        value = -value;
    int_part = (long)value;
    frac_part = value - int_part;
    while (frac_part > 0.000001 && count < 10) {
        frac_part *= 10.0;
        frac_part -= (long)frac_part;
        count++;
    }
    return count;
}

int handle_f_or_e(struct_data_t *data)
{
    double value = va_arg(data->ap, double);
    int precision = (data->format.precision_value < 0) ? 6 :
        data->format.precision_value;
    int decimal_places;

    if (precision == 0)
        precision = 1;
    if (should_use_scientific(value, precision)) {
        data->format.precision_value = precision - 1;
        data->format.specifier = (data->format.specifier == 'G') ? 'E' : 'e';
        return handle_scientific_with_value(data, value);
    }
    decimal_places = count_decimal_places(value);
    data->format.precision_value = decimal_places;
    return handle_float_with_value(data, value);
}
