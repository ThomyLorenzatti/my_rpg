/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_HOUSE_H__
#define __STRUCT_HOUSE_H__

#include <struct_sprite.h>

typedef struct house_s house_t;

struct house_s {
    char **collisions;
    sprite_t back;
    sprite_t ground;
    sprite_t wall;
    sprite_t props;
    sprite_t props2;
    int bubble;
};

#endif /* !__RPG_H__ */