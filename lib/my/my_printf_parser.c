/*
** EPITECH PROJECT, 2025
** my_printf_parser.c
** File description:
** Simple printf parser using struct_data_t
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "../../include/my_struct.h"
#include "../../include/my.h"

static void init_format(struct_data_t *data)
{
    data->format.left_justify = false;
    data->format.plus = false;
    data->format.space = false;
    data->format.hash = false;
    data->format.zero_padding = false;
    data->format.specifier = '\0';
    data->format.precision_value = -1;
    data->format.width_value = 0;
}

static void assign_flag(struct_data_t *data, char c)
{
    switch (c) {
        case '-':
            data->format.left_justify = true;
            break;
        case '+':
            data->format.plus = true;
            break;
        case ' ':
            data->format.space = true;
            break;
        case '#':
            data->format.hash = true;
            break;
        case '0':
            data->format.zero_padding = true;
            break;
    }
}

static void parse_flags(struct_data_t *data, int *pos)
{
    char c;

    while (data->fmt_copy[*pos] != '\0') {
        c = data->fmt_copy[*pos];
        if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0') {
            assign_flag(data, c);
            (*pos)++;
        } else {
            break;
        }
    }
}

static void parse_width(struct_data_t *data, int *pos)
{
    while (data->fmt_copy[*pos] >= '0' && data->fmt_copy[*pos] <= '9') {
        data->format.width_value = data->format.width_value * 10 +
            (data->fmt_copy[*pos] - '0');
        (*pos)++;
    }
}

static void while_precision(struct_data_t *data, int *pos)
{
    while (data->fmt_copy[*pos] >= '0' && data->fmt_copy[*pos] <= '9') {
        data->format.precision_value = data->format.precision_value * 10 +
            (data->fmt_copy[*pos] - '0');
        (*pos)++;
    }
}

static void parse_precision(struct_data_t *data, int *pos)
{
    if (data->fmt_copy[*pos] == '.') {
        (*pos)++;
        data->format.precision_value = 0;
        if (data->fmt_copy[*pos] >= '0' && data->fmt_copy[*pos] <= '9') {
            while_precision(data, pos);
        }
    }
}

static bool parse_specifier(struct_data_t *data, int *pos)
{
    char valid[] = "diuoxXfFeEgGcspn%";

    for (int i = 0; valid[i] != '\0'; i++) {
        if (data->fmt_copy[*pos] == valid[i]) {
            data->format.specifier = data->fmt_copy[*pos];
            (*pos)++;
            return true;
        }
    }
    return false;
}

bool parse_format(struct_data_t *data, int *pos)
{
    int start_pos = *pos;

    if (data->fmt_copy[*pos] != '%')
        return false;
    (*pos)++;
    init_format(data);
    parse_flags(data, pos);
    parse_width(data, pos);
    parse_precision(data, pos);
    if (!parse_specifier(data, pos)) {
        *pos = start_pos;
        return false;
    }
    return true;
}
