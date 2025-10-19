/*
** EPITECH PROJECT, 2025
** my_isneg
** File description:
** Function that checks if an integer is positive of negative
*/

#include "../../include/my.h"

int my_isneg(int number)
{
    if (number >= 0) {
        my_putchar(80);
    } else {
        my_putchar(78);
    }
    return 0;
}
