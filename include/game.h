/*
** EPITECH PROJECT, 2021
** Live-Astek-Linked-List
** File description:
** game
*/

#pragma once

#include <iso646.h>

#include "my_list.h"
#include "train.h"

typedef struct game_s {
    sfTexture *texture_wagon;
    linked_list_t *train;
    sfRenderWindow *window;
} game_t;

void game_init(game_t *game);
void game_update(game_t *game);
void game_event(game_t *game);
void game_draw(game_t *game);
void game_end(game_t *game);
