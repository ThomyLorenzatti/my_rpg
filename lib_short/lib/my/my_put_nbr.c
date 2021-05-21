/*
** EPITECH PROJECT, 2020
** put_nbr
** File description:
** put_nbr
*/

#include <my.h>

void my_put_nbr(int nb)
{
    char *str_nb = my_unatoi(nb);

    my_putstr(str_nb);
}