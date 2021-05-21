/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_SPRITE_H__
#define __STRUCT_SPRITE_H__

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct sprites
{
    sfVector2f position;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfTime time;
    sfTime time2;
    sfText *text;
    sfFont *font;
    char **array;
    char *path;
    int index;
    float size;
    float seconds;
    float seconds2;
    sfClock *clock;
    sfClock *clock2;
    sfMusic *music;
} sprite_t;

#endif /* !__RPG_H__ */