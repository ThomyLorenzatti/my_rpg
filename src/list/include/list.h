/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __LIST_H__
#define __LIST_H__

#include <rpg.h>

void init_slot_list(rpg_t *rpg);
slot_t i_s(sfVector2f pos, int place, int free, slot_t to_init);
object_t init_object_list(int place, int nb, object_t to_init, char *path);
float get_distance(float cx, float cy, float x, float y);
void slot_list_push_back(list_slot **list, slot_t value);
void slot_list_destroy(list_slot **list);
void obj_list_push_back(list_obj **list, object_t value);
void obj_list_destroy(list_obj **list);

#endif /* !__RPG_H__ */