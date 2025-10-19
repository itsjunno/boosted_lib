/*
** EPITECH PROJECT, 2025
** my_revstr.c
** File description:
** reverse a string
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int start = 0;
    int end = my_strlen(str) - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return str;
}
