/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** inventory draw
*/

#include <rpg.h>

void draw_inventory(rpg_t *rpg)
{
    list_slot *tmp = NULL;

    if (rpg->inv.open != 1)
        return;
    display_sprite(rpg->window, &rpg->inv.inv, 0, 0);
    tmp = rpg->inv.slot;
    for (; tmp != NULL; tmp = tmp->next) {
        if (rpg->inv.cdisp.x == tmp->value.place && rpg->inv.cdisp.y == 1) {
            display_sprite(rpg->window, &tmp->value.clic,
            tmp->value.pos.x, tmp->value.pos.y);
        }
        display_in_inv(rpg, tmp->value);
    }
}