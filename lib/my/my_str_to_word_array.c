/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int count_space_in_str(char const *str)
{
    int nb_space = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (my_char_isalpha(str[i]) == 0){
            nb_space += 1;
        }
    }
    return nb_space;
}

char **my_str_to_word_array(char const *str)
{
    int length = count_space_in_str(str);
    char **address_array = malloc(sizeof(char *) * (length + 2));
    int start = 0;
    int word_count = 0;
    char *str_temp = malloc(sizeof(char) * (my_strlen(str) + 1));

    my_strcpy(str_temp, str);
    for (int i = 0; str_temp[i] != '\0'; i++){
        if (my_char_isalpha(str_temp[i]) == 0){
            str_temp[i] = '\0';
            address_array[word_count] = my_strdup(str_temp + start);
            start = i + 1;
            word_count += 1;
        }
    }
    address_array[word_count] = my_strdup(str_temp + start);
    address_array[length + 1] = NULL;
    return address_array;
}
