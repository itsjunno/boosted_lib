/*
** EPITECH PROJECT, 2025
** my_putnbr.c
** File description:
** my put number
*/

#include "../../include/my.h"
#include <unistd.h>

static int length_nb(unsigned int nb)
{
    int i = 0;

    if (nb < 0)
        i = 1;
    for (; nb; i++) {
        nb = nb / 10;
    }
    return i;
}

static int cut_number(unsigned int nb)
{
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

int my_put_unsigned_nbr(unsigned int nb)
{
    cut_number(nb);
    return (length_nb(nb));
}
