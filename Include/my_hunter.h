/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** Header file for my_hunter project
*/

#ifndef MY_HUNTER_H
    #define MY_HUNTER_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include <math.h>

    #define WINDOW_WIDTH 1280
    #define WINDOW_HEIGHT 720
    #define FRAME_RATE 60
    #define MAX_DUCKS 5
    #define DUCK_SPEED 200.0f
    #define ANIMATION_SPEED 0.08f
    #define CROW_FRAME_WIDTH 697
    #define CROW_FRAME_HEIGHT 800
    #define CROW_SCALE 0.15f
    #define GUN_FRAME_WIDTH 133
    #define GUN_FRAME_HEIGHT 280
    #define GUN_SCALE 1.5f
    #define SHOOT_ANIM_SPEED 0.08f
    #define GUN_IDLE_Y 167

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

typedef struct gun_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *anim_clock;
    int frame;
    int is_shooting;
} gun_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    sfTexture *duck_texture;
    sfClock *game_clock;
    duck_t ducks[MAX_DUCKS];
    gun_t gun;
    sfFont *font;
    sfText *score_text;
    int score;
    int active_ducks;
} game_t;

void display_help(void);
game_t *init_game(void);
void init_window(game_t *game);
void init_textures(game_t *game);
void init_gun(game_t *game);
void init_ducks(game_t *game);
void init_ui(game_t *game);
void spawn_duck(game_t *game, int index);
void animate_duck(duck_t *duck);
void update_duck(duck_t *duck, float delta_time);
void check_duck_collision(game_t *game, sfVector2i mouse_pos);
void update_gun(gun_t *gun, sfVector2i mouse_pos);
void shoot_gun(gun_t *gun);
void animate_gun(gun_t *gun);
void handle_events(game_t *game);
void update_game(game_t *game, float delta_time);
void render_game(game_t *game);
void game_loop(game_t *game);
void cleanup_game(game_t *game);
void update_score_display(game_t *game);

#endif
