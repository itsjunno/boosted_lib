/*
** EPITECH PROJECT, 2025
** my_swap
** File description:
** Function that swaps the value of two integer a and b
*/

void my_swap(int *a, int *b)
{
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}
