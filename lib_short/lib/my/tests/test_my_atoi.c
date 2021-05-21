/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_atoi, test_atoi)
{
    int v = my_atoi("123");

    cr_assert_eq(v, 123);
}

Test(my_atoi, test_atoi_2)
{
    int v = my_atoi("-123");

    cr_assert_eq(v, -123);
}