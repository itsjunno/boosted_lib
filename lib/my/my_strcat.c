/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** concatenates two strings
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char string[my_strlen(dest) + my_strlen(src)];

    while (dest[i] != '\0') {
        string[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        string[i] = src[j];
        j++;
        i++;
    }
    string[i] = '\0';
    my_strcpy(dest, string);
    return (dest);
}
