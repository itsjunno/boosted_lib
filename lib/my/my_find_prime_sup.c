/*
** EPITECH PROJECT, 2025
** my_is_prime_sup
** File description:
** Function that finds the smallest bigger prime number
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    int answer = nb;

    while (my_is_prime(answer) == 0) {
        answer++;
    }
    return answer;
}
