/*
** EPITECH PROJECT, 2025
** my_func_array.h
** File description:
** function array pointers for my_printf
*/

#ifndef MY_FUNC_ARRAY_H_
    #define MY_FUNC_ARRAY_H_
    #include "./my.h"

// === array of pointer to functions ===

const struct_flag_t handlers[] = {
    {'s', handle_string},
    {'c', handle_char},
    {'i', handle_nbr},
    {'d', handle_nbr},
    {'%', handle_percent},
    {'e', handle_scientific},
    {'E', handle_scientific},
    {'f', handle_float},
    {'g', handle_f_or_e},
    {'G', handle_f_or_e},
    {'x', handle_int_hex},
    {'X', handle_int_hex},
    {'u', handle_unsigned_nbr},
    {'\0', NULL}
};

#endif
