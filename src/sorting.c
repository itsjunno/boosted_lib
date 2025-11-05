/*
** EPITECH PROJECT, 2025
** sorting.c
** File description:
** all functions for sorting
*/

#include "../include/my.h"
#include "../include/my_ls.h"
#include <stdlib.h>

static char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int strcasecmp_custom(const char *s1, const char *s2)
{
    char c1;
    char c2;

    while (*s1 && *s2) {
        c1 = to_lower(*s1);
        c2 = to_lower(*s2);
        if (c1 != c2)
            return c1 - c2;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

static void swap_entries(char **a, char **b)
{
    char *temp = *a;

    *a = *b;
    *b = temp;
}

static bool should_swap(int cmp, bool reverse)
{
    if (cmp > 0 && !reverse)
        return true;
    if (cmp < 0 && reverse)
        return true;
    return false;
}

static void swapper(char **entries, int j, bool swap_needed)
{
    if (swap_needed)
        swap_entries(&entries[j], &entries[j + 1]);
}

void sort_entries(char **entries, int count, bool reverse)
{
    int i = 0;
    int j = 0;
    int cmp = 0;
    bool swap_needed = false;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            cmp = strcasecmp_custom(entries[j], entries[j + 1]);
            swap_needed = should_swap(cmp, reverse);
            swapper(entries, j, swap_needed);
        }
    }
}
