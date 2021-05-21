/*
** EPITECH PROJECT, 2020
** update
** File description:
** game_over.c
*/

#include <rpg.h>

void init_gover(rpg_t *rpg)
{
    rpg->gom = init_sprite(init_rect(0, 0, 800, 600), "./res/gom.png");
    rpg->gomb = init_sprite(init_rect(0, 0, 800, 600), "./res/gomb.png");
}

void gover_event(rpg_t *rpg)
{
    if (POS.x >= 285 && POS.x <= 525 && POS.y >= 235 && POS.y <= 340) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            rpg->player.player.position = (sfVector2f) {200, 250};
            sfSprite_setPosition(rpg->player.player.sprite,
            (sfVector2f) {255, 210});
            rpg->player.move = 0;
            rpg->player.life = rpg->player.max_life;
            sfSprite_setPosition(rpg->map.layer1.sprite, (sfVector2f)
            {-5010, -5370});
            rpg->scene = 1;
        }
    }
    if (POS.x >= 285 && POS.x <= 525 && POS.y >= 350 && POS.y <= 420) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(rpg->window);
    }
}

void draw_gover(rpg_t *rpg)
{
    display_sprite(rpg->window, &rpg->gom, 0, 0);
    if (POS.x >= 285 && POS.x <= 525 && POS.y >= 235 && POS.y <= 340) {
        rpg->gomb.rect.top = 0;
        rpg->gomb.rect.height = 345;
        sfSprite_setTextureRect(rpg->gomb.sprite, rpg->gomb.rect);
        display_sprite(rpg->window, &rpg->gomb, 0, 0);
    }
    if (POS.x >= 285 && POS.x <= 525 && POS.y >= 350 && POS.y <= 420) {
        rpg->gomb.rect.top = 345;
        rpg->gomb.rect.height = 80;
        sfSprite_setTextureRect(rpg->gomb.sprite, rpg->gomb.rect);
        display_sprite(rpg->window, &rpg->gomb, 0, 345);
    }
}