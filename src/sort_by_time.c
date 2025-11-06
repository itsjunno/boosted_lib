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

static time_t get_mtime(char *path, char *name)
{
    struct stat sb;
    char full_path[1024];
    int i = 0;
    int j = 0;

    while (path[i]) {
        full_path[i] = path[i];
        i++;
    }
    full_path[i] = '/';
    i++;
    while (name[j]) {
        full_path[i] = name[j];
        i++;
        j++;
    }
    full_path[i] = '\0';
    if (lstat(full_path, &sb) == -1)
        return 0;
    return sb.st_mtime;
}

static bool should_swap_time(time_t t1, time_t t2, bool reverse)
{
    if (t1 < t2 && !reverse)
        return true;
    if (t1 > t2 && reverse)
        return true;
    return false;
}

static void swap_entries(char **a, char **b)
{
    char *temp = *a;

    *a = *b;
    *b = temp;
}

void sort_by_time(char *path, char **entries, int count, bool reverse)
{
    int i = 0;
    int j = 0;
    time_t time1;
    time_t time2;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            time1 = get_mtime(path, entries[j]);
            time2 = get_mtime(path, entries[j + 1]);
            if (should_swap_time(time1, time2, reverse))
                swap_entries(&entries[j], &entries[j + 1]);
        }
    }
}
