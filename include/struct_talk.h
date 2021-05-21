/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_TALK_H__
#define __STRUCT_TALK_H__

#include <struct_sprite.h>

typedef struct talk_s talk_t;

struct talk_s
{
    sprite_t bg;
    sfText *text;
    sfFont *font;
    int is_speaking;
};

#endif /* !__RPG_H__ */