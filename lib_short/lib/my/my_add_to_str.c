/*
** EPITECH PROJECT, 2020
** add_str
** File description:
** add_str
*/

#include <my.h>
#include <stdlib.h>

char *my_add_to_str(char *str, char *add, int nb)
{
    int len = my_strlen(str);
    char *new_str = malloc(len + nb + 1);
    int i = 0;

    for (; str[i]; i++)
        new_str[i] = str[i];
    for (int j = 0; j < nb; j++)
        new_str[i + j] = add[j];
    new_str[len + nb] = 0;
    return (new_str);
}

char *my_add_char_to_str(char *str, char add)
{
    int len = my_strlen(str);
    char *new_str = my_malloc(len + 2);
    int i = 0;

    for (; str[i]; i++)
        new_str[i] = str[i];
    new_str[len] = add;
    new_str[len + 1] = 0;
    return (new_str);
}