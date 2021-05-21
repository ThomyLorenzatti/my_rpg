/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** inventory_event.c
*/

#include <rpg.h>

void check_on_slot(rpg_t *rpg, slot_t slot, int i)
{
    rpg->inv.cdisp.x = i;
    rpg->inv.cdisp.y = 1;
}

void check_object_in_slot(rpg_t *rpg, slot_t slot)
{
    if (get_distance(slot.pos.x, slot.pos.y, POS.x, POS.y) < rpg->inv.radius) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            check_use_obj_loop(rpg, slot);
        }
        check_del_obj(rpg, slot);
    }
}

void check_slots2(rpg_t *rpg, list_slot *tmp)
{
    for (int i = 1; i <= 18; i++) {
        if (tmp->value.place == i && SLOT < rpg->inv.radius)
            check_on_slot(rpg, tmp->value, i);
    }
}

void check_slots(rpg_t *rpg)
{
    list_slot *tmp = rpg->inv.slot;

    for (; tmp != NULL; tmp = tmp->next) {
        check_slots2(rpg, tmp);
        check_object_in_slot(rpg, tmp->value);
    }
}

void inventory_event(rpg_t *rpg)
{
    if (rpg->player.skilltab == 1)
        return;
    if ((rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == rpg->settkey.inventory - 65) && rpg->inv.open == 0)
        rpg->inv.open = 1;
    else if ((rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == rpg->settkey.inventory - 65)
    && rpg->inv.open == 1)
        rpg->inv.open = 0;
    if (rpg->inv.open == 1)
        check_slots(rpg);
}