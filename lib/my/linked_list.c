/*
** EPITECH PROJECT, 2021
** Live-Astek-Linked-List
** File description:
** linked_list
*/

#include "my.h"
#include <stdlib.h>

linked_list_t *add_list(void *data, linked_list_t *list)
{
    linked_list_t *new_node = NULL;

    new_node = malloc(sizeof(linked_list_t));
    new_node->data = data;
    new_node->next = list;
    return (new_node);
}

void print_list(linked_list_t *head)
{
    linked_list_t *current_node = head;

    while (current_node != NULL) {
        printf("It prints\n");
        current_node = current_node->next;
    }
}

int len_list(linked_list_t *head)
{
    int len = 0;
    linked_list_t *current_node = head;

    while (current_node != NULL) {
        ++len;
        current_node = current_node->next;
    }
}