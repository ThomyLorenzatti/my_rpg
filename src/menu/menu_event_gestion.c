/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** menu_event_gestion.c
*/

#include <rpg.h>

void option_event2(rpg_t *rpg)
{
    if (POS.x >= 329 && POS.x <= 374 && POS.y >= 378 && POS.y <= 422) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            play_sound(rpg->clic.sound, rpg);
            rpg->fps = 120;
        }
    }
    if (POS.x >= 265 && POS.x <= 365 && POS.y >= 173 && POS.y <= 183) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            rpg->musicv = POS.x - 265;
    }
    if (POS.x >= 265 && POS.x <= 365 && POS.y >= 285 && POS.y <= 295) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            rpg->soundv = POS.x - 265;

    }
    sfRenderWindow_setFramerateLimit(rpg->window, rpg->fps);
    event_bindings(rpg);
}

void option_event(rpg_t *rpg)
{
    if (POS.x >= 310 && POS.x <= 522 && POS.y >= 470 && POS.y <= 535) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            play_sound(rpg->clic.sound, rpg);
            rpg->menu = 0;
        }
    }
    if (POS.x >= 212 && POS.x <= 256 && POS.y >= 378 && POS.y <= 422) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            play_sound(rpg->clic.sound, rpg);
            rpg->fps = 30;
        }
    }
    if (POS.x >= 270 && POS.x <= 315 && POS.y >= 378 && POS.y <= 422) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            play_sound(rpg->clic.sound, rpg);
            rpg->fps = 60;
        }
    }
    option_event2(rpg);
}

void menu_event_gestion2(rpg_t *rpg)
{
    if (POS.x >= 620 && POS.x <= 770 && POS.y >= 505 && POS.y <= 550) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            play_sound(rpg->clic.sound, rpg);
            rpg->menu = 3;
        }
    }
    if (POS.x >= 40 && POS.x <= 235 && POS.y >= 45 && POS.y <= 105) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            play_sound(rpg->clic.sound, rpg);
            rpg->menu = 0;
        }
    }
    if (POS.x >= 65 && POS.x <= 222 && POS.y >= 505 && POS.y <= 550) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(rpg->window);
    }
}

void menu_event_gestion(rpg_t *rpg)
{
    if (POS.x >= 65 && POS.x <= 222 && POS.y >= 325 && POS.y <= 372) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            play_sound(rpg->clic.sound, rpg);
            rpg->scene = 4;
        }
    }
    if (POS.x >= 65 && POS.x <= 222 && POS.y >= 383 && POS.y <= 429) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            play_sound(rpg->clic.sound, rpg);
            save_load(rpg);
            rpg->scene = 1;
        }
    }
    if (POS.x >= 65 && POS.x <= 222 && POS.y >= 442 && POS.y <= 490) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            play_sound(rpg->clic.sound, rpg);
            rpg->menu = 2;
        }
    }
    menu_event_gestion2(rpg);
}