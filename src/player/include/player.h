/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <rpg.h>

void display_attack(rpg_t *rpg);
void display_player(rpg_t *rpg);
void change_alpha(rpg_t *rpg, int alpha);
void player_hit(rpg_t *rpg, int damage);
void anim_hit(rpg_t *rpg);
void create_perso2(rpg_t *rpg);
void create_perso(rpg_t *rpg);
void create_player(rpg_t *rpg);
void load_xp_life_bar(rpg_t *rpg);
void attack_enemies(rpg_t *rpg);
void destroy_assets(rpg_t *rpg, enemies_t *temp2);
void kill_enemy(rpg_t *rpg, enemies_t **enemy, int index);
void get_attack_pos(rpg_t *rpg);
void enemy_hitted(rpg_t *rpg, enemies_t **enemy);
void gain_xp(rpg_t *rpg, enemies_t **enemy);
void anim_attack(rpg_t *rpg);
void player_attack(rpg_t *rpg);
void load_eyes(sfTexture **eyes);
void load_hairs(sfTexture **hairs);
void change_rects(rpg_t *rpg);
void check_anim_clock(rpg_t *rpg, int top);
void player_movements2(rpg_t *rpg);
void player_movements(rpg_t *rpg);
int check_move(rpg_t *rpg, sfVector2f pos, char **map);
sfVector2f get_player_move_position(rpg_t *rpg, int x, int y, sfSprite *sp);
void player_move_up(rpg_t *rpg, sfSprite *map,
char **collisions, int which);
void player_move(rpg_t *rpg, sfSprite *map, char **collisions, int which);
void player_move_horizontal(rpg_t *rpg, sfSprite *map, char **collisions,
int which);
void load_paints(sfTexture **paints);
void load_pants(sfTexture **pants);
sfVector2f get_player_position(rpg_t *rpg, int x, int y);
void load_skins(sfTexture **skins);
void load_vests(sfTexture **vests);

#endif /* !__RPG_H__ */