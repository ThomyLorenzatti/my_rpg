/*
** EPITECH PROJECT, 2020
** str_dup
** File description:
** str_dup
*/

#include <stdlib.h>
#include <my.h>

char *my_strdup(char *str)
{
    int i = 0;
    char *dup = NULL;

    for (; str[i]; i++);
    dup = my_malloc(sizeof(char) * (i + 1));
    dup[i] = 0;
    for (int j = 0; j < i; j++)
        dup[j] = str[j];
    return (dup);
}