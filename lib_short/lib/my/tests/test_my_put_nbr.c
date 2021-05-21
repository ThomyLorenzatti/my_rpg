/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_put_nbr, test_put_nbr)
{
    cr_redirect_stdout();
    my_put_nbr(12345);
    cr_assert_stdout_eq_str("12345");
}