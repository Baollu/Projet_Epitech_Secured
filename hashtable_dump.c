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

void ht_dump(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++){
        my_putstr("[");
        my_put_nbr(i);
        my_putstr("]:\n");
        display_list(ht->table[i], &display_node);
    }
}
