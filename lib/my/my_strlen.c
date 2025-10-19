/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** Function that return the amount of character inside a string type
*/

int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index++;
    }
    return index;
}
