/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_printf, test_printf)
{
    cr_redirect_stdout();
    my_printf("hello %d %i %c %s", 123, 123, 'A', "hello");
    cr_assert_stdout_eq_str("hello 123 123 A hello");
}
