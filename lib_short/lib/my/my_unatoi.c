/*
** EPITECH PROJECT, 2020
** unatoy
** File description:
** unatoy
*/

#include <my.h>
#include <stdlib.h>

char *my_unatoi(int nb)
{
    int neg = nb < 0 ? 1 : 0;
    char *str_nb = NULL;
    int i = (nb == 0) ? 1 : 0;
    int k = 1;

    if (nb < 0)
        for (int temp = nb; temp < 0; temp /= 10, i++);
    else
        for (int temp = nb; temp > 0; temp /= 10, i++);
    str_nb = my_malloc(i + 1 + neg);
    str_nb[i + neg] = 0;
    str_nb[0] = '0';
    for (int j = 0; j < i; j++) {
        for (int g = i - j - 1; g > 0; k *= 10, g--);
        k = (neg == 1) ? ((nb / k % 10) * -1) + 48 : (nb / k % 10) + 48;
        str_nb[j + neg] = k;
        k = 1;
    }
    neg == 1 ? str_nb[0] = '-' : str_nb[0];
    return (str_nb);
}