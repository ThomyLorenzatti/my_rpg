/*
** EPITECH PROJECT, 2020
** char_in_str
** File description:
** char_in_str
*/

int my_char_in_str(char str, char *ref)
{
    for (int i = 0; ref[i]; i++)
        if (ref[i] == str)
            return (1);
    return (0);
}

int my_char_str_in_str(char *str, char *ref)
{
    char is_here = 'b';

    for (int i = 0; str[i]; i++) {
        for (int j = 0; ref[j]; j++) {
            is_here = (str[i] == ref[j]) ? 'a' : 'b';
        }
        if (is_here == 'a')
            return (1);
    }
    return (0);
}

int my_unknow_char_str_in_str(char *str, char *ref)
{
    char is_here = 'b';

    for (int i = 0; str[i]; i++) {
        is_here = 'b';
        for (int j = 0; ref[j]; j++) {
            is_here = (str[i] == ref[j] && is_here == 'b') ? 'a' : is_here;
        }
        if (is_here == 'b')
            return (1);
    }
    return (0);
}