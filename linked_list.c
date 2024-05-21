/*
** EPITECH PROJECT, 2023
** main
** File description:
** main template
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "hashtable.h"

void display_node(void *data)
{
    ht_data_t *Data = data;

    my_putstr("> ");
    my_put_nbr(Data->key);
    my_putstr(" - ");
    my_putstr(Data->value);
    my_putstr("\n");
}

void display_list(linked_list_t *begin, void (*disp_fct)())
{
    if (begin == NULL)
        return;
    disp_fct(begin->data);
    display_list(begin->next, disp_fct);
}

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    node->data = data;
    node->next = *begin;
    *begin = node;
}
