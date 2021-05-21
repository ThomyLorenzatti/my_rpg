/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** boat move
*/

#include <rpg.h>

bool key_exist(rpg_t *rpg)
{
    if (rpg->event.key.code + 65 == rpg->settkey.backward)
        return (false);
    if (rpg->event.key.code + 65 == rpg->settkey.forward)
        return (false);
    if (rpg->event.key.code + 65 == rpg->settkey.left)
        return (false);
    if (rpg->event.key.code + 65 == rpg->settkey.right)
        return (false);
    if (rpg->event.key.code + 65 == rpg->settkey.inventory)
        return (false);
    if (rpg->event.key.code + 65 == rpg->settkey.skilltab)
        return (false);
    return (true);
}

bool key_true(rpg_t *rpg)
{
    if (key_exist(rpg) == false)
        return (false);
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code >= 0 && rpg->event.key.code <= 25)
            return (true);
        if (rpg->event.key.code >= 71 && rpg->event.key.code <= 74)
            return (true);
    }
    return (false);
}

void update_text(rpg_t *rpg, text_t *node, int key)
{
    char tmp[4];
    if (key >= 65 && key <= 90) {
        tmp[0] = key;
        tmp[1] = '\0';
    } else {
        tmp[0] = 'A';
        tmp[1] = '_';
    }
    if (key == 73+65)
        tmp[2] = 'U';
    if (key == 74+65)
        tmp[2] = 'D';
    if (key == 71+65)
        tmp[2] = 'L';
    if (key == 72+65)
        tmp[2] = 'R';
    if (!(key >= 65 && key <= 90))
        tmp[3] = '\0';
    sfText_setString(node->text, tmp);
    sfRenderWindow_drawText(rpg->window, node->text, NULL);
}

void display_keys(rpg_t *rpg)
{
    update_text(rpg, &rpg->settkey.kinventory, rpg->settkey.inventory);
    update_text(rpg, &rpg->settkey.kskilltab, rpg->settkey.skilltab);
    update_text(rpg, &rpg->settkey.kforward, rpg->settkey.forward);
    update_text(rpg, &rpg->settkey.kbackward, rpg->settkey.backward);
    update_text(rpg, &rpg->settkey.kleft, rpg->settkey.left);
    update_text(rpg, &rpg->settkey.kright, rpg->settkey.right);
}

void event_bindings(rpg_t *rpg)
{
    if (key_true(rpg) == true) {
        if (POS.x >= 628 && POS.x <= 671 && POS.y >= 110 && POS.y <= 153)
            rpg->settkey.inventory = rpg->event.key.code + 65;
        if (POS.x >= 628 && POS.x <= 671 && POS.y >= 169 && POS.y <= 212)
            rpg->settkey.skilltab = rpg->event.key.code + 65;
        if (POS.x >= 628 && POS.x <= 671 && POS.y >= 230 && POS.y <= 273)
            rpg->settkey.forward = rpg->event.key.code + 65;
        if (POS.x >= 628 && POS.x <= 671 && POS.y >= 291 && POS.y <= 334)
            rpg->settkey.backward = rpg->event.key.code + 65;
        if (POS.x >= 628 && POS.x <= 671 && POS.y >= 348 && POS.y <= 391)
            rpg->settkey.left = rpg->event.key.code + 65;
        if (POS.x >= 628 && POS.x <= 671 && POS.y >= 407 && POS.y <= 450)
            rpg->settkey.right = rpg->event.key.code + 65;
    }
}