/*
** EPITECH PROJECT, 2025
** directory_ops.c
** File description:
** all directory operations
*/

#include "../include/my.h"
#include "../include/my_ls.h"
#include <dirent.h>
#include <stdlib.h>

int count_entries(DIR *dir, bool show_hidden)
{
    struct dirent *entry;
    int count = 0;

    entry = readdir(dir);
    while (entry != NULL) {
        if (show_hidden || entry->d_name[0] != '.')
            count++;
        entry = readdir(dir);
    }
    return count;
}

char **read_entries(DIR *dir, bool show_hidden, int count)
{
    struct dirent *entry;
    char **entries;
    int idx = 0;

    entries = malloc(sizeof(char *) * count);
    if (!entries)
        return NULL;
    entry = readdir(dir);
    while (entry != NULL) {
        if (show_hidden || entry->d_name[0] != '.') {
            entries[idx] = my_strdup(entry->d_name);
            idx++;
        }
        entry = readdir(dir);
    }
    return entries;
}
