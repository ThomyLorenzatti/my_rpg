/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** menu draw
*/

#include <rpg.h>

void draw_menu3(rpg_t *rpg)
{
    if (rpg->menu == 2) {
        display_sprite(rpg->window, &rpg->moption, 0, 0);
        display_sprite(rpg->window, &rpg->greyoption1, 260, 171);
        display_sprite(rpg->window, &rpg->greyoption2, 260, 285);
        display_sprite(rpg->window, &rpg->redoption, 260 +
        ((rpg->musicv - 12.5) * 1.15), 165);
        display_sprite(rpg->window, &rpg->blueoption, 260 +
        ((rpg->soundv - 12.5) * 1.15), 280);
        draw_option(rpg);
        draw_option2(rpg);
        display_keys(rpg);
    }
}

void draw_menu2(rpg_t *rpg)
{
    if (POS.x >= 65 && POS.x <= 222 && POS.y >= 505 && POS.y <= 550)
        display_sprite(rpg->window, &rpg->quitc, 0, 0);
    rpg->time = sfClock_getElapsedTime(rpg->persom.clock);
    sfVector2u size = sfTexture_getSize(rpg->persom.texture);
    sfSprite_setScale(rpg->persom.sprite, (sfVector2f) {1.5, 1.5});
    display_sprite(rpg->window, &rpg->persom, 450, 200);
    if (rpg->time.microseconds / 1000000.0 > 0.20) {
        sfClock_restart(rpg->persom.clock);
        rpg->persom.rect.left += size.x / 4;
        if (rpg->persom.rect.left >= (int) size.x)
            rpg->persom.rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->persom.sprite,
    rpg->persom.rect);
    if (POS.x >= 620 && POS.x <= 770 && POS.y >= 505 && POS.y <= 550)
        display_sprite(rpg->window, &rpg->htp, 0, 0);
}

void draw_menu(rpg_t *rpg)
{
    display_sprite(rpg->window, &rpg->mbg, 0, 0);
    if (rpg->menu == 0) {
        display_sprite(rpg->window, &rpg->mbutton, 0, 0);
        if (POS.x >= 65 && POS.x <= 222 && POS.y >= 325 && POS.y <= 372)
            display_sprite(rpg->window, &rpg->playc, 0, 0);
        if (POS.x >= 65 && POS.x <= 222 && POS.y >= 383 && POS.y <= 429)
            display_sprite(rpg->window, &rpg->loadc, 0, 0);
        if (POS.x >= 65 && POS.x <= 222 && POS.y >= 442 && POS.y <= 490)
            display_sprite(rpg->window, &rpg->optionc, 0, 0);
        draw_menu2(rpg);
    }
    if (rpg->menu == 3) {
        display_sprite(rpg->window, &rpg->htpm, 0, 0);
        if (POS.x >= 40 && POS.x <= 235 && POS.y >= 45 && POS.y <= 105)
            display_sprite(rpg->window, &rpg->gtmc, 0, 0);
    }
    draw_menu3(rpg);
}