/*
** EPITECH PROJECT, 2024
** insert
** File description:
** insert
*/

#include <stdlib.h>
#include "my.h"
#include "my_macro.h"
#include "hashtable.h"


char *cpystr(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *dupstr(char const *src)
{
    char *str_cp;

    str_cp = malloc(sizeof(char) * (get_len(src) + 1));
    return cpystr(str_cp, src);
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    ht_data_t *data;
    int res;
    int index;

    if (ht == NULL || key == NULL || value == NULL)
        return 0;
    data = malloc(sizeof(ht_data_t));
    res = ht->hash(key, ht->len);
    index = (res % ht->len);
    data->value = my_strdup(value);
    data->key = res;
    push_to_list(&(ht->table[index]), data);
    return 0;
}
