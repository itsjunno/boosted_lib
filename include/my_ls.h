/*
** EPITECH PROJECT, 2025
** include/my_ls.h
** File description:
** Header file for my_ls
*/

#ifndef MY_LS_H_
    #define MY_LS_H_
    #include <stdbool.h>

// === Structure to hold ls options ===

typedef struct ls_options {
    bool long_format;      // -l flag
    bool show_hidden;      // -a flag
    bool reverse;          // -r flag
    bool recursive;        // -R flag
    bool sort_by_time;     // -t flag
} ls_options_t;

/* Function declarations */
void print_permissions(mode_t mode);
void print_time_formatted(time_t mtime);
void print_long_format(char *path, char *name);
int count_entries(DIR *dir, bool show_hidden);
int strcasecmp_custom(const char *s1, const char *s2);
void sort_entries(char **entries, int count, bool reverse);
char **read_entries(DIR *dir, bool show_hidden, int count);
void print_entry(char *path, char *name, bool long_format);
void free_entries(char **entries, int count);
void print_all_entry(char *path, char **entries, int count, ls_options_t *opts);
void list_directory(char *path, ls_options_t *opts);
void set_option(ls_options_t *opts, char flag);
void parse_flags(char *arg, ls_options_t *opts);
void parse_options(int argc, char **argv, ls_options_t *opts);
void process_arguments(int argc, char **argv, ls_options_t *opts);
void list_directory_recursive(char *path, ls_options_t *opts, bool first);

#endif
