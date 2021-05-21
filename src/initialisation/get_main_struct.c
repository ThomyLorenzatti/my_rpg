/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get main struct
*/

#include <rpg.h>

void create_rpg(rpg_t *rpg)
{
    init_game(rpg);
}

rpg_t *get_main_struct(int check)
{
    static rpg_t rpg;

    if (check == 0)
        create_rpg(&rpg);
    return (&rpg);
}