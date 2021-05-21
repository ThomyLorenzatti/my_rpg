/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __INITIALISATION_H__
#define __INITIALISATION_H__

#include <rpg.h>

bool key_exist(rpg_t *rpg);
bool key_true(rpg_t *rpg);
void update_text(rpg_t *rpg, text_t *node, int key);
void display_keys(rpg_t *rpg);
void event_bindings(rpg_t *rpg);
void create_game(rpg_t *rpg);
void create_map(rpg_t *rpg);
void get_collisions(rpg_t *rpg);
void get_collisions_house(rpg_t *rpg);
void get_collisions_cave(rpg_t *rpg);
void get_collisions_boss(rpg_t *rpg);
void create_rpg(rpg_t *rpg);
rpg_t *get_main_struct(int check);
void create_npcs(rpg_t *rpg);
void create_talk(rpg_t *rpg);
void init_game3(rpg_t *rpg);
void init_game2(rpg_t *rpg);
void init_game(rpg_t *rpg);
void display_sprite(sfRenderWindow *window, sprite_t *sprite, float x, float y);
sprite_t init_sprite(sfIntRect rect, char *path);
sfIntRect init_rect(int top, int left, int width, int height);
void move_rect(sfIntRect* rect, float offset);

#endif /* !__RPG_H__ */