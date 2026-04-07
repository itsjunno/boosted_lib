/*
** EPITECH PROJECT, 2025
** strn cmp
** File description:
** cool
*/

#include "../../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n == 0)
        return 0;
    n--;
    while (n && *s1 && *s1 == *s2) {
        s1++;
        s2++;
        --n;
    }
    if (n == 0)
        return ((*(unsigned char *)s1 - *(unsigned char *)s2));
}
