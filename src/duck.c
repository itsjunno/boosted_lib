/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** Duck management functions
*/

#include "../Include/my_hunter.h"

void animate_duck(duck_t *duck)
{
    float elapsed;
    int row;
    int col;

    if (!duck->anim_clock)
        return;
    elapsed = sfTime_asSeconds(sfClock_getElapsedTime(duck->anim_clock));
    if (elapsed > ANIMATION_SPEED) {
        if (duck->is_hit) {
            duck->rect.left = CROW_FRAME_WIDTH * 3;
            duck->rect.top = CROW_FRAME_HEIGHT * 2;
        } else {
            duck->frame = (duck->frame + 1) % 8;
            row = duck->frame / 4;
            col = duck->frame % 4;
            duck->rect.left = col * CROW_FRAME_WIDTH;
            duck->rect.top = row * CROW_FRAME_HEIGHT;
        }
        sfSprite_setTextureRect(duck->sprite, duck->rect);
        sfClock_restart(duck->anim_clock);
    }
}

void update_duck(duck_t *duck, float delta_time)
{
    if (duck->is_hit) {
        duck->hit_timer += delta_time;
        duck->velocity.y += 500.0f * delta_time;
        if (duck->hit_timer > 1.0f ||
            duck->position.y > WINDOW_HEIGHT + 200)
            duck->is_alive = 0;
    }
    duck->position.x += duck->velocity.x * delta_time;
    duck->position.y += duck->velocity.y * delta_time;
    sfSprite_setPosition(duck->sprite, duck->position);
}

void update_score_display(game_t *game)
{
    char score_str[50];

    snprintf(score_str, sizeof(score_str), "Score: %d", game->score);
    sfText_setString(game->score_text, score_str);
}

void check_duck_collision(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect duck_bounds;
    sfVector2f mouse_float = {mouse_pos.x, mouse_pos.y};
    int i;

    for (i = 0; i < MAX_DUCKS; i++) {
        if (game->ducks[i].is_alive && !game->ducks[i].is_hit) {
            duck_bounds = sfSprite_getGlobalBounds(game->ducks[i].sprite);
            if (sfFloatRect_contains(&duck_bounds,
                mouse_float.x, mouse_float.y)) {
                game->ducks[i].is_hit = 1;
                game->ducks[i].velocity.x = 0;
                game->ducks[i].velocity.y = 0;
                game->score += 10;
                update_score_display(game);
            }
        }
    }
}
