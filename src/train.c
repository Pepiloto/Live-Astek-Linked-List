/*
** EPITECH PROJECT, 2021
** Live-Astek-Linked-List
** File description:
** train
*/

#include "train.h"

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>

#include "game.h"

static const sfIntRect WAGON_TEXTURE_RECT = {
    .left = 128,
    .top = 160,
    .width = 16,
    .height = 16};

static const float FLOOR = 600.f;

wagon_t *wagon_create(sfVector2f position, sfTexture *texture)
{
    wagon_t *new = malloc(sizeof(wagon_t));

    if (!new) {
        return NULL;
    }
    *new = (wagon_t){
        .position = position,
        .sprite = sfSprite_create(),
        .velocity = 0.f,
        .is_fiouufff = false,
        .speed = 0.f,
        .timeout_begin = 0.f};
    if (!new->sprite)
        return (NULL);
    sfSprite_setTexture(new->sprite, texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, WAGON_TEXTURE_RECT);
    sfSprite_setPosition(new->sprite, new->position);
    sfSprite_setScale(new->sprite, (sfVector2f){5, 5});
    return (new);
}

void wagon_destroy(wagon_t *wagon)
{
    sfSprite_destroy(wagon->sprite);
    free(wagon);
}

void wagon_draw(wagon_t *wagon, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, wagon->sprite, NULL);
}

void train_add_wagon(linked_list_t **train, sfTexture *texture)
{
    wagon_t *wagon;
    wagon_t *new;

    if (not *train) {
        new = wagon_create((sfVector2f){.x = 0, .y = FLOOR}, texture);
    } else {
        wagon = (*train)->data;
        new = wagon_create(
            (sfVector2f){.x = wagon->position.x + 100, .y = FLOOR},
            texture);
    }
    list_push(train, new);
}

// #define LAMBDA(return_type, args, body) ({return_type __unnamed args body
// &__unnamed;})

void train_draw(linked_list_t *train, sfRenderWindow *window)
{
    list_apply(train, ({
                   void func(void *data)
                   {
                       wagon_t *wagon = data;
                       sfRenderWindow_drawSprite(window, wagon->sprite, NULL);
                   }
                   &func;
               }));
}

void wagon_fiouufff(wagon_t *wagon)
{
    if (wagon->timeout_begin > 0) {
        wagon->timeout_begin -= 1;
        return;
    }
    if (wagon->position.y > FLOOR) {
        wagon->is_fiouufff = false;
        return;
    }
    wagon->speed -= wagon->velocity;
    wagon->position.y -= wagon->speed;
}

void train_fiouufff(linked_list_t *train)
{
    int i = 0;

    list_apply(train, ({
                   void func(void *data)
                   {
                       wagon_t *wagon = data;

                       i += 1;
                       if (not wagon->is_fiouufff) {
                           wagon->is_fiouufff = true;
                           wagon->timeout_begin = i * 50;
                           wagon->velocity = 0.05;
                           wagon->speed = 7;
                           wagon->position.y = FLOOR - 0.1;
                       }
                   }
                   &func;
               }));
}

void train_update(linked_list_t *train)
{
    list_apply(train, ({
                   void func(void *data)
                   {
                       wagon_t *wagon = data;

                       if (wagon->is_fiouufff) {
                           wagon_fiouufff(wagon);
                       }
                       sfSprite_setPosition(wagon->sprite, wagon->position);
                   }
                   &func;
               }));
}
