/*
** EPITECH PROJECT, 2020
** my_memset
** File description:
** my_memset
*/

char *my_memset(char *str, char c, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = c;
    return (str);
}