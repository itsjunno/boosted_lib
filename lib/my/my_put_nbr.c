/*
** EPITECH PROJECT, 2025
** my_putnbr.c
** File description:
** my put number
*/

#include "../../include/my.h"
#include <unistd.h>

static int length_nb(int nb)
{
    int i = 0;

    if (nb < 0)
        i = 1;
    for (i; nb; i++) {
        nb = nb / 10;
    }
    return i;
}

static int cut_number(int nb)
{
    if (nb <= -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        cut_number(-nb);
        return (0);
    }
    if (nb <= 9) {
        my_putchar(nb + 48);
        return (0);
    }
    cut_number(nb / 10);
    cut_number(nb % 10);
    return (0);
}

int my_putnbr(int nb)
{
    cut_number(nb);
    return (length_nb(nb));
}
