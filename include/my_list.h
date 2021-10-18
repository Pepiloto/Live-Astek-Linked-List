/*
** EPITECH PROJECT, 2021
** Live-Astek-Linked-List
** File description:
** my
*/

#pragma once

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

void list_push(linked_list_t **list, void *data);
void list_apply(linked_list_t *head, void (*f)(void *));
int list_size(linked_list_t *head);
linked_list_t *list_pop(linked_list_t **head);
