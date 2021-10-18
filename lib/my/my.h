/*
** EPITECH PROJECT, 2021
** Live-Astek-Linked-List
** File description:
** my
*/

#pragma once

typedef struct linked_list{
    void *data;
    struct linked_list *next;
} linked_list_t;

linked_list_t *add_list(void *data, linked_list_t *list);
void print_list(linked_list_t *head);
int len_list(linked_list_t *head);