/*
** EPITECH PROJECT, 2025
** my_getnbr.c*
** File description:
** Function that find a number within a string argument
*/

#include "../../include/my.h"

static int is_it_full_int(char const *str)
{
    int i = 0;

    if (str[i] == '-')
        i = 1;
    while (str[i] != '\0') {
        if (is_digit(str[i]) != 0)
            return 84;
        i++;
    }
    return 0;
}

static int checker(char const *str)
{
    char *string_max = "2147483647";
    int i = 0;

    if (str[0] == '-') {
        i = 1;
    }
    if (is_it_full_int(str) == 84)
        return 0;
    if (my_strlen(str) < my_strlen(string_max))
        return 0;
    if (my_strlen(str) > my_strlen(string_max))
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > string_max[i])
            return 84;
    }
    return -50;
}

static int my_converter(int index, char const *str)
{
    int number = 0;

    while (str[index] != '\0') {
        if (is_digit(str[index]) == 0) {
            number = number * 10 + (str[index] - 48);
        } else {
            break;
        }
        index++;
    }
    return number;
}

int my_getnbr(char const *str)
{
    int index = 0;
    int sign = 0;

    if (is_it_full_int(str) == 0 && checker(str) == 84)
        return 0;
    while (str[index] != '\0') {
        if (str[index] == '-' && is_digit(str[index + 1]) == 0) {
            sign = 1;
            break;
        }
        if (is_digit(str[index]) == 0) {
            break;
        }
        index++;
    }
    if (sign == 1) {
        return my_converter(index + 1, str) * -1;
    }
    return my_converter(index, str);
}
