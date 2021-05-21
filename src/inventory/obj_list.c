/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** obj_list.c
*/

#include <rpg.h>

int obj_list_len(rpg_t *rpg)
{
    int i = 1;
    list_obj *tmp = rpg->inv.obj;

    for (; tmp != NULL; tmp = tmp->next, i++) {
        tmp->value.place = i;
    }

    return (i);
}

void remove_obj(rpg_t *rpg, int index)
{
    list_obj *temp = rpg->inv.obj;
    list_obj *temp2 = NULL;

    if (temp == NULL)
        return;
    if (index == 0) {
        temp2 = rpg->inv.obj;
        rpg->inv.obj = rpg->inv.obj->next;
        destroy_sprite(&temp2->value.look);
        return;
    }
    for (int i = 1; i < index; i++)
        temp = temp->next;
    temp2 = temp->next;
    temp->next = temp->next->next;
    destroy_sprite(&temp2->value.look);
}