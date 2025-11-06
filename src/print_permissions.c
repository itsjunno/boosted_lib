/*
** EPITECH PROJECT, 2025
** print_permissions.c
** File description:
** print perms with SUID, SGID, Sticky Bit
*/

#include "../include/my.h"
#include "../include/my_ls.h"
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <linux/stat.h>

static void print_user_execute(mode_t mode)
{
    if (mode & S_ISUID)
        my_putchar((mode & S_IXUSR) ? 's' : 'S');
    else
        my_putchar((mode & S_IXUSR) ? 'x' : '-');
}

static void print_group_execute(mode_t mode)
{
    if (mode & S_ISGID)
        my_putchar((mode & S_IXGRP) ? 's' : 'S');
    else
        my_putchar((mode & S_IXGRP) ? 'x' : '-');
}

static void print_other_execute(mode_t mode)
{
    if (mode & S_ISVTX)
        my_putchar((mode & S_IXOTH) ? 't' : 'T');
    else
        my_putchar((mode & S_IXOTH) ? 'x' : '-');
}

void print_permissions(mode_t mode)
{
    my_putchar((S_ISDIR(mode)) ? 'd' : '-');
    my_putchar((mode & S_IRUSR) ? 'r' : '-');
    my_putchar((mode & S_IWUSR) ? 'w' : '-');
    print_user_execute(mode);
    my_putchar((mode & S_IRGRP) ? 'r' : '-');
    my_putchar((mode & S_IWGRP) ? 'w' : '-');
    print_group_execute(mode);
    my_putchar((mode & S_IROTH) ? 'r' : '-');
    my_putchar((mode & S_IWOTH) ? 'w' : '-');
    print_other_execute(mode);
}
