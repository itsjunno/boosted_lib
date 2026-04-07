/*
** EPITECH PROJECT, 2025
** my_sort_int_array.c
** File description:
** Sort int array
*/

#include "../../include/my.h"

static int compare_int(int *array, int small, int new)
{
    if (array[new] < array[small]) {
        return new;
    } else {
        return small;
    }
}

void my_sort_int_array(int *array, int size)
{
    int index_mini = 0;
    int temp = 0;

    for (int index = 0; index < size; index++) {
        index_mini = index;
        for (int alt_index = index; alt_index < size; alt_index++) {
            index_mini = compare_int(array, index_mini, alt_index);
        }
        my_swap(&array[index_mini], &array[index]);
    }
}
