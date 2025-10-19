/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <stdio.h>
#include "include/my.h"
#include <stdarg.h>
#include <stdbool.h>

int test(struct_data_t *data, ...)
{
    data->fmt_copy = "Hello";
    va_start(data->ap, data);
    data->char_written = 0;
    data->format.left_justify = true;
}

int main(void)
{
    struct_data_t data;

    test(&data, 45);
    printf("%s, %d\n", data.fmt_copy, data.format.left_justify);
    printf("%.310f\n", 10.123456);
}
