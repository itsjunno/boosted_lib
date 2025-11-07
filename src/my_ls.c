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
#include "../include/my_macro.h"

static void sort_and_print(char *path, char **entries, int count,
    ls_options_t *opts)
{
    if (opts->sort_by_time)
        sort_by_time(path, entries, count, opts->reverse);
    else
        sort_entries(entries, count, opts->reverse);
    print_all_entry(path, entries, count, opts);
    free(entries);
}

int list_directory(char *path, ls_options_t *opts)
{
    DIR *dir = opendir(path);
    char **entries;
    int count;

    if (!dir) {
        perror("my_ls");
        return ERROR;
    }
    count = count_entries(dir, opts->show_hidden);
    closedir(dir);
    dir = opendir(path);
    if (!dir)
        return ERROR;
    entries = read_entries(dir, opts->show_hidden, count);
    closedir(dir);
    if (!entries)
        return ERROR;
    sort_and_print(path, entries, count, opts);
    return SUCCESS;
}

void my_ls_particular(int argc, ls_options_t *opts, int *return_value)
{
    if (argc == 1) {
        if (opts->recursive)
            *return_value = list_directory_recursive(".", opts, true);
        else
            *return_value = list_directory(".", opts);
    }
}

void my_ls_particular_2(int argc, char **argv, ls_options_t *opts, int *val)
{
    if (argv[1][0] == '-' && argc == 2) {
        if (opts->recursive)
            *val = list_directory_recursive(".", opts, true);
        else
            *val = list_directory(".", opts);
    }
}

int main(int argc, char **argv)
{
    ls_options_t opts;
    int return_value = 0;
    int check_value = 0;

    parse_options(argc, argv, &opts);
    if (opts.show_dir) {
        my_printf(".\n");
        return 0;
    }
    my_ls_particular(argc, &opts, &return_value);
    if (return_value == 84)
        check_value = 84;
    my_ls_particular_2(argc, argv, &opts, &return_value);
    if (return_value == 84)
        check_value = 84;
    return_value = process_arguments(argc, argv, &opts);
    if (return_value == 84)
        check_value = 84;
    return check_value;
}
