/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_add_to_str, test_add_to_str)
{
    char *str = my_add_to_str("hello", "hello", 3);

    cr_assert_str_eq(str, "hellohel");
}

Test(my_add_char_to_str, test_add_char_to_str)
{
    char *str = my_add_char_to_str("hello", 'h');

    cr_assert_str_eq(str, "helloh");
}