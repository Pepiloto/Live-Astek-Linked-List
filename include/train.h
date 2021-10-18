/*
** EPITECH PROJECT, 2021
** Live-Astek-Linked-List
** File description:
** train
*/

#pragma once

#include <SFML/Graphics/Sprite.h>
#include <stdbool.h>
#include <stdlib.h>

#include "my_list.h"

typedef struct wagon_s {
    sfVector2f position;
    sfSprite *sprite;
    bool is_fiouufff;
    float velocity;
    float speed;
    float timeout_begin;
} wagon_t;

wagon_t *wagon_create(sfVector2f position, sfTexture *texture);
void wagon_destroy(wagon_t *wagon);
void wagon_draw(wagon_t *wagon, sfRenderWindow *window);
void train_add_wagon(linked_list_t **train, sfTexture *texture);
void train_draw(linked_list_t *train, sfRenderWindow *window);
void train_fiouufff(linked_list_t *train);
void train_update(linked_list_t *train);

static inline void train_crash_wagon(linked_list_t **train)
{
    linked_list_t *node = list_pop(train);

    if (!node) {
        return;
    }
    wagon_destroy((wagon_t *)node->data);
    free(node);
}
