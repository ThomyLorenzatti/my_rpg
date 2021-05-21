/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** object use
*/

#include <rpg.h>

int check_use_obj_loop2(rpg_t *rpg, slot_t slot, list_obj *tmp)
{
    if (tmp->value.place == slot.place) {
        if (check_use_obj(rpg, tmp->value) == 1) {
            rpg->nbobj = obj_list_len(rpg);
            return (1);
        }
    }
    return (0);
}

void check_use_obj_loop(rpg_t *rpg, slot_t slot)
{
    list_obj *tmp = rpg->inv.obj;

    for (; tmp != NULL; tmp = tmp->next) {
        if (check_use_obj_loop2(rpg, slot, tmp) == 1)
            return;
    }
}