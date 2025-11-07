/*
** EPITECH PROJECT, 2025
** sort_by_time.c
** File description:
** Sort entries by modification time
*/

#include "../include/my.h"
#include "../include/my_ls.h"
#include <sys/stat.h>
#include <stdlib.h>

static void build_file_path(char *dest, char *dir, char *file)
{
    int i = 0;
    int j = 0;

    while (dir[i]) {
        dest[i] = dir[i];
        i++;
    }
    if (i > 0 && dest[i - 1] != '/') {
        dest[i] = '/';
        i++;
    }
    while (file[j]) {
        dest[i] = file[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

static time_t get_mtime(char *path, char *name)
{
    struct stat sb;
    char full_path[1024];

    build_file_path(full_path, path, name);
    if (lstat(full_path, &sb) == -1)
        return 0;
    return sb.st_mtime;
}

static void swap_entries(char **a, char **b)
{
    char *temp = *a;

    *a = *b;
    *b = temp;
}

static void swap_if_needed(char **entries, int j, char *path, bool reverse)
{
    time_t time1 = get_mtime(path, entries[j]);
    time_t time2 = get_mtime(path, entries[j + 1]);
    bool should_swap = false;

    if (!reverse && time1 < time2)
        should_swap = true;
    if (reverse && time1 > time2)
        should_swap = true;
    if (should_swap)
        swap_entries(&entries[j], &entries[j + 1]);
}

void sort_by_time(char *path, char **entries, int count, bool reverse)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++)
            swap_if_needed(entries, j, path, reverse);
    }
}
