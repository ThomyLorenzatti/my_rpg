/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_char_in_str, test_my_char_in_str)
{
    int res = my_char_in_str('a', "abc");

    cr_assert_eq(res, 1);
}

Test(my_char_in_str, test_my_char_in_str2)
{
    int res = my_char_in_str('d', "abc");

    cr_assert_eq(res, 0);
}

Test(my_char_str_in_str, test_my_char_str_in_str)
{
    int res = my_char_str_in_str("ad", "abc");

    cr_assert_eq(res, 0);
}

Test(my_char_str_in_str, test_my_char_str_in_str2)
{
    int res = my_char_str_in_str("a", "abc");

    cr_assert_eq(res, 0);
}

Test(my_char_str_in_str, test_my_char_str_in_str3)
{
    int res = my_char_str_in_str("c", "abc");

    cr_assert_eq(res, 1);
}

Test(my_unknow_char_str_in_str, test_my_unknow_char_str_in_str)
{
    int res = my_unknow_char_str_in_str("c", "abc");

    cr_assert_eq(res, 0);
}

Test(my_unknow_char_str_in_str, test_my_unknow_char_str_in_str2)
{
    int res = my_unknow_char_str_in_str("ababcababacbac", "abc");

    cr_assert_eq(res, 0);
}

Test(my_unknow_char_str_in_str, test_my_unknow_char_str_in_str3)
{
    int res = my_unknow_char_str_in_str("fcgvhbjnkl", "abc");

    cr_assert_eq(res, 1);
}

Test(my_unknow_char_str_in_str, test_my_unknow_char_str_in_str4)
{
    int res = my_unknow_char_str_in_str("a", "abca");

    cr_assert_eq(res, 0);
}