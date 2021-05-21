/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** endgame.c
*/

#include <rpg.h>

void end_init(rpg_t *rpg)
{
    rpg->congrat = init_sprite(init_rect(0, 0, 800, 600), "./res/congrat.png");
    rpg->conquit = init_sprite(init_rect(0, 0, 800, 600),
    "./res/congratquit.png");
}

void end_event(rpg_t *rpg)
{
    if (POS.x >= 300 && POS.x <= 500 && POS.y >= 280 && POS.y <= 340) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            sfRenderWindow_close(rpg->window);
        }
    }
}

void end_draw(rpg_t *rpg)
{
    display_sprite(rpg->window, &rpg->congrat, 0, 0);
    if (POS.x >= 300 && POS.x <= 500 && POS.y >= 280 && POS.y <= 340)
        display_sprite(rpg->window, &rpg->conquit, 0, 0);

}