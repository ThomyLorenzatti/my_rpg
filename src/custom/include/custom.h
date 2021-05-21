/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __CUSTOM_H__
#define __CUSTOM_H__

#include <rpg.h>

void draw_arrows_hover_left(rpg_t *rpg);
void draw_arrows_hover(rpg_t *rpg);
void draw_arrows_click_left(rpg_t *rpg);
void draw_arrows_click(rpg_t *rpg);
void draw_arrows_click2(rpg_t *rpg);
void draw_arrows_click_left2(rpg_t *rpg);
void check_index_parts2(rpg_t *rpg);
void check_index_parts(rpg_t *rpg);
void change_parts(rpg_t *rpg);
void init_custom(rpg_t *rpg);
void custom_event(rpg_t *rpg);
void draw_player_parts(rpg_t *rpg);
void draw_custom(rpg_t *rpg);

#endif /* !__RPG_H__ */