/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __SKILL_H__
#define __SKILL_H__

#include <rpg.h>

void init_skilltab(rpg_t *rpg);
void skilltab_event2(rpg_t *rpg, sfMouseButtonEvent mouse);
void skilltab_event(rpg_t *rpg, sfMouseButtonEvent mouse);
void draw_skilltab(rpg_t *rpg);
void speed_click(rpg_t *rpg);
void attack_click(rpg_t *rpg);
void armor_click(rpg_t *rpg);

#endif /* !__RPG_H__ */