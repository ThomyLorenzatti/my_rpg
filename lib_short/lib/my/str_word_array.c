/*
** EPITECH PROJECT, 2021
** str_word_array
** File description:
** str_word_array
*/

#include <stdio.h>
#include <unistd.h>
#include <my.h>

int get_len_tab(char *str, char c)
{
    int len = 1;

    if (str[0] == c)
        len = 0;
    for (int i = 1; str[i]; i++) {
        if ((str[i] != c) &&
        (str[i - 1] == c))
            len++;
    }
    return (len);
}

int is_string(char *word, char c)
{
    for (int i = 0; word[i]; i++)
        if (word[i] != c)
            return (0);
    return (1);
}

int change_i(int i, char *str, char c)
{
    while (str[i] == c)
        i++;
    i = str[i] == '\0' ? i - 1 : i;
    return (i);
}

char **my_str_word_array(char *str, char c)
{
    int len_tab = get_len_tab(str, c);
    char **tab_word = my_malloc(sizeof(char *) * (len_tab + 1));
    char *word = "";
    int index = 0;

    tab_word[len_tab] = NULL;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c && is_string(word, c) == 0) {
            tab_word[index] = word;
            index++;
            word = "";
        }
        i = change_i(i, str, c);
        word = my_add_char_to_str(word, str[i]);
    }
    if (is_string(word, c) == 0)
        tab_word[index] = word;
    return (tab_word);
}