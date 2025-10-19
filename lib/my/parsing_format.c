/*
** EPITECH PROJECT, 2025
** parsing_format.c
** File description:
** ᕕ( ᐛ )ᕗ
*/

#include <stdarg.h>
#include <unistd.h>
#include "../../include/my_struct.h"
#include "../../include/my_macro.h"
#include "../../include/my.h"
#include <stdbool.h>

bool format_parser(struct_data_t *data)
{
    int index = 1;
    bool return_value = false;

    if (flag_checker(data, &index) == true) {
        return_value = true;
        *data->fmt_copy + (index - 1); 
    }
    if () {

    }
}
