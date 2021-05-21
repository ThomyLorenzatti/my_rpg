/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>
#include <stdlib.h>

Test(my_memset, test_memset)
{
    char *str = malloc(6);
    str = my_memset(str, '\0', 6);
    str = my_memset(str, 'a', 5);
    cr_assert_str_eq(str, "aaaaa");
}
