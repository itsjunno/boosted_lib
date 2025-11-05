/*
** EPITECH PROJECT, 2025
** time_utils.c
** File description:
** yay
*/

#include "../include/my.h"
#include "../include/my_ls.h"
#include <time.h>

void print_time_formatted(time_t mtime)
{
    char *time_str = ctime(&mtime);
    int i = 4;

    for (i = 4; i < 16; i++)
        my_putchar(time_str[i]);
}
