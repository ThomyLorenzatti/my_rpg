/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __BOAT_H__
#define __BOAT_H__

#include <rpg.h>

void player_new_pos(rpg_t *rpg, int x, int y);
void move_screen(rpg_t *rpg);
void boat_events(rpg_t *rpg);
void check_deboat(rpg_t *rpg, sfVector2i b_pos);
void boat_move(rpg_t *rpg);
sfVector2f get_boat_move_pos(rpg_t *rpg, int x, int y);
void boat_move_ver(rpg_t *rpg, sfVector2f temp, int speed, sfVector2f pos);
void boat_move_up(rpg_t *rpg, sfVector2f pos, sfVector2f temp, int speed);
void boat_move_hor(rpg_t *rpg, sfVector2f pos, sfVector2f temp, int speed);
void boat_moving(rpg_t *rpg);
sfVector2i get_boat_pos(rpg_t *rpg);
void draw_reboat(rpg_t *rpg);

#endif /* !__RPG_H__ */