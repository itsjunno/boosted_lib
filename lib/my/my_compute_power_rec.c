/*
** EPITECH PROJECT, 2025
** my_compute_power_rec.c
** File description:
** compute nb power p
*/

#include <limits.h>

static long int long_my_compute_power_rec(long int nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    return (nb * (long_my_compute_power_rec(nb, p - 1)));
}

int my_compute_power_rec(int nb, int p)
{
    if (long_my_compute_power_rec(nb, p) > INT_MAX)
        return 0;
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    return (nb * (my_compute_power_rec(nb, p - 1)));
}
