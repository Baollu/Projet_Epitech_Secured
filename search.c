/*
** EPITECH PROJECT, 2024
** search
** File description:
** search
*/

#include <stdlib.h>
#include "my.h"
#include "my_macro.h"
#include "hashtable.h"

char *ht_search(hashtable_t *ht, char *key)
{
    linked_list_t *node;
    ht_data_t *data;

    if (ht == NULL || key == NULL)
        return NULL;
    node = ht->table[ht->hash(key, ht->len) % ht->len];
    if (node == NULL)
        return NULL;
    data = node->data;
    return data->value;
}
