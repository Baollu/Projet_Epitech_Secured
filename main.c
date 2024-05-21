/*
** EPITECH PROJECT, 2023
** main
** File description:
** main template
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/hashtable.h"

int main(void)
{
    hashtable_t *table = new_hashtable(&hash, 5);

    ht_insert(table, "bidule", "bidule");
    ht_insert(table, "", "");
    ht_search(table, "");
    ht_delete(table, "");
    ht_insert(table, "machin", "machin");
    ht_dump(NULL);
    delete_hashtable(NULL);
    return 0;
}
