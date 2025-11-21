/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** Game initialization functions
*/

#include "../Include/my_hunter.h"

void init_window(game_t *game)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

    game->window = sfRenderWindow_create(mode,
        "My Hunter - Crow Edition", sfClose, NULL);
    if (!game->window)
        return;
    sfRenderWindow_setFramerateLimit(game->window, FRAME_RATE);
}

void init_textures(game_t *game)
{
    game->bg_texture = sfTexture_createFromFile(
        "assets/Ocean_1/1.png", NULL);
    if (!game->bg_texture)
        printf("Error: Could not load assets/Ocean_1/1.png\n");
    game->bg_sprite = sfSprite_create();
    if (game->bg_sprite && game->bg_texture) {
        sfSprite_setTexture(game->bg_sprite, game->bg_texture, sfTrue);
        sfVector2u bg_size = sfTexture_getSize(game->bg_texture);
        float scale_x = (float)WINDOW_WIDTH / bg_size.x;
        float scale_y = (float)WINDOW_HEIGHT / bg_size.y;
        sfSprite_setScale(game->bg_sprite, (sfVector2f){scale_x, scale_y});
    }
    game->duck_texture = sfTexture_createFromFile(
        "assets/CrowV2_Fly_01.png", NULL);
    if (!game->duck_texture)
        printf("Error: Could not load assets/CrowV2_Fly_01.png\n");
}

void init_gun(game_t *game)
{
    game->gun.texture = sfTexture_createFromFile(
        "assets/Gun Sprites/Sgun.png", NULL);
    if (!game->gun.texture)
        printf("Error: Could not load assets/Sgun.png\n");
    game->gun.sprite = sfSprite_create();
    game->gun.anim_clock = sfClock_create();
    game->gun.frame = 0;
    game->gun.is_shooting = 0;
    game->gun.rect = (sfIntRect){0, 0, GUN_FRAME_WIDTH, GUN_FRAME_HEIGHT};
    if (game->gun.sprite && game->gun.texture) {
        sfSprite_setTexture(game->gun.sprite, game->gun.texture, sfTrue);
        sfSprite_setTextureRect(game->gun.sprite, game->gun.rect);
        sfSprite_setScale(game->gun.sprite,
            (sfVector2f){GUN_SCALE, GUN_SCALE});
        sfSprite_setOrigin(game->gun.sprite,
            (sfVector2f){GUN_FRAME_WIDTH / 2, 0});
    }
}

void init_ui(game_t *game)
{
    game->font = sfFont_createFromFile(
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    if (!game->font)
        game->font = sfFont_createFromFile(
            "/usr/share/fonts/TTF/DejaVuSans.ttf");
    game->score_text = sfText_create();
    if (game->score_text && game->font) {
        sfText_setFont(game->score_text, game->font);
        sfText_setCharacterSize(game->score_text, 30);
        sfText_setFillColor(game->score_text, sfWhite);
        sfText_setPosition(game->score_text, (sfVector2f){10, 10});
        sfText_setOutlineColor(game->score_text, sfBlack);
        sfText_setOutlineThickness(game->score_text, 2);
        sfText_setString(game->score_text, "Score: 0");
    }
}

void spawn_duck(game_t *game, int index)
{
    int direction = rand() % 2;
    float y_pos = rand() % (WINDOW_HEIGHT - 300) + 50;

    game->ducks[index].is_alive = 1;
    game->ducks[index].is_hit = 0;
    game->ducks[index].hit_timer = 0;
    game->ducks[index].frame = 0;
    game->ducks[index].rect = (sfIntRect){0, 0,
        CROW_FRAME_WIDTH, CROW_FRAME_HEIGHT};
    if (direction == 0) {
        game->ducks[index].position = (sfVector2f){-150, y_pos};
        game->ducks[index].velocity = (sfVector2f){DUCK_SPEED, 0};
        sfSprite_setScale(game->ducks[index].sprite,
            (sfVector2f){CROW_SCALE, CROW_SCALE});
    } else {
        game->ducks[index].position = (sfVector2f){WINDOW_WIDTH + 150, y_pos};
        game->ducks[index].velocity = (sfVector2f){-DUCK_SPEED, 0};
        sfSprite_setScale(game->ducks[index].sprite,
            (sfVector2f){-CROW_SCALE, CROW_SCALE});
    }
    sfSprite_setPosition(game->ducks[index].sprite,
        game->ducks[index].position);
}

void init_ducks(game_t *game)
{
    int i;

    for (i = 0; i < MAX_DUCKS; i++) {
        game->ducks[i].sprite = sfSprite_create();
        game->ducks[i].anim_clock = sfClock_create();
        if (game->ducks[i].sprite && game->duck_texture)
            sfSprite_setTexture(game->ducks[i].sprite,
                game->duck_texture, sfTrue);
        game->ducks[i].is_alive = 0;
    }
    game->active_ducks = 0;
    for (i = 0; i < 3; i++)
        spawn_duck(game, i);
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->score = 0;
    game->game_clock = sfClock_create();
    init_window(game);
    if (!game->window) {
        free(game);
        return NULL;
    }
    init_textures(game);
    init_gun(game);
    init_ui(game);
    init_ducks(game);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    return game;
}
