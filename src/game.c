/*
** EPITECH PROJECT, 2021
** Live-Astek-Linked-List
** File description:
** game
*/

#include "game.h"

#include <SFML/Graphics.h>
#include <stdlib.h>

void game_init(game_t *game)
{
    *game = (game_t){
        .window = sfRenderWindow_create(
            (sfVideoMode){1280, 720, 32},
            "TchouTchou",
            sfDefaultStyle,
            NULL),
        .texture_wagon = sfTexture_createFromFile("assets/tileset.png", NULL),
        .train = NULL};
}

void game_update(game_t *game) { train_update(game->train); }

#include <stdio.h>
void game_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeySpace) {
                train_add_wagon(&game->train, game->texture_wagon);
            }
            if (event.key.code == sfKeyA) {
                train_fiouufff(game->train);
            }
            if (event.key.code == sfKeyF) {
                train_crash_wagon(&game->train);
            }
        }
    }
}

void game_draw(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    train_draw(game->train, game->window);
    sfRenderWindow_display(game->window);
}

void game_end(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    while (game->train) {
        linked_list_t *node = list_pop(&game->train);

        wagon_destroy(node->data);
        free(node);
    }
    sfTexture_destroy(game->texture_wagon);
}
