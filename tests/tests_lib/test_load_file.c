/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(load_file, test_load)
{
    char *str = load_file("./tests/tests_lib/text.txt");

    cr_assert_str_eq(str, "hello");
}

Test(load_file, test_load_2)
{
    load_file("");
}

Test(load_file, test_load_3)
{
    load_file("./tests/tests_lib/test.txt");
}