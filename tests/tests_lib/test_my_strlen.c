/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_strlen, test_strlen)
{
    int v = my_strlen("hello");

    cr_assert_eq(v, 5);
}
