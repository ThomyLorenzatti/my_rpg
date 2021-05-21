/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** skills.c
*/

#include <rpg.h>

void init_skilltab(rpg_t *rpg)
{
    rpg->player.fontpt = sfFont_createFromFile("res/font/font.ttf");
    rpg->player.textpt = sfText_create();
    rpg->player.skilltabmenu = init_sprite(init_rect(0, 0, 800, 600),
    "res/skilltree/skilltree.png");
    rpg->player.speedtree = init_sprite(init_rect(0, 0, 37, 274),
    "res/skilltree/tree.png");
    rpg->player.armortree = init_sprite(init_rect(0, 0, 37, 274),
    "res/skilltree/tree.png");
    rpg->player.attacktree = init_sprite(init_rect(0, 0, 37, 274),
    "res/skilltree/tree.png");
    rpg->player.levelup.sound = sfSound_create();
    rpg->player.levelup.buffer =
    sfSoundBuffer_createFromFile("sound/xp_sound.ogg");
    sfSound_setVolume(rpg->player.levelup.sound, 70);
    sfSound_setBuffer(rpg->player.levelup.sound, rpg->player.levelup.buffer);
}

void skilltab_event2(rpg_t *rpg, sfMouseButtonEvent mouse)
{
    if (rpg->player.skilltab != 1)
        return;
    if (mouse.type == sfEvtMouseButtonPressed &&
    mouse.button == sfMouseLeft) {
        if ((mouse.x >= 275 && mouse.x <= 310) &&
        (mouse.y >= 495 && mouse.y <= 525))
            speed_click(rpg);
        if ((mouse.x >= 375 && mouse.x <= 405) &&
        (mouse.y >= 495 && mouse.y <= 525))
            attack_click(rpg);
        if ((mouse.x >= 485 && mouse.x <= 525) &&
        (mouse.y >= 495 && mouse.y <= 525))
            armor_click(rpg);
    }
}

void skilltab_event(rpg_t *rpg, sfMouseButtonEvent mouse)
{
    if (rpg->inv.open == 1)
        return;
    if ((rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == rpg->settkey.skilltab - 65) &&
    rpg->player.skilltab == 0)
        rpg->player.skilltab = 1;
    else if ((rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == rpg->settkey.skilltab - 65) &&
    rpg->player.skilltab == 1)
        rpg->player.skilltab = 0;
    skilltab_event2(rpg, mouse);
}

void draw_skilltab(rpg_t *rpg)
{
    if (rpg->player.skilltab == 1) {
        display_sprite(rpg->window, &rpg->player.skilltabmenu, 0, 0);
        display_sprite(rpg->window, &rpg->player.speedtree, 276, 252);
        display_sprite(rpg->window, &rpg->player.attacktree, 380, 252);
        display_sprite(rpg->window, &rpg->player.armortree, 492, 252);
        sfText_setString(rpg->player.textpt, my_unatoi(rpg->player.pt));
        sfText_setFont(rpg->player.textpt, rpg->player.fontpt);
        sfText_setColor(rpg->player.textpt, sfWhite);
        sfText_setOutlineColor(rpg->player.textpt, sfGreen);
        sfText_setOutlineThickness(rpg->player.textpt, 1);
        sfText_setPosition(rpg->player.textpt, (sfVector2f) {410, 130});
        sfRenderWindow_drawText(rpg->window, rpg->player.textpt, NULL);
    }
}