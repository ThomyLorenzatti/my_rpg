/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(str_word_array, test_str_array)
{
    char *str = "hello comment va?";
    char **arr = my_str_word_array(str, ' ');

    cr_assert_str_eq(arr[0], "hello");
}

Test(str_word_array, test_str_array_2)
{
    char *str = "hello comment va?    ";
    char **arr = my_str_word_array(str, ' ');

    cr_assert_str_eq(arr[0], "hello");
}

Test(str_word_array, test_str_array_3)
{
    char *str = "  hello comment va?    ";
    char **arr = my_str_word_array(str, ' ');

    cr_assert_str_eq(arr[0], "hello");
}