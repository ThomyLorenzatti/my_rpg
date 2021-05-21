/*
** EPITECH PROJECT, 2020
** putstr
** File description:
** putstr
*/

#include <unistd.h>

void my_putstr(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    write(1, str, i);
}