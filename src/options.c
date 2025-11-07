/*
** EPITECH PROJECT, 2025
** options.c
** File description:
** handles options
*/

#include "../include/my.h"
#include "../include/my_ls.h"

void set_option(ls_options_t *opts, char flag)
{
    if (flag == 'l')
        opts->long_format = true;
    if (flag == 'a')
        opts->show_hidden = true;
    if (flag == 'r')
        opts->reverse = true;
    if (flag == 'R')
        opts->recursive = true;
    if (flag == 't')
        opts->sort_by_time = true;
    if (flag == 'd')
        opts->show_dir = true;
}

void parse_flags(char *arg, ls_options_t *opts)
{
    int j = 1;

    while (arg[j]) {
        set_option(opts, arg[j]);
        j++;
    }
}

void parse_options(int argc, char **argv, ls_options_t *opts)
{
    int i = 1;

    opts->long_format = false;
    opts->show_hidden = false;
    opts->reverse = false;
    opts->recursive = false;
    opts->sort_by_time = false;
    opts->show_dir = false;
    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-')
            parse_flags(argv[i], opts);
    }
}

static int process_single_arg(char *arg, ls_options_t *opts)
{
    if (opts->recursive)
        return list_directory_recursive(arg, opts, true);
    else
        return list_directory(arg, opts);
}

int process_arguments(int argc, char **argv, ls_options_t *opts)
{
    int i = 1;
    int return_value = 0;
    int check_value = 0;

    for (i = 1; i < argc; i++) {
        if (argv[i][0] != '-')
            return_value = process_single_arg(argv[i], opts);
        if (return_value == 84)
            check_value = 84;
    }
    return check_value;
}
