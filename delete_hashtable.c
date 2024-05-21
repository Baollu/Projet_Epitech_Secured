/*
** EPITECH PROJECT, 2023
** main
** File description:
** main template
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "my_macro.h"
#include "hashtable.h"

void delete_list(linked_list_t *begin)
{
    ht_data_t *Data;

    if (begin == NULL)
        return;
    delete_list(begin->next);
    Data = begin->data;
    free(Data->value);
    free(Data);
    free(begin);
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index;

    if (ht == NULL || key == NULL)
        return 0;
    index = ht->hash(key, ht->len) % ht->len;
    delete_list(ht->table[index]);
    ht->table[index] = NULL;
    return 0;
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++){
        delete_list(ht->table[i]);
    }
    free(ht->table);
    free(ht);
}
