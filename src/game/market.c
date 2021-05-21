/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** market.c
*/

#include <rpg.h>

void init_market(rpg_t *rpg)
{
    rpg->money = 1000;
    rpg->nbheal = 0;
    rpg->nbsp = 0;
    rpg->nbtot = 0;
    rpg->nbpet = 0;
    rpg->nbps = 0;
    rpg->nbmp3 = 0;
    rpg->moneyf = sfFont_createFromFile("res/font/font.ttf");
    rpg->moneyt = sfText_create();
    sfText_setFont(rpg->moneyt, rpg->moneyf);
    sfText_setColor(rpg->moneyt, sfWhite);
    sfText_setPosition(rpg->moneyt, (sfVector2f) {355, 315});
    sfText_setScale(rpg->moneyt, (sfVector2f) {1.70, 1.70});
    rpg->market = init_sprite(init_rect(0, 0, 800, 600), "./res/market.png");
    rpg->mb = init_sprite(init_rect(0, 0, 800, 600), "./res/mb.png");
}

void event_market2(rpg_t *rpg)
{
    if (POS.x >= 195 && POS.x <= 370 && POS.y >= 110 && POS.y <= 160)
        to_buy(rpg, 50, "./res/heal.png");
    if (POS.x >= 425 && POS.x <= 600 && POS.y >= 110 && POS.y <= 160)
        to_buy(rpg, 100, "./res/totem.png");
    if (POS.x >= 195 && POS.x <= 370 && POS.y >= 170 && POS.y <= 225)
        to_buy(rpg, 50, "./res/speed.png");
    if (POS.x >= 425 && POS.x <= 600 && POS.y >= 170 && POS.y <= 225)
        to_buy(rpg, 100, "./res/ps.png");
    if (POS.x >= 195 && POS.x <= 370 && POS.y >= 240 && POS.y <= 290)
        to_buy(rpg, 100, "./res/rab.png");
    if (POS.x >= 425 && POS.x <= 600 && POS.y >= 240 && POS.y <= 290)
        to_buy(rpg, 200, "./res/mp3.png");
}

void event_market(rpg_t *rpg)
{
    if (rpg->markop == 1) {
        if (rpg->event.type == sfEvtKeyPressed &&
        rpg->event.key.code == sfKeyEscape)
            rpg->markop = 0;
        event_market2(rpg);
    }
}

void draw_market2(rpg_t *rpg)
{
    if (POS.x >= 425 && POS.x <= 600 && POS.y >= 170 && POS.y <= 225) {
        rpg->mb.rect = init_rect(170, 400, 400, 60);
        sfSprite_setTextureRect(rpg->mb.sprite, rpg->mb.rect);
        display_sprite(rpg->window, &rpg->mb, 400, 170);
    }
    if (POS.x >= 195 && POS.x <= 370 && POS.y >= 240 && POS.y <= 290) {
        rpg->mb.rect = init_rect(240, 0, 400, 60);
        sfSprite_setTextureRect(rpg->mb.sprite, rpg->mb.rect);
        display_sprite(rpg->window, &rpg->mb, 0, 240);
    }
    if (POS.x >= 425 && POS.x <= 600 && POS.y >= 240 && POS.y <= 290) {
        rpg->mb.rect = init_rect(240, 400, 400, 60);
        sfSprite_setTextureRect(rpg->mb.sprite, rpg->mb.rect);
        display_sprite(rpg->window, &rpg->mb, 400, 240);
    }
    sfText_setString(rpg->moneyt, my_unatoi(rpg->money));
    sfRenderWindow_drawText(rpg->window, rpg->moneyt, NULL);
}

void draw_market(rpg_t *rpg)
{
    if (rpg->markop == 1) {
        display_sprite(rpg->window, &rpg->market, 0, 0);
        if (POS.x >= 195 && POS.x <= 370 && POS.y >= 110 && POS.y <= 160) {
            rpg->mb.rect = init_rect(0, 0, 400, 170);
            sfSprite_setTextureRect(rpg->mb.sprite, rpg->mb.rect);
            display_sprite(rpg->window, &rpg->mb, 0, 0);
        }
        if (POS.x >= 425 && POS.x <= 600 && POS.y >= 110 && POS.y <= 160) {
            rpg->mb.rect = init_rect(0, 400, 400, 170);
            sfSprite_setTextureRect(rpg->mb.sprite, rpg->mb.rect);
            display_sprite(rpg->window, &rpg->mb, 400, 0);
        }
        if (POS.x >= 195 && POS.x <= 370 && POS.y >= 170 && POS.y <= 225) {
            rpg->mb.rect = init_rect(170, 0, 400, 60);
            sfSprite_setTextureRect(rpg->mb.sprite, rpg->mb.rect);
            display_sprite(rpg->window, &rpg->mb, 0, 170);
        }
        draw_market2(rpg);
    }
}