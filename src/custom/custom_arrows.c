/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** custom arrows
*/

#include <rpg.h>

void draw_arrows_hover_left(rpg_t *rpg)
{
    if (POS.x >= 79 && POS.x <= 105 && POS.y >= 88 && POS.y <= 120)
        display_sprite(rpg->window, &rpg->arr_hg, 79, 88);
    if (POS.x >= 77 && POS.x <= 105 && POS.y >= 166 && POS.y <= 198)
        display_sprite(rpg->window, &rpg->arr_hg, 77, 166);
    if (POS.x >= 73 && POS.x <= 105 && POS.y >= 253 && POS.y <= 285)
        display_sprite(rpg->window, &rpg->arr_hg, 73, 254);
    if (POS.x >= 73 && POS.x <= 105 && POS.y >= 333 && POS.y <= 366)
        display_sprite(rpg->window, &rpg->arr_hg, 73, 332);
    if (POS.x >= 68 && POS.x <= 105 && POS.y >= 415 && POS.y <= 448)
        display_sprite(rpg->window, &rpg->arr_hg, 68, 415);
    if (POS.x >= 68 && POS.x <= 105 && POS.y >= 503 && POS.y <= 536)
        display_sprite(rpg->window, &rpg->arr_hg, 68, 502);
}

void draw_arrows_hover(rpg_t *rpg)
{
    if (POS.x >= 292 && POS.x <= 315 && POS.y >= 88 && POS.y <= 120)
        display_sprite(rpg->window, &rpg->arr_hd, 293, 88);
    if (POS.x >= 292 && POS.x <= 315 && POS.y >= 166 && POS.y <= 198)
        display_sprite(rpg->window, &rpg->arr_hd, 291, 166);
    if (POS.x >= 288 && POS.x <= 315 && POS.y >= 253 && POS.y <= 285)
        display_sprite(rpg->window, &rpg->arr_hd, 287, 254);
    if (POS.x >= 288 && POS.x <= 315 && POS.y >= 333 && POS.y <= 366)
        display_sprite(rpg->window, &rpg->arr_hd, 287, 332);
    if (POS.x >= 284 && POS.x <= 315 && POS.y >= 415 && POS.y <= 448)
        display_sprite(rpg->window, &rpg->arr_hd, 282, 415);
    if (POS.x >= 284 && POS.x <= 315 && POS.y >= 503 && POS.y <= 536)
        display_sprite(rpg->window, &rpg->arr_hd, 282, 501);
    draw_arrows_hover_left(rpg);
}

void draw_arrows_click_left(rpg_t *rpg)
{
    if (POS.x >= 79 && POS.x <= 105 && POS.y >= 88 && POS.y <= 120) {
        display_sprite(rpg->window, &rpg->arr_cg, 79, 88);
        rpg->player.i_hair--;
    } else if (POS.x >= 77 && POS.x <= 105 && POS.y >= 166 && POS.y <= 198) {
        display_sprite(rpg->window, &rpg->arr_cg, 77, 166);
        rpg->player.i_eye--;
    }
    if (POS.x >= 73 && POS.x <= 105 && POS.y >= 253 && POS.y <= 285) {
        display_sprite(rpg->window, &rpg->arr_cg, 73, 254);
        rpg->player.i_vest--;
    } else if (POS.x >= 73 && POS.x <= 105 && POS.y >= 333 && POS.y <= 366) {
        display_sprite(rpg->window, &rpg->arr_cg, 73, 332);
        rpg->player.i_pant--;
    }
    draw_arrows_click_left2(rpg);
}

void draw_arrows_click(rpg_t *rpg)
{
    if (POS.x >= 292 && POS.x <= 315 && POS.y >= 88 && POS.y <= 120) {
        display_sprite(rpg->window, &rpg->arr_cd, 293, 88);
        rpg->player.i_hair++;
    } else if (POS.x >= 292 && POS.x <= 315 && POS.y >= 166 && POS.y <= 198) {
        display_sprite(rpg->window, &rpg->arr_cd, 291, 166);
        rpg->player.i_eye++;
    }
    if (POS.x >= 288 && POS.x <= 315 && POS.y >= 253 && POS.y <= 285) {
        display_sprite(rpg->window, &rpg->arr_cd, 287, 254);
        rpg->player.i_vest++;
    } else if (POS.x >= 288 && POS.x <= 315 && POS.y >= 333 && POS.y <= 366) {
        display_sprite(rpg->window, &rpg->arr_cd, 287, 332);
        rpg->player.i_pant++;
    }
    draw_arrows_click2(rpg);
}