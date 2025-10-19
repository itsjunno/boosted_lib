/*
** EPITECH PROJECT, 2025
** include/my.h
** File description:
** includes functions
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

#include <stdbool.h>
#include <stdarg.h>

typedef struct struct_format {
    bool left_justify;
    bool plus;
    bool space;
    bool hash;
    bool zero_padding;
    char specifier;
    int precision_value;
    int width_value;
} struct_format_t;

typedef struct struct_data {
    char *fmt_copy;
    va_list ap;
    int char_written;
    struct_format_t format;
} struct_data_t;

typedef struct struct_flag {
    char specifier;
    int (*fptr)(struct_data_t *);
} struct_flag_t;

#endif
