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


int get_len(char const *str)
{
    int len;

    for (len = 0; str[len]; len++);
    return len;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht;
    linked_list_t **table;

    if (len <= 0 || hash == NULL)
        return NULL;
    ht = malloc(sizeof(hashtable_t));
    table = malloc(sizeof(linked_list_t *) * len);
    if (table == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        table[i] = NULL;
    ht->table = table;
    ht->len = len;
    ht->hash = hash;
    return ht;
}

int convert_char(char c, int i)
{
    char *chiffre[] = {
        "idaga HAMUS",
        "vieux",
        "whisky",
        "juger",
        "quota",
        "francium",
        "FUMOIRE",
        "JUKEBOX",
        "BLOND",
        "PORTEZ"
    };
    int index = i % 10;
    int index_letter = c % get_len(chiffre[index]);

    return chiffre[index][index_letter];
}

int hash(char *key, int)
{
    int res = 42;
    int len;

    if (key == NULL)
        return NULL;
    len = my_strlen(key) > 0 ? my_strlen(key) : 3;
    for (int i = 0; key[i]; i++){
        res = (res / len) % 10000000;
        res = res * convert_char(key[i], i);
    }
    return res;
}
