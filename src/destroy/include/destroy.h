/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __DESTROY_H__
#define __DESTROY_H__

#include <rpg.h>

void destroy_sprite(sprite_t *sp);
void destroy_sound(sound_t *s);
void destroy_particule_engine(rpg_t *rpg);
void destroy_all4(rpg_t *rpg);
void destroy_all3(rpg_t *rpg);
void destroy_all2(rpg_t *rpg);
void destroy_all(rpg_t *rpg);

#endif /* !__RPG_H__ */