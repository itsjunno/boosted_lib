/*
** EPITECH PROJECT, 2025
** my_ls.c
** File description:
** ls command implementation
*/

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/my_ls.h"

void list_directory(char *path, ls_options_t *opts)
{
    DIR *dir = opendir(path);
    char **entries;
    int count;

    if (!dir) {
        perror("my_ls");
        return;
    }
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
    print_all_entry(path, entries, count, opts);
    free(entries);
}

int main(int argc, char **argv)
{
    ls_options_t opts;

    parse_options(argc, argv, &opts);
    if (argc == 1) {
        list_directory(".", &opts);
        return 0;
    }
    if (argv[1][0] == '-' && argc == 2) {
        list_directory(".", &opts);
        return 0;
    }
    process_arguments(argc, argv, &opts);
    return 0;
}
