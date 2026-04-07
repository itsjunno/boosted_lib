/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** concatenates two strings
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int j = 0;
    char string[my_strlen(dest) + my_strlen(src)];

    for (; dest[i] != '\0'; i++) {
        string[i] = dest[i];
    }
    while (j < n) {
        if (my_strlen(src) < j + 1) {
            string[i] = '\0';
            break;
        }
        string[i] = src[j];
        j++;
        i++;
    }
    string[i] = '\0';
    my_strcpy(dest, string);
    return (dest);
}
