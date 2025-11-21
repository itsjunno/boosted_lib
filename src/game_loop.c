/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** Game loop and event handling
*/

#include "../Include/my_hunter.h"

void handle_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtMouseButtonPressed &&
            event.mouseButton.button == sfMouseLeft) {
            sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
            shoot_gun(&game->gun);
            check_duck_collision(game, pos);
        }
    }
}

void update_game(game_t *game, float delta_time)
{
    int alive_count = 0;
    int i;
    sfVector2i mouse_pos;

    for (i = 0; i < MAX_DUCKS; i++) {
        if (game->ducks[i].is_alive) {
            update_duck(&game->ducks[i], delta_time);
            animate_duck(&game->ducks[i]);
            alive_count++;
            if (game->ducks[i].position.x < -200 ||
                game->ducks[i].position.x > WINDOW_WIDTH + 200)
                game->ducks[i].is_alive = 0;
        }
    }
    if (alive_count < 3) {
        for (i = 0; i < MAX_DUCKS; i++) {
            if (!game->ducks[i].is_alive) {
                spawn_duck(game, i);
                break;
            }
        }
    }
    mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    update_gun(&game->gun, mouse_pos);
}

void render_game(game_t *game)
{
    int i;

    sfRenderWindow_clear(game->window, (sfColor){135, 206, 235, 255});
    if (game->bg_sprite)
        sfRenderWindow_drawSprite(game->window, game->bg_sprite, NULL);
    for (i = 0; i < MAX_DUCKS; i++) {
        if (game->ducks[i].is_alive)
            sfRenderWindow_drawSprite(game->window,
                game->ducks[i].sprite, NULL);
    }
    if (game->gun.sprite)
        sfRenderWindow_drawSprite(game->window, game->gun.sprite, NULL);
    if (game->score_text)
        sfRenderWindow_drawText(game->window, game->score_text, NULL);
    sfRenderWindow_display(game->window);
}

void game_loop(game_t *game)
{
    sfClock *delta_clock = sfClock_create();
    float delta_time;

    while (sfRenderWindow_isOpen(game->window)) {
        delta_time = sfTime_asSeconds(sfClock_restart(delta_clock));
        handle_events(game);
        update_game(game, delta_time);
        render_game(game);
    }
    sfClock_destroy(delta_clock);
}
