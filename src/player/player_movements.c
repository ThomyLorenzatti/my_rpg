/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** player movements
*/

#include <rpg.h>

void change_rects(rpg_t *rpg)
{
    rpg->player.skin.rect = rpg->player.player.rect;
    rpg->player.pant.rect = rpg->player.player.rect;
    rpg->player.vest.rect = rpg->player.player.rect;
    rpg->player.paint.rect = rpg->player.player.rect;
    rpg->player.eye.rect = rpg->player.player.rect;
    rpg->player.hair.rect = rpg->player.player.rect;
    rpg->player.sword.rect = rpg->player.player.rect;
}

void check_anim_clock(rpg_t *rpg, int top)
{
    sfVector2u size = sfTexture_getSize(rpg->player.player.texture);

    rpg->time = sfClock_getElapsedTime(rpg->player.player.clock);
    if (rpg->time.microseconds / 1000000.0 >= 0.15) {
        sfClock_restart(rpg->player.player.clock);
        rpg->player.player.rect.left += size.x / 3;
        rpg->player.player.rect.top = size.y / 4 * top;
        if (rpg->player.player.rect.left >= (int) size.x)
            rpg->player.player.rect.left = 0;
        change_rects(rpg);
    }
}

void player_movements2(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code + 65 == rpg->settkey.left)
            rpg->player.move = -2;
    }
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code + 65 == rpg->settkey.right)
            rpg->player.move = 2;
    }
}

void player_movements(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyReleased) {
        rpg->player.player.rect.left = 0;
        rpg->player.move = 0;
        sfSprite_setTextureRect(rpg->player.player.sprite,
        rpg->player.player.rect);
    }
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code + 65 == rpg->settkey.backward)
            rpg->player.move = -1;
    }
    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code + 65 == rpg->settkey.forward)
            rpg->player.move = 1;
    }
    player_movements2(rpg);
}