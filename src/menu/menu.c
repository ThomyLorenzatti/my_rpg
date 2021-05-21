/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** menu.c
*/

#include <rpg.h>

void create_font(text_t *text, char str, int x, int y)
{
    char tmp[2];
    tmp[0] = str;
    tmp[1] = '\0';
    text->font = sfFont_createFromFile("res/font/font.ttf");
    text->text = sfText_create();
    sfText_setScale(text->text, (sfVector2f){0.8, 0.8});
    sfText_setFont(text->text, text->font);
    sfText_setString(text->text, tmp);
    sfText_setPosition(text->text, (sfVector2f) {x, y});
}

void create_optmenu(rpg_t *rpg)
{
    rpg->blueoption = init_sprite(init_rect(0, 0, 25, 25),
    "./res/opt/blue_sound.png");
    rpg->backc = init_sprite(init_rect(0, 0, 212, 62), "res/opt/creturn.png");
    rpg->fpsc = init_sprite(init_rect(0, 0, 44, 44), "res/opt/cfps.png");
    rpg->cgreen = init_sprite(init_rect(0, 0, 44, 44), "res/opt/cgreen.png");
    rpg->cred = init_sprite(init_rect(0, 0, 44, 44), "res/opt/cred.png");
    rpg->moption = init_sprite(init_rect(0, 0, 800, 600),
    "res/opt/moptions.png");
    rpg->settkey.forward = 73 + 65;
    rpg->settkey.backward = 74 + 65;
    rpg->settkey.left = 71 + 65;
    rpg->settkey.right = 72 + 65;
    rpg->settkey.inventory = 8 + 65;
    rpg->settkey.skilltab = 18 + 65;
    create_font(&rpg->settkey.kinventory, rpg->settkey.inventory, 645, 115);
    create_font(&rpg->settkey.kskilltab, rpg->settkey.skilltab, 645, 175);
    create_font(&rpg->settkey.kforward, rpg->settkey.forward, 634, 235);
    create_font(&rpg->settkey.kbackward, rpg->settkey.backward, 634, 295);
    create_font(&rpg->settkey.kleft, rpg->settkey.left, 634, 355);
    create_font(&rpg->settkey.kright, rpg->settkey.right, 634, 415);
}

void create_menu(rpg_t *rpg)
{
    rpg->menu = 0;
    rpg->mbg = init_sprite(init_rect(0, 0, 800, 600), "./res/bg.jpg");
    rpg->mbutton = init_sprite(init_rect(0, 0, 800, 600), "./res/mbutton.png");
    rpg->playc = init_sprite(init_rect(0, 0, 800, 600), "./res/playc.png");
    rpg->loadc = init_sprite(init_rect(0, 0, 800, 600), "./res/loadc.png");
    rpg->optionc = init_sprite(init_rect(0, 0, 800, 600), "./res/optionc.png");
    rpg->quitc = init_sprite(init_rect(0, 0, 800, 600), "res/quitc.png");
    rpg->persom = init_sprite(init_rect(0, 0, 130, 150), "res/persom.png");
    rpg->htp = init_sprite(init_rect(0, 0, 800, 600), "./res/htp.png");
    rpg->htpm = init_sprite(init_rect(0, 0, 800, 600), "./res/htpm.png");
    rpg->gtmc = init_sprite(init_rect(0, 0, 800, 600), "./res/gtmc.png");
    rpg->greyoption1 = init_sprite(init_rect(0, 0, 115, 15),
    "./res/opt/grey_bar.png");
    rpg->greyoption2 = init_sprite(init_rect(0, 0, 115, 15),
    "./res/opt/grey_bar.png");
    rpg->redoption = init_sprite(init_rect(0, 0, 25, 25),
    "./res/opt/red_sound.png");
    rpg->musicv = 50;
    rpg->soundv = 50;
    create_optmenu(rpg);
}

void draw_option2(rpg_t *rpg)
{
    if (POS.x >= 628 && POS.x <= 671 && POS.y >= 110 && POS.y <= 154)
        display_sprite(rpg->window, &rpg->cred, 628, 110);
    if (POS.x >= 628 && POS.x <= 671 && POS.y >= 169 && POS.y <= 213)
        display_sprite(rpg->window, &rpg->cred, 628, 169);
    if (POS.x >= 628 && POS.x <= 671 && POS.y >= 230 && POS.y <= 274)
        display_sprite(rpg->window, &rpg->cgreen, 628, 230);
    if (POS.x >= 628 && POS.x <= 671 && POS.y >= 291 && POS.y <= 335)
        display_sprite(rpg->window, &rpg->cgreen, 628, 291);
    if (POS.x >= 628 && POS.x <= 671 && POS.y >= 348 && POS.y <= 392)
        display_sprite(rpg->window, &rpg->cgreen, 628, 348);
    if (POS.x >= 628 && POS.x <= 671 && POS.y >= 407 && POS.y <= 450)
        display_sprite(rpg->window, &rpg->cgreen, 628, 407);
}

void draw_option(rpg_t *rpg)
{
    if (POS.x >= 310 && POS.x <= 522 && POS.y >= 470 && POS.y <= 535)
        display_sprite(rpg->window, &rpg->backc, 311, 474);
    if (POS.x >= 212 && POS.x <= 256 && POS.y >= 378 && POS.y <= 422) {
        rpg->fpsc.rect.left = 0;
        rpg->fpsc.rect.width = 45;
        sfSprite_setTextureRect(rpg->fpsc.sprite, rpg->fpsc.rect);
        display_sprite(rpg->window, &rpg->fpsc, 212, 379);
    }
    if (POS.x >= 270 && POS.x <= 315 && POS.y >= 378 && POS.y <= 422) {
        rpg->fpsc.rect.left = 58;
        rpg->fpsc.rect.width = 45;
        sfSprite_setTextureRect(rpg->fpsc.sprite, rpg->fpsc.rect);
        display_sprite(rpg->window, &rpg->fpsc, 271, 379);
    }
    if (POS.x >= 329 && POS.x <= 374 && POS.y >= 378 && POS.y <= 422) {
        rpg->fpsc.rect.left = 118;
        rpg->fpsc.rect.width = 45;
        sfSprite_setTextureRect(rpg->fpsc.sprite, rpg->fpsc.rect);
        display_sprite(rpg->window, &rpg->fpsc, 330, 379);
    }
}