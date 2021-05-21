/*
** EPITECH PROJECT, 2021
** rgp
** File description:
** quest
*/

#include <rpg.h>

void quest(rpg_t *rpg)
{
    if (rpg->game.quest == 0)
        house_door_locked(rpg);
    else
        house_door_unlocked(rpg);
    cave_locked(rpg);
}