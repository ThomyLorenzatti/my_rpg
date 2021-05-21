/*
** EPITECH PROJECT, 2020
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include <my.h>

void choose_func(va_list ap, char c)
{
    if (c == 'd' || c == 'i')
        my_put_nbr(va_arg(ap, int));
    if (c == 'c')
        my_putchar(va_arg(ap, int));
    if (c == 's')
        my_putstr(va_arg(ap, char *));
}

void my_printf(char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] != '%')
            my_putchar(str[i]);
        else {
            choose_func(ap, str[i + 1]);
            i++;
        }
    }
    va_end(ap);
}