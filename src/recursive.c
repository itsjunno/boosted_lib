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

    if (stat(path, &sb) == -1)
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
    if (i > 0 && dest[i - 1] != '/') {
        dest[i] = '/';
        i++;
    }
    while (name[j]) {
        dest[i] = name[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

static void process_entry(char *entry, char *path, ls_options_t *opts)
{
    char full_path[1024];

    if (!is_special_dir(entry)) {
        build_full_path(full_path, path, entry);
        if (is_directory(full_path)) {
            list_directory_recursive(full_path, opts, false);
        }
    }
}

static void process_entries(char **entries, int count,
    char *path, ls_options_t *opts)
{
    for (int i = 0; i < count; i++) {
        process_entry(entries[i], path, opts);
        free(entries[i]);
    }
}

static char **get_sorted_entries(char *path, ls_options_t *opts, int *count)
{
    DIR *dir = opendir(path);
    char **entries;

    if (!dir)
        return NULL;
    *count = count_entries(dir, opts->show_hidden);
    closedir(dir);
    dir = opendir(path);
    if (!dir)
        return NULL;
    entries = read_entries(dir, opts->show_hidden, *count);
    closedir(dir);
    if (!entries)
        return NULL;
    sort_entries(entries, *count, opts->reverse);
    return entries;
}

void list_directory_recursive(char *path, ls_options_t *opts, bool first)
{
    char **entries;
    int count;

    if (!first) {
        my_printf("\n%s:\n", path);
    }
    list_directory(path, opts);
    if (!opts->recursive)
        return;
    entries = get_sorted_entries(path, opts, &count);
    if (!entries)
        return;
    process_entries(entries, count, path, opts);
    free(entries);
}
