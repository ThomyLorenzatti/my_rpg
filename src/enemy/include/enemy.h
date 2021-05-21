/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <rpg.h>

void destroy_all_enemies(rpg_t *rpg);
void create_enemies(rpg_t *rpg);
void push_back_enemy2(rpg_t *rpg, enemies_t **list, char **data);
void push_back_enemy(rpg_t *rpg, enemies_t **list, char *enemy);
void display_npcs(rpg_t *rpg);
void display_enemy(rpg_t *rpg, enemies_t *temp);
void display_enemies(rpg_t *rpg);
void check_damage(rpg_t *rpg, sprite_t sp, enemies_t *temp);
void move_enemy_to_player(rpg_t *rpg, enemies_t *enemy,
sfVector2f p_pos, sfVector2f e_pos);
void move_enemy_back_player(rpg_t *rpg, enemies_t *enemy,
sfVector2f p_pos, sfVector2f e_pos);
sfVector2f get_enemy_move_position(rpg_t *rpg, int x, int y, sprite_t sp);
int check_e_clock(rpg_t *rpg, int top, enemies_t *enemy, float time);
int range_e_p(rpg_t *rpg, enemies_t *enemy, int action, int dist);
void move_rand(rpg_t *rpg, enemies_t *temp);
void move_enemies(rpg_t *rpg);
sfVector2f get_dir_ball(rpg_t *rpg, sfVector2f p_pos, sfVector2f e_pos,
sfVector2f dir);
void enemy_fire_ball(rpg_t *rpg, enemies_t *temp);
sfVector2f get_dir_swoosh(rpg_t *rpg, sfVector2f e_pos,
sfVector2f dir, enemies_t *temp);
void enemy_swoosh(rpg_t *rpg, enemies_t *temp);
void enemies_damages(rpg_t *rpg);

#endif /* !__RPG_H__ */