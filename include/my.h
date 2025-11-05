/*
** EPITECH PROJECT, 2025
** include/my.h
** File description:
** includes functions
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdbool.h>
    #include "./my_struct.h"
    #include <stddef.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdbool.h>

// ===== libmy.a functions =====

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);

//======== my_printf parsing ==========

bool flag_checker(struct_data_t *data, int *index);
int my_printf(const char *format, ...);
bool parse_format(struct_data_t *data, int *pos);

//======== specifier handling ==========

int handle_string(struct_data_t *data);
int handle_char(struct_data_t *data);
int handle_nbr(struct_data_t *data);
int execute_specifier(struct_data_t *data);
int handle_scientific(struct_data_t *data);
int handle_float(struct_data_t *data);
int handle_percent(struct_data_t *data);
int handle_nbr(struct_data_t *data);
int handle_f_or_e(struct_data_t *data);
int handle_scientific_with_value(struct_data_t *data, double value);
int handle_float_with_value(struct_data_t *data, double value);
int handle_int_hex(struct_data_t *data);
int handle_nbr(struct_data_t *data);
int handle_unsigned_nbr(struct_data_t *data);
int my_put_unsigned_nbr(unsigned int nb);

//======== my_ls functions ========



#endif
