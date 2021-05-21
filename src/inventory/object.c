/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** object.c
*/

#include <rpg.h>

void init_object(rpg_t *rpg)
{
    rpg->nbobj = obj_list_len(rpg);
    rpg->scene = 0;
}

int check_del_obj2(rpg_t *rpg, slot_t slot, list_obj *tmp)
{
    if (tmp->value.place == slot.place) {
        if (rpg->event.type == sfEvtKeyPressed &&
        rpg->event.key.code == sfKeyLShift)
            remove_obj(rpg, tmp->value.place - 1);
        rpg->nbobj = obj_list_len(rpg);
        return (1);
    }
    return (0);
}

void check_del_obj(rpg_t *rpg, slot_t slot)
{
    list_obj *tmp = rpg->inv.obj;

    for (; tmp != NULL; tmp = tmp->next) {
        if (check_del_obj2(rpg, slot, tmp) == 1)
            return;
    }
}

int check_use_obj(rpg_t *rpg, object_t obj)
{
    if (my_strcmp(obj.look.path, "./res/heal.png") == 0 &&
    rpg->player.life < rpg->player.max_life) {
        rpg->player.life += 1;
        remove_obj(rpg, obj.place - 1);
        return (1);
    }
    if (my_strcmp(obj.look.path, "./res/speed.png") == 0) {
        rpg->player.vspeed += 1;
        remove_obj(rpg, obj.place - 1);
        return (1);
    }
    if (my_strcmp(obj.look.path, "./res/ps.png") == 0) {
        rpg->hunt = 1;
        rpg->inv.open = 0;
    }
    if (my_strcmp(obj.look.path, "./res/mp3.png") == 0) {
        rpg->mp3 = 1;
        rpg->inv.open = 0;
    }
    return (0);
}