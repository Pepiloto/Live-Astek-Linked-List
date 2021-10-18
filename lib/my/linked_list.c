/*
** EPITECH PROJECT, 2021
** Live-Astek-Linked-List
** File description:
** linked_list
*/

#include <stdlib.h>

#include "my_list.h"

void list_push(linked_list_t **list, void *data)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));

    if (!new_node) {
        return;
    }
    new_node->data = data;
    new_node->next = *list;
    *list = new_node;
}

linked_list_t *list_pop(linked_list_t **head)
{
    linked_list_t *tmp = *head;

    if (!*head) {
        return NULL;
    }
    *head = (*head)->next;
    return (tmp);
}

void list_apply(linked_list_t *head, void (*f)(void *))
{
    linked_list_t *current_node = head;

    while (current_node != NULL) {
        f(current_node->data);
        current_node = current_node->next;
    }
}

int list_size(linked_list_t *head)
{
    int len = 0;
    linked_list_t *current_node = head;

    while (current_node != NULL) {
        ++len;
        current_node = current_node->next;
    }
    return len;
}
