/*
** EPITECH PROJECT, 2025
** handle_scientific
** File description:
** handles the %e and %E
*/

#include <stdarg.h>
#include <stdbool.h>
#include "../../include/my.h"

static int count_digits(int n)
{
    int count = 0;

    if (n == 0)
        return 1;
    if (n < 0)
        n = -n;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

static void print_exponent(int exponent, bool uppercase)
{
    char e = uppercase ? 'E' : 'e';

    my_putchar(e);
    if (exponent >= 0)
        my_putchar('+');
    if (exponent < 0) {
        my_putchar('-');
        exponent = -exponent;
    }
    if (exponent < 10)
        my_putchar('0');
    my_put_nbr(exponent);
}

static double normalize_number(double value, int *exponent)
{
    *exponent = 0;
    if (value == 0.0)
        return 0.0;
    if (value < 0)
        value = -value;
    while (value >= 10.0) {
        value /= 10.0;
        (*exponent)++;
    }
    while (value < 1.0) {
        value *= 10.0;
        (*exponent)--;
    }
    return value;
}

static void print_mantissa(double mantissa, int precision)
{
    int int_part = (int)mantissa;
    double frac_part = mantissa - int_part;
    int digit = 0;

    my_put_nbr(int_part);
    if (precision > 0)
        my_putchar('.');
    for (int i = 0; i < precision; i++) {
        frac_part *= 10.0;
        digit = (int)frac_part;
        my_putchar(digit + '0');
        frac_part -= digit;
    }
}

static int calculate_output_length(struct_data_t *data, double value)
{
    int len = 0;
    int precision = (data->format.precision_value < 0) ? 6 :
        data->format.precision_value;

    if (value < 0 || data->format.plus || data->format.space)
        len++;
    len += 1;
    if (precision > 0)
        len += 1 + precision;
    len += 4;
    return len;
}

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

static void print_scientific_value(struct_data_t *data, double value)
{
    int exponent;
    double mantissa;
    int precision = (data->format.precision_value < 0) ? 6 :
        data->format.precision_value;
    bool uppercase = (data->format.specifier == 'E');

    print_sign(data, value);
    if (value < 0)
        value = -value;
    mantissa = normalize_number(value, &exponent);
    print_mantissa(mantissa, precision);
    print_exponent(exponent, uppercase);
}

static void print_padding_chars(int count)
{
    for (int i = 0; i < count; i++)
        my_putchar(' ');
}

int handle_scientific(struct_data_t *data)
{
    double value = va_arg(data->ap, double);
    int output_len = calculate_output_length(data, value);
    int padding = (data->format.width_value > output_len) ?
        data->format.width_value - output_len : 0;

    if (!data->format.left_justify)
        print_padding_chars(padding);
    print_scientific_value(data, value);
    if (data->format.left_justify)
        print_padding_chars(padding);
    return output_len + padding;
}

int handle_scientific_with_value(struct_data_t *data, double value)
{
    int output_len = calculate_output_length(data, value);
    int padding = (data->format.width_value > output_len) ?
        data->format.width_value - output_len : 0;

    if (!data->format.left_justify)
        print_padding_chars(padding);
    print_scientific_value(data, value);
    if (data->format.left_justify)
        print_padding_chars(padding);
    return output_len + padding;
}
