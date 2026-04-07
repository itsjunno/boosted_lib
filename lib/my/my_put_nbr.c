/*
** EPITECH PROJECT, 2025
** put nbr
** File description:
** displays any number given in argument
*/

#include <stdio.h>
#include "../../include/my.h"

static int my_power_ten(int power)
{
    int i = 0;
    int ten = 1;

    while (i < power) {
        ten = ten * 10;
        i++;
    }
    return ten;
}

static int my_isneg_at_my_sauce(int n)
{
    if (n >= 0) {
        return 0;
    } else {
        return 84;
    }
    return 0;
}

static int my_nbrlen(int n)
{
    int counter = 0;

    if (n == 0)
        return 1;
    if (my_isneg_at_my_sauce(n) == 84)
        n = -n;
    while (n != 0) {
        n = n / 10;
        counter++;
    }
    return counter;
}

int my_put_nbr(int nb)
{
    int i = my_nbrlen(nb) - 1;

    if (my_isneg_at_my_sauce(nb) == 84) {
        my_putchar('-');
        nb = -nb;
    }
    for (int i = my_nbrlen(nb) - 1; i != -1; i--) {
        my_putchar((char) ((nb / my_power_ten(i)) % 10) + '0');
    }
    return 0;
}
