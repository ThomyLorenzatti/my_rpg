/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_strdup, test_strdup)
{
    char *str = my_strdup("hello");

    cr_assert_str_eq(str, "hello");
}
