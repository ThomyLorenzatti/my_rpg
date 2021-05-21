/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_CURSOR_H__
#define __STRUCT_CURSOR_H__

#include <struct_sprite.h>

typedef struct cursor_s cursor_t;

struct cursor_s
{
    sfVector2f position;
    sfIntRect rectangle;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfTime time;
    float seconds;
};

#endif /* !__RPG_H__ */