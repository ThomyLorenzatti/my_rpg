/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_unatoi, test_unatoi)
{
    char *str = my_unatoi(123);

    cr_assert_str_eq(str, "123");
}

Test(my_unatoi, test_unatoi_2)
{
    char *str = my_unatoi(-123);

    cr_assert_str_eq(str, "-123");
}

Test(my_unatoi, test_unatoi_3)
{
    char *str = my_unatoi(0);

    cr_assert_str_eq(str, "0");
}