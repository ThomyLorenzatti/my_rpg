/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** custom arrow 2
*/

#include <rpg.h>

void draw_arrows_click2(rpg_t *rpg)
{
    if (POS.x >= 284 && POS.x <= 315 && POS.y >= 415 && POS.y <= 448) {
        display_sprite(rpg->window, &rpg->arr_cd, 282, 415);
        rpg->player.i_skin++;
    } else if (POS.x >= 284 && POS.x <= 315 && POS.y >= 503 && POS.y <= 536) {
        display_sprite(rpg->window, &rpg->arr_cd, 282, 501);
        rpg->player.i_paint++;
    }
}

void draw_arrows_click_left2(rpg_t *rpg)
{
    if (POS.x >= 68 && POS.x <= 105 && POS.y >= 415 && POS.y <= 448) {
        display_sprite(rpg->window, &rpg->arr_cg, 68, 415);
        rpg->player.i_skin--;
    } else if (POS.x >= 68 && POS.x <= 105 && POS.y >= 503 && POS.y <= 536) {
        display_sprite(rpg->window, &rpg->arr_cg, 68, 502);
        rpg->player.i_paint--;
    }
}