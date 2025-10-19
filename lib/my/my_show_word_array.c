/*
** EPITECH PROJECT, 2025
** my_show_word_array.c
** File description:
** show word array
*/

#include "../../include/my.h"

int my_show_word_array(char *const *tab)
{
    if (!*tab)
        return 0;
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
    }
    return 0;
}
