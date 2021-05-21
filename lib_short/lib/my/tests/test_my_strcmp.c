/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

Test(my_strcmp, test_strcmp)
{
    int v = my_strcmp("123", "123");

    cr_assert_eq(v, 0);
}

Test(my_strcmp, test_strcmp_2)
{
    int v = my_strcmp("123", "133");

    cr_assert_eq(v, -1);
}

Test(my_strcmp, test_strcmp_3)
{
    int v = my_strcmp("123", "12");

    cr_assert_eq(v, 51);
}

Test(my_strncmp, test_strncmp)
{
    int v = my_strncmp("123", "124", 2);

    cr_assert_eq(v, 0);
}

Test(my_strncmp, test_strncmp_2)
{
    int v = my_strncmp("123", "133", 3);

    cr_assert_eq(v, -1);
}

Test(my_strncmp, test_strncmp_3)
{
    int v = my_strncmp("123", "12", 3);

    cr_assert_eq(v, 51);
}

Test(my_strncmp, test_strncmp_4)
{
    int v = my_strncmp("12", "123", 3);

    cr_assert_eq(v, -51);
}