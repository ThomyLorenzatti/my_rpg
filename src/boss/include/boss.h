/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __BOSS_H__
#define __BOSS_H__

#include <rpg.h>

void anim_boss(rpg_t *rpg);
int check_boss_att_clock(rpg_t *rpg, sfClock *clock);
void check_attack_to_player(rpg_t *rpg);
void boss_attack2(rpg_t *rpg, sfVector2f p_pos, sfVector2f b_pos);
void boss_attack(rpg_t *rpg);
void check_player_ball(rpg_t *rpg, sfVector2f b_pos);
void draw_ball(rpg_t *rpg, sprite_t *sp, int x, int y);
int check_ball_clock(rpg_t *rpg, sfClock *clock);
void fire_ball(rpg_t *rpg);
void boss_death(rpg_t *rpg);
void boss_hitted(rpg_t *rpg);
int check_bmove(rpg_t *rpg);
void check_hitted_boss(rpg_t *rpg);
void boss_move(rpg_t *rpg);
void display_boss(rpg_t *rpg);
void draw_boss(rpg_t *rpg);

#endif /* !__RPG_H__ */