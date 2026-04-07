/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** Functions that displays one by one the characters of a string using putchar
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
