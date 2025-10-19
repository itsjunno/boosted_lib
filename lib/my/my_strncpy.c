/*
** EPITECH PROJECT, 2025
** my_strncpy.c
** File description:
** Function that copies a string
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int size = my_strlen(src);

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > size) {
        dest[i] = '\0';
    }
    return dest;
}
