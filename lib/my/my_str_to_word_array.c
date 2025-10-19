/*
** EPITECH PROJECT, 2025
** Day 08 - Task 04
** File description:
** Splits a string into words
*/

#include <stdlib.h>
#include "../../include/my.h"

static int is_alphanumerical(char c)
{
    return ('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') ||
        ('a' <= c && c <= 'z');
}

static char *extract_word(char const *tab, int word_pos, int *i)
{
    int size = my_strlen(tab);
    int word_len = 0;
    char *word;

    for (int j = word_pos; j < size && is_alphanumerical(tab[j]); j++)
        word_len++;
    *i += word_len;
    word = malloc(sizeof(char) * (word_len + 1));
    my_strncpy(word, tab + word_pos, word_len);
    return word;
}

static int count_words(char const *tab, int size)
{
    int count = 0;
    int started_word = is_alphanumerical(tab[0]);

    for (int i = 1; i < size; i++) {
        if (started_word && !is_alphanumerical(tab[i]))
            count++;
        started_word = is_alphanumerical(tab[i]);
    }
    return count;
}

char **my_str_to_word_array(char const *tab)
{
    char **result;
    int size = my_strlen(tab);
    int nb_word = count_words(tab, size);
    int curr_word = 0;

    result = malloc(sizeof(char *) * (nb_word + 2));
    for (int i = 0; i < size; i++){
        if (is_alphanumerical(tab[i])) {
            result[curr_word] = extract_word(tab, i, &i);
            curr_word++;
        }
    }
    result[curr_word] = NULL;
    return result;
}
