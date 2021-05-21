/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** draw_pause.c
*/

#include <rpg.h>

void init_pause(rpg_t *rpg)
{
    rpg->pause = init_sprite(init_rect(0, 0, 800, 600), "./res/pause.png");
    rpg->pausec = init_sprite(init_rect(0, 0, 800, 600), "./res/pausec.png");
}

void draw_pause2(rpg_t *rpg)
{
    if (POS.x >= 300 && POS.x <= 500 && POS.y >= 380 && POS.y <= 440) {
        rpg->pausec.rect.top = 375;
        rpg->pausec.rect.height = 70;
        sfSprite_setTextureRect(rpg->pausec.sprite, rpg->pausec.rect);
        display_sprite(rpg->window, &rpg->pausec, 0, 375);
    }
    if (POS.x >= 300 && POS.x <= 500 && POS.y >= 460 && POS.y <= 520) {
        rpg->pausec.rect.top = 455;
        rpg->pausec.rect.height = 70;
        sfSprite_setTextureRect(rpg->pausec.sprite, rpg->pausec.rect);
        display_sprite(rpg->window, &rpg->pausec, 0, 455);
    }
}

void draw_pause(rpg_t *rpg)
{
    display_sprite(rpg->window, &rpg->pause, 0, 0);
    if (POS.x >= 300 && POS.x <= 500 && POS.y >= 250 && POS.y <= 310) {
        rpg->pausec.rect.top = 0;
        rpg->pausec.rect.height = 310;
        sfSprite_setTextureRect(rpg->pausec.sprite, rpg->pausec.rect);
        display_sprite(rpg->window, &rpg->pausec, 0, 0);
    }
    if (POS.x >= 300 && POS.x <= 500 && POS.y >= 320 && POS.y <= 370) {
        rpg->pausec.rect.top = 310;
        rpg->pausec.rect.height = 70;
        sfSprite_setTextureRect(rpg->pausec.sprite, rpg->pausec.rect);
        display_sprite(rpg->window, &rpg->pausec, 0, 310);
    }
    draw_pause2(rpg);
}

void pause_event2(rpg_t *rpg)
{
    if (POS.x >= 300 && POS.x <= 500 && POS.y >= 250 && POS.y <= 310) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            rpg->scene = rpg->lastscene;
    }
    if (POS.x >= 300 && POS.x <= 500 && POS.y >= 320 && POS.y <= 370) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            save(rpg);
    }
    if (POS.x >= 300 && POS.x <= 500 && POS.y >= 380 && POS.y <= 440) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            rpg->scene = 0;
    }
    if (POS.x >= 300 && POS.x <= 500 && POS.y >= 460 && POS.y <= 520) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(rpg->window);
    }
}

void pause_event(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == sfKeyEscape &&
    rpg->markop == 0 && rpg->inv.open == 0
    && rpg->hunt == 0 && rpg->scene != 3 && rpg->game.is_boat != 2) {
        rpg->lastscene = rpg->scene;
        rpg->scene = 3;
    }
    else if (rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == sfKeyEscape && rpg->scene == 3)
        rpg->scene = rpg->lastscene;
    if (rpg->scene == 3) {
        pause_event2(rpg);
    }
}