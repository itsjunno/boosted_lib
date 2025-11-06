/*
** EPITECH PROJECT, 2025
** recursive.c
** File description:
** recursive directory listing
*/

#include "../include/my.h"
#include "../include/my_ls.h"
#include <sys/stat.h>
#include <stdlib.h>

static bool is_special_dir(char *name)
{
    if (name[0] == '.' && name[1] == '\0')
        return true;
    if (name[0] == '.' && name[1] == '.' && name[2] == '\0')
        return true;
    return false;
}

static bool is_directory(char *path)
{
    struct stat sb;

    if (lstat(path, &sb) == -1)
        return false;
    return S_ISDIR(sb.st_mode);
}

static void build_full_path(char *dest, char *dir, char *name)
{
    int i = 0;
    int j = 0;

    while (dir[i]) {
        dest[i] = dir[i];
        i++;
    }
    dest[i] = '/';
    i++;
    while (name[j]) {
        dest[i] = name[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

void list_directory_recursive(char *path, ls_options_t *opts, bool first)
{
    DIR *dir;
    char **entries;
    int count;
    int i = 0;
    char full_path[1024];

    if (!first) {
        my_printf("\n%s:\n", path);
    }
    list_directory(path, opts);
    if (!opts->recursive)
        return;
    dir = opendir(path);
    if (!dir)
        return;
    count = count_entries(dir, opts->show_hidden);
    closedir(dir);
    dir = opendir(path);
    if (!dir)
        return;
    entries = read_entries(dir, opts->show_hidden, count);
    closedir(dir);
    if (!entries)
        return;
    sort_entries(entries, count, opts->reverse);
    for (i = 0; i < count; i++) {
        if (!is_special_dir(entries[i])) {
            build_full_path(full_path, path, entries[i]);
            if (is_directory(full_path))
                list_directory_recursive(full_path, opts, false);
        }
        free(entries[i]);
    }
    free(entries);
}