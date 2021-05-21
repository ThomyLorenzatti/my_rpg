/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** custom.c
*/

#include <rpg.h>

void init_custom(rpg_t *rpg)
{
    rpg->customb = init_sprite(init_rect(0, 0, 800, 600), "./res/custom.png");
    rpg->pcc = init_sprite(init_rect(0, 0, 800, 600), "./res/pcc.png");
    rpg->arr_hd = init_sprite(init_rect(0, 0, 23, 32), "res/arr_hd.png");
    rpg->arr_hg = init_sprite(init_rect(0, 0, 23, 32), "res/arr_hg.png");
    rpg->arr_cd = init_sprite(init_rect(0, 0, 23, 32), "res/arr_cd.png");
    rpg->arr_cg = init_sprite(init_rect(0, 0, 23, 32), "res/arr_cg.png");
    init_gover(rpg);
}

void custom_event(rpg_t *rpg)
{
    rpg->custom_click = 0;
    if (POS.x >= 500 && POS.x <= 660 && POS.y >= 460 && POS.y <= 510)
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
            rpg->scene = 1;
            sfSprite_setScale(rpg->player.skin.sprite, (sfVector2f) {1, 1});
            sfSprite_setScale(rpg->player.pant.sprite, (sfVector2f) {1, 1});
            sfSprite_setScale(rpg->player.vest.sprite, (sfVector2f) {1, 1});
            sfSprite_setScale(rpg->player.paint.sprite, (sfVector2f) {1, 1});
            sfSprite_setScale(rpg->player.eye.sprite, (sfVector2f) {1, 1});
            sfSprite_setScale(rpg->player.hair.sprite, (sfVector2f) {1, 1});
        }
    if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed) {
        draw_arrows_click(rpg);
        draw_arrows_click_left(rpg);
        sfRenderWindow_display(rpg->window);
        rpg->custom_click = 1;
    }
}

void draw_player_parts(rpg_t *rpg)
{
    rpg->player.player.rect.top = 0;
    rpg->player.player.rect.left = 48;
    change_rects(rpg);
    sfSprite_setScale(rpg->player.skin.sprite, (sfVector2f) {6, 6});
    display_sprite(rpg->window, &rpg->player.skin, 435, 120);
    sfSprite_setScale(rpg->player.pant.sprite, (sfVector2f) {6, 6});
    display_sprite(rpg->window, &rpg->player.pant, 435, 120);
    sfSprite_setScale(rpg->player.vest.sprite, (sfVector2f) {6, 6});
    display_sprite(rpg->window, &rpg->player.vest, 435, 120);
    sfSprite_setScale(rpg->player.paint.sprite, (sfVector2f) {6, 6});
    display_sprite(rpg->window, &rpg->player.paint, 435, 120);
    sfSprite_setScale(rpg->player.eye.sprite, (sfVector2f) {6, 6});
    display_sprite(rpg->window, &rpg->player.eye, 435, 120);
    sfSprite_setScale(rpg->player.hair.sprite, (sfVector2f) {6, 6});
    display_sprite(rpg->window, &rpg->player.hair, 435, 120);
}

void draw_custom(rpg_t *rpg)
{
    display_sprite(rpg->window, &rpg->customb, 0, 0);
    if (POS.x >= 500 && POS.x <= 660 && POS.y >= 460 && POS.y <= 510)
        display_sprite(rpg->window, &rpg->pcc, 0, 0);
    if (rpg->custom_click == 0)
        draw_arrows_hover(rpg);
    check_index_parts(rpg);
    change_parts(rpg);
    draw_player_parts(rpg);
}