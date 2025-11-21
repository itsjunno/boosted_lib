/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** Single file implementation with crow sprites
*/


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "Include/my_hunter.h"
#include "Include/my_macro.h"
#include "Include/my_struct.h"

int main(int argc, char **argv)
{
    game_t *game;
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        display_help();
        return 0;
    }
    srand(time(NULL));
    game = init_game();
    if (!game)
        return 84;
    game_loop(game);
    cleanup_game(game);
    return 0;
}
