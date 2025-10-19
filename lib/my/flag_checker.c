/*
** EPITECH PROJECT, 2025
** flag_checker.c
** File description:
** checks flags ᕕ( ᐛ )ᕗ
*/

#include "../../include/my.h"

static void assign_flag(struct_data_t *data, int index)
{
    if (index == 0) {
        data->format.left_justify = true;
    }
    if (index == 1) {
	data->format.plus = true;
    }
    if (index == 2) {
	data->format.space = true;
    }
    if (index == 3) {
	data->format.hash = true;
    }
    if (index == 4) {
	data->format.zero_padding = true;
    }
    return;
}

static bool check_flag(struct_data_t *data, char c)
{
    char *flags = {'-', '+', ' ', '\#', '0'};
    
    for (int i = 0; flags[i] != '\0'; i++) {
        if (flags[i] == c) {
            assign_flag(data, i);
            return true;
        }
    }
    return false;
}

bool flag_checker(struct_data_t *data, int *index)
{
    bool return_value = false;

    for(; data->fmt_copy[*index] != '\0' && ; *index++) {
        return_value = check_flag(data, data->fmt_copy[*index]);
        if (return_value == true)
            break;
    }
    return return_value;
}
