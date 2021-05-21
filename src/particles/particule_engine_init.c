/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init particule engine
*/

#include <rpg.h>

void init_particule_engine(rpg_t *rpg)
{
    for (int i = 0; i < MAX_PART; i++) {
        rpg->game.eng[i].living = 0;
        rpg->game.eng[i].clock = sfClock_create();
    }
}

void reset_particule_engine(rpg_t *rpg)
{
    for (int i = 0; i < MAX_PART; i++)
        rpg->game.eng[i].living = 0;
}