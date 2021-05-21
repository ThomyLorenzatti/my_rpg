/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_ENEMIES_H__
#define __STRUCT_ENEMIES_H__

#include <struct_sprite.h>

typedef struct enemies_s enemies_t;

struct enemies_s {
    sprite_t sp;
    int speed;
    int life;
    int xp;
    int attack;
    int type;
    int cooldown;
    sfClock *a_clock;
    sprite_t att;
    sfVector2f dir;
    int swoosh;
    enemies_t *next;
};

#endif /* !__RPG_H__ */