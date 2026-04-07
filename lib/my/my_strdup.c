/*
** EPITECH PROJECT, 2025
** my_strdup.c
** File description:
** duplicates a string then return the duplicated pointer
*/

#include <stddef.h>
#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *str;
    char *temp;

    if (src == NULL)
        return NULL;
    if (*src == '\0') {
        str = malloc(sizeof(char) * 1);
        return str;
    }
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    temp = str;
    while (*src) {
        *temp = *src;
        src++;
        temp++;
    }
    *temp = '\0';
    return str;
}
