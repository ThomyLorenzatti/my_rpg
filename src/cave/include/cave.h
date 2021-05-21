/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __CAVE_H__
#define __CAVE_H__

#include <rpg.h>

void cave_locked(rpg_t *rpg);
void draw_cave2(rpg_t *rpg);
void draw_cave(rpg_t *rpg);
void cave_checker(rpg_t *rpg, sfVector2f pos);
void cave_events(rpg_t *rpg);

#endif /* !__RPG_H__ */