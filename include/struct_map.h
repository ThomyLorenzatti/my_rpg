/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_MAP_H__
#define __STRUCT_MAP_H__

#include <struct_sprite.h>

typedef struct map_s map_t;

struct map_s
{
    char **collisions;
    sprite_t layer1;
    sprite_t back;
    sprite_t border;
    sprite_t path;
    sprite_t houses;
    sprite_t cave;
    sprite_t cave_wall;
    sprite_t cave_ground;
    char **cave_col;
    sprite_t lava;
};

#endif /* !__RPG_H__ */