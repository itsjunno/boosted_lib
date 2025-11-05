/*
** EPITECH PROJECT, 2025
** print_permissions.c
** File description:
** print perms
*/

#include "../include/my.h"
#include "../include/my_ls.h"
#include <sys/stat.h>

void print_permissions(mode_t mode)
{
    my_putchar((S_ISDIR(mode)) ? 'd' : '-');
    my_putchar((mode & S_IRUSR) ? 'r' : '-');
    my_putchar((mode & S_IWUSR) ? 'w' : '-');
    my_putchar((mode & S_IXUSR) ? 'x' : '-');
    my_putchar((mode & S_IRGRP) ? 'r' : '-');
    my_putchar((mode & S_IWGRP) ? 'w' : '-');
    my_putchar((mode & S_IXGRP) ? 'x' : '-');
    my_putchar((mode & S_IROTH) ? 'r' : '-');
    my_putchar((mode & S_IWOTH) ? 'w' : '-');
    my_putchar((mode & S_IXOTH) ? 'x' : '-');
}
