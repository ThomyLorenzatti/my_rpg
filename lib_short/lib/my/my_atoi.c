/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int nb = 0;
    int neg = str[0] == '-' ? -1 : 1;

    if (str[0] == '-')
        str = str + 1;
    for (int i = 0; str[i]; i++) {
        nb *= 10;
        if (neg == -1)
            nb -= (str[i] - 48);
        else
            nb += str[i] - 48;
    }
    return (nb);
}