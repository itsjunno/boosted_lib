/*
** EPITECH PROJECT, 2025
** handle_float_hex.c
** File description:
** 凸( •̀_•́ )凸
*/

#include <stdarg.h>
#include <stdbool.h>
#include "../../include/my.h"

static void print_hex_digit(int digit, bool uppercase)
{
    if (digit < 10)
        my_putchar(digit + '0');
    else if (uppercase)
        my_putchar(digit - 10 + 'A');
    else
        my_putchar(digit - 10 + 'a');
}

static int count_hex_digits(unsigned int value)
{
    int count = 0;

    if (value == 0)
        return 1;
    while (value > 0) {
        count++;
        value /= 16;
    }
    return count;
}

static void print_hex_value(unsigned int value, bool uppercase)
{
    if (value >= 16)
        print_hex_value(value / 16, uppercase);
    print_hex_digit(value % 16, uppercase);
}

static void print_prefix(struct_data_t *data)
{
    bool uppercase = (data->format.specifier == 'X');

    if (!data->format.hash)
        return;
    my_putchar('0');
    my_putchar(uppercase ? 'X' : 'x');
}

static void print_sign(struct_data_t *data, unsigned int value)
{
    (void)data;
    (void)value;
}

static int calculate_hex_length(struct_data_t *data, unsigned int value)
{
    int len = count_hex_digits(value);

    if (data->format.hash && value != 0)
        len += 2;
    return len;
}

static void print_padding(int count, char pad_char)
{
    for (int i = 0; i < count; i++)
        my_putchar(pad_char);
}

static void print_hex_formatted(struct_data_t *data, unsigned int value)
{
    bool uppercase = (data->format.specifier == 'X');
    int num_len = count_hex_digits(value);
    int prefix_len = (data->format.hash && value != 0) ? 2 : 0;
    int total_len = prefix_len + num_len;
    int padding = (data->format.width_value > total_len) ?
        data->format.width_value - total_len : 0;

    if (!data->format.left_justify && !data->format.zero_padding)
        print_padding(padding, ' ');
    if (value != 0)
        print_prefix(data);
    if (!data->format.left_justify && data->format.zero_padding)
        print_padding(padding, '0');
    print_hex_value(value, uppercase);
    if (data->format.left_justify)
        print_padding(padding, ' ');
}

int handle_int_hex(struct_data_t *data)
{
    unsigned int value = va_arg(data->ap, unsigned int);
    int output_len = calculate_hex_length(data, value);
    int padding = (data->format.width_value > output_len) ?
        data->format.width_value - output_len : 0;

    print_hex_formatted(data, value);
    return output_len + padding;
}
