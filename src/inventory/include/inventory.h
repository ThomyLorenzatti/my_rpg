/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <rpg.h>

void draw_inventory(rpg_t *rpg);
void check_on_slot(rpg_t *rpg, slot_t slot, int i);
void check_object_in_slot(rpg_t *rpg, slot_t slot);
void check_slots2(rpg_t *rpg, list_slot *tmp);
void check_slots(rpg_t *rpg);
void inventory_event(rpg_t *rpg);
void check_items(rpg_t *rpg, char *path);
void to_buy(rpg_t *rpg, int price, char *path);
void create_inventory(rpg_t *rpg);
void display_in_inv(rpg_t *rpg, slot_t s);
void destroy_inv(rpg_t *rpg);
int obj_list_len(rpg_t *rpg);
void remove_obj(rpg_t *rpg, int index);
int check_use_obj_loop2(rpg_t *rpg, slot_t slot, list_obj *tmp);
void check_use_obj_loop(rpg_t *rpg, slot_t slot);
void init_object(rpg_t *rpg);
int check_del_obj2(rpg_t *rpg, slot_t slot, list_obj *tmp);
void check_del_obj(rpg_t *rpg, slot_t slot);
int check_use_obj(rpg_t *rpg, object_t obj);

#endif /* !__RPG_H__ */