/*
** EPITECH PROJECT, 2025
** my_bs.c
** File description:
** my ls bs
*/


#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>
#include "include/my.h"
#include <sys/types.h>

void file_type(struct stat *sb)
{
    switch (sb->st_mode & S_IFMT) {
        case S_IFBLK:
            my_printf("b");
            break;
        case S_IFCHR:
            my_printf("c\n");
            break;
        case S_IFDIR:
            my_printf("directory\n");
            break;
        case S_IFIFO:
            my_printf("FIFO/pipe\n");
            break;
        case S_IFLNK:
            my_printf("symlink\n");
            break;
        case S_IFREG:
            my_printf("f\n");
            break;
     }
}

void handle_device(char **argv, bool device, struct stat *sb)
{
    lstat(argv[1], sb);
    if (device == true) {
        my_printf("Major: %d\n", major(sb->st_rdev));
        my_printf("Minor: %d\n", minor(sb->st_rdev));
    } else {
        my_printf("Major: N/A\n");
        my_printf("Minor: N/A\n");
    }
}

int handle_errors(int argc, char **argv, struct stat *sb)
{
    if (argc != 2) {
        write(1, "Usage: ", 7);
	my_printf("%s", argv[0]);
	my_printf(" <pathname>\n");
	return(EXIT_FAILURE);
    }
    if (lstat(argv[1], sb) == -1) {
	perror("lstat");
	return(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
    struct stat sb;
    bool device = false;

    if (handle_errors(argc, argv, &sb) == EXIT_FAILURE)
        return 84;
    lstat(argv[1], &sb);
    my_printf("Type: ");
    file_type(&sb);
    my_printf("Hard Link: %d\n", sb.st_nlink);
    my_printf("Inode: %d\n", sb.st_ino);
    my_printf("UID: %d\n", sb.st_uid);
    my_printf("GID: %d\n", sb.st_gid);
    my_printf("Size: %d\n", sb.st_size);
    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:
            device = true;
            break;
        case S_IFCHR:
            device = true;
            break;
    }
    handle_device(argv, device, &sb);
}
