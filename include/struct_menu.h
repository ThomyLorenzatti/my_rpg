/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_MENU_H__
#define __STRUCT_MENU_H__

#include <struct_sprite.h>

typedef struct menu menu_t;

struct menu
{
    sfSprite* sprite;
    sfTexture* texture;
    sfIntRect rect;
    int offset;
    int index;
};

#endif /* !__RPG_H__ */