/*
** EPITECH PROJECT, 2025
** printing.c
** File description:
** functions used to print
*/

#include "../include/my.h"
#include "../include/my_ls.h"
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>

void print_long_format(char *path, char *name)
{
    struct stat sb;
    struct passwd *pwd;
    struct group *grp;

    if (lstat(path, &sb) == -1)
        return;
    print_permissions(sb.st_mode);
    my_printf(" %d ", sb.st_nlink);
    pwd = getpwuid(sb.st_uid);
    grp = getgrgid(sb.st_gid);
    my_printf("%s %s ", pwd ? pwd->pw_name : "", grp ? grp->gr_name : "");
    my_printf("%5d ", sb.st_size);
    print_time_formatted(sb.st_mtime);
    my_printf(" %s\n", name);
}

void print_entry(char *path, char *name, bool long_format)
{
    char full_path[1024];

    if (long_format) {
        my_strcpy(full_path, path);
        my_strcat(full_path, "/");
        my_strcat(full_path, name);
        print_long_format(full_path, name);
    } else {
        my_printf("%s\n", name);
    }
}

void free_entries(char **entries, int count)
{
    int i = 0;

    for (i = 0; i < count; i++)
        free(entries[i]);
    free(entries);
}

void print_all_entry(char *path, char **entries, int count, ls_options_t *opts)
{
    int i = 0;

    for (i = 0; i < count; i++) {
        print_entry(path, entries[i], opts->long_format);
        free(entries[i]);
    }
}
