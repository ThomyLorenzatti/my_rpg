/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_INVENTORY_H__
#define __STRUCT_INVENTORY_H__

#include <struct_sprite.h>

typedef struct object_s
{
    sprite_t look;
    int place;
    int nb;
    int use;
    int on_map;
}object_t;

typedef struct slot_s
{
    sfVector2f pos;
    int place;
    int free;
    sprite_t clic;
}slot_t;

typedef struct list_obj
{
    object_t value;
    struct list_obj *next;
}list_obj;

typedef struct list_s
{
    slot_t value;
    struct list_s *next;
}list_slot;

typedef struct inv_s
{
    sprite_t inv;
    int open;
    int radius;
    list_obj *obj;
    list_slot *slot;
    sfVector2i cdisp;
}inv_t;

#endif /* !__RPG_H__ */