/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __HOUSE_H__
#define __HOUSE_H__

#include <rpg.h>

void house_door_locked(rpg_t *rpg);
void house_door_unlocked(rpg_t *rpg);
void close_door(rpg_t *rpg);
void anim_door(rpg_t *rpg);
void display_house_interact(rpg_t *rpg);
void draw_house(rpg_t *rpg);
sfVector2i get_position_house(rpg_t *rpg, int x, int y);
void quit_house(rpg_t *rpg);
void chess_house(rpg_t *rpg, sfVector2i pos);
void check_quest(rpg_t *rpg);
void event_house(rpg_t *rpg);
sfVector2f get_player_move_position_h(rpg_t *rpg, int x, int y);
int check_move_h(rpg_t *rpg, sfVector2f pos);
void player_move_house_hor(rpg_t *rpg, int speed);
void player_move_house(rpg_t *rpg);
void init_house(rpg_t *rpg);

#endif /* !__RPG_H__ */