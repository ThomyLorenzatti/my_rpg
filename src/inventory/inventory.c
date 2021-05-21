/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** inventory.c
*/

#include <rpg.h>

void check_items(rpg_t *rpg, char *path)
{
    if (my_strcmp(path, "./res/rab.png") == 0)
        rpg->nbpet += 1;
    if (my_strcmp(path, "./res/ps.png") == 0)
        rpg->nbps += 1;
    if (my_strcmp(path, "./res/mp3.png") == 0)
        rpg->nbmp3 += 1;
}

void to_buy(rpg_t *rpg, int price, char *path)
{
    object_t obj;

    if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed
    && rpg->money >= price) {
        play_sound(rpg->clic.sound, rpg);
        obj_list_push_back(&rpg->inv.obj,
        init_object_list(rpg->nbobj, 1, obj, path));
        rpg->nbobj = obj_list_len(rpg);
        rpg->money -= price;
        if (my_strcmp(path, "./res/heal.png") == 0)
            rpg->nbheal += 1;
        if (my_strcmp(path, "./res/speed.png") == 0)
            rpg->nbsp += 1;
        if (my_strcmp(path, "./res/totem.png") == 0)
            rpg->nbtot += 1;
        check_items(rpg, path);
    }
}

void create_inventory(rpg_t *rpg)
{
    rpg->inv.cdisp = (sfVector2i) {0, 0};
    rpg->inv.radius = 20;
    rpg->inv.obj = NULL;
    rpg->inv.slot = NULL;
    rpg->inv.open = 0;
    rpg->inv.inv = init_sprite(init_rect(0, 0, 800, 600), "res/inv.png");
    init_slot_list(rpg);
}

void display_in_inv(rpg_t *rpg, slot_t s)
{
    list_obj *tmp = rpg->inv.obj;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->value.place == s.place) {
            display_sprite(rpg->window, &tmp->value.look, s.pos.x, s.pos.y);
        }
    }
}

void destroy_inv(rpg_t *rpg)
{
    list_obj *temp = rpg->inv.obj;

    while (temp) {
        remove_obj(rpg, 0);
        temp = temp->next;
    }
}