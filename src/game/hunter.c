/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** hunter.c
*/

#include <rpg.h>

void init_hunt(rpg_t *rpg)
{
    rpg->hback = init_sprite(init_rect(0, 0, 800, 600), "./res/hback.png");
    rpg->dc = sfClock_create();
    rpg->duck = init_sprite(init_rect(0, 0, 110, 110), "res/duck.png");
    rpg->duck.position.y = ((rand() % 300));
    rpg->duck.position.x = ((rand() % 900) - 150) * -1;
    sfSprite_setPosition(rpg->duck.sprite, rpg->duck.position);
}

void draw_hunt(rpg_t *rpg)
{
    sfVector2u size = sfTexture_getSize(rpg->duck.texture);
    rpg->time = sfClock_getElapsedTime(rpg->dc);

    display_sprite(rpg->window, &rpg->hback, 0, 0);
    display_sprite(rpg->window, &rpg->duck, rpg->duck.position.x,
    rpg->duck.position.y);
    sfSprite_setPosition(rpg->duck.sprite, rpg->duck.position);
    rpg->duck.position.x = (rpg->duck.position.x > 800)
    ? -110 : rpg->duck.position.x + 6;
    if (rpg->time.microseconds / 1000000.0 > 0.10) {
        rpg->duck.rect.left += size.x / 3;
        if (rpg->duck.rect.left >= (int) size.x)
            rpg->duck.rect.left = 0;
        sfClock_restart(rpg->dc);
    }
}

void event_hunt(rpg_t *rpg)
{
    if (POS.x > rpg->duck.position.x && POS.x < rpg->duck.position.x + 110 &&
    POS.y > rpg->duck.position.y && POS.y < rpg->duck.position.y + 110) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            rpg->duck.position.y = ((rand() % 300));
            rpg->duck.position.x = ((rand() % 800) - 50) * -1;
            sfSprite_setPosition(rpg->duck.sprite, rpg->duck.position);
        }
    }
    if (rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == sfKeyEscape)
        rpg->hunt = 0;
}