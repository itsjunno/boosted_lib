/*
** EPITECH PROJECT, 2025
** specifier_handlers.c
** File description:
** Array of function pointers for different format specifiers
*/

#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/my_func_array.h"

int execute_specifier(struct_data_t *data)
{
    for (int i = 0; handlers[i].specifier != '\0'; i++) {
        if (handlers[i].specifier == data->format.specifier) {
            return handlers[i].fptr(data);
        }
    }
    return 0;
}
