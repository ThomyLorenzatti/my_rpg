/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** sprite.c
*/

#include "rpg.h"

void display_sprite(sfRenderWindow *window, sprite_t *sprite, float x, float y)
{
    sprite->position.x = x;
    sprite->position.y = y;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, sprite->position);
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
}

sprite_t init_sprite(sfIntRect rect, char *path)
{
    sprite_t sprite;

    sprite.path = path;
    sprite.rect = rect;
    sprite.texture = sfTexture_createFromFile(path, NULL);
    sfTexture_setRepeated(sprite.texture, sfTrue);
    sprite.sprite = sfSprite_create();
    sfSprite_setTextureRect(sprite.sprite, sprite.rect);
    sprite.clock = sfClock_create();
    return (sprite);
}

sfIntRect init_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

void move_rect(sfIntRect* rect, float offset)
{
    rect->left += offset;
}