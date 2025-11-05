/*
** EPITECH PROJECT, 2025
** options.c
** File description:
** handles options
*/

#include "../include/my.h"
#include "../include/my_ls.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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
    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-')
            parse_flags(argv[i], opts);
    }
}

bool count_directory(int argc, char **argv)
{
    struct stat stat_path;
    int count = 0;

    for (int i = 0; i <= argc; i++) {
        if (S_ISDIR(stat_path.st_mode))
            count++;
    }
    if (count > 1) {
        return true;
    } else {
        return false;
    }
}

void process_arguments(int argc, char **argv, ls_options_t *opts)
{
    int i = 1;
    bool multiple_dir = count_directory(argc, argv);

    for (i = 1; i < argc; i++) {
        if (argv[i][0] != '-')
            list_directory(argv[i], opts);
    }
}
