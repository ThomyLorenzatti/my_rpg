/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_BOSS_H__
#define __STRUCT_BOSS_H__

#include <struct_sprite.h>

typedef struct boss_s boss_t;

struct boss_s {
    sprite_t map;
    char **coll;
    sprite_t sp;
    sprite_t ic;
    int live;
    int attack;
    sfClock *c_move;
    int state;
    int attacking;
    sfClock *c_attack;
    sfClock *f_attack;
    sprite_t fire;
    sprite_t up;
    sprite_t ri;
    sprite_t dow;
    sprite_t le;
};

#endif /* !__RPG_H__ */