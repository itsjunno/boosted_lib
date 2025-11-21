/*
** EPITECH PROJECT, 2025
** include/my.h
** File description:
** includes functions
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include "my_macro.h"

typedef struct duck_s {
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f velocity;
    sfIntRect rect;
    sfClock *anim_clock;
    int frame;
    int is_alive;
    int is_hit;
    float hit_timer;
} duck_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    sfTexture *duck_texture;
    sfTexture *cursor_texture;
    sfSprite *cursor_sprite;
    sfFont *font;
    sfText *score_text;
    sfClock *game_clock;
    duck_t ducks[MAX_DUCKS];
    int score;
    int active_ducks;
    int bullets;
} game_t;

#endif
