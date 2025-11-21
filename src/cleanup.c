/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** Cleanup and resource management
*/

#include "../Include/my_hunter.h"

void cleanup_game(game_t *game)
{
    int i;

    if (!game)
        return;
    for (i = 0; i < MAX_DUCKS; i++) {
        if (game->ducks[i].sprite)
            sfSprite_destroy(game->ducks[i].sprite);
        if (game->ducks[i].anim_clock)
            sfClock_destroy(game->ducks[i].anim_clock);
    }
    if (game->duck_texture)
        sfTexture_destroy(game->duck_texture);
    if (game->gun.sprite)
        sfSprite_destroy(game->gun.sprite);
    if (game->gun.texture)
        sfTexture_destroy(game->gun.texture);
    if (game->gun.anim_clock)
        sfClock_destroy(game->gun.anim_clock);
    if (game->bg_texture)
        sfTexture_destroy(game->bg_texture);
    if (game->bg_sprite)
        sfSprite_destroy(game->bg_sprite);
    if (game->score_text)
        sfText_destroy(game->score_text);
    if (game->font)
        sfFont_destroy(game->font);
    if (game->game_clock)
        sfClock_destroy(game->game_clock);
    if (game->window)
        sfRenderWindow_destroy(game->window);
    free(game);
}
