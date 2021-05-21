/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_putstr, test_my_putstr)
{
    cr_redirect_stdout();
    my_putstr("abcde");
    cr_assert_stdout_eq_str("abcde");
}
