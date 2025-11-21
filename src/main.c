/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** Main file for my_hunter project
*/

#include "../Include/my_hunter.h"

void display_help(void)
{
    printf("MY_HUNTER - Crow Hunt Game\n\n");
    printf("DESCRIPTION:\n");
    printf("    A Duck Hunt inspired game where you shoot crows.\n");
    printf("    Click on the crows to shoot them and score!\n\n");
    printf("USAGE:\n");
    printf("    ./my_hunter\n");
    printf("    ./my_hunter -h (display this help)\n\n");
    printf("CONTROLS:\n");
    printf("    Mouse Movement - Aim shotgun\n");
    printf("    Mouse Click - Shoot\n");
    printf("    ESC or Close Window - Exit game\n\n");
    printf("GAMEPLAY:\n");
    printf("    - Crows fly across the screen\n");
    printf("    - Aim with your shotgun at the bottom\n");
    printf("    - Click to shoot and score points\n");
    printf("    - Each hit adds 10 points\n\n");
}

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
