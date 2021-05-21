/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_malloc, test_my_malloc)
{
    char *str = my_malloc(2);
    str[0] = 'a';
    str[1] = 0;
}