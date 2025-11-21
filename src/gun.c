/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** Gun management functions
*/

#include "../Include/my_hunter.h"

void shoot_gun(gun_t *gun)
{
    gun->is_shooting = 1;
    gun->frame = 0;
    sfClock_restart(gun->anim_clock);
}

void animate_gun(gun_t *gun)
{
    float elapsed;

    if (!gun->is_shooting)
        return;
    elapsed = sfTime_asSeconds(sfClock_getElapsedTime(gun->anim_clock));
    if (elapsed > SHOOT_ANIM_SPEED) {
        gun->frame++;
        if (gun->frame >= 5) {
            gun->is_shooting = 0;
            gun->frame = 0;
        }
        gun->rect.left = gun->frame * GUN_FRAME_WIDTH;
        gun->rect.top = 0;
        sfSprite_setTextureRect(gun->sprite, gun->rect);
        sfClock_restart(gun->anim_clock);
    }
}

void update_gun(gun_t *gun, sfVector2i mouse_pos)
{
    sfVector2f position;

    position.x = mouse_pos.x + 150;
    position.y = WINDOW_HEIGHT - (GUN_IDLE_Y * GUN_SCALE);
    sfSprite_setPosition(gun->sprite, position);
    animate_gun(gun);
}
