/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __GAME_H__
#define __GAME_H__

#include <rpg.h>

void init_cinema(rpg_t *rpg);
void text_positions(rpg_t *rpg);
void draw_cinema2(rpg_t *rpg);
void draw_cinema(rpg_t *rpg);
void cine_checker(rpg_t *rpg);
cursor_t create_cursor(void);
cursor_t update_cursor(const sfRenderWindow *window, cursor_t cursor);
void display_cursor(sfRenderWindow *window, const cursor_t cursor);
void destroy_cursor(rpg_t *rpg);
void draw_boat(rpg_t *rpg);
void draw_game2(rpg_t *rpg, sfVector2i pos);
void draw_game(rpg_t *rpg);
void draw_scene2(rpg_t *rpg);
void draw_scene(rpg_t *rpg);
void end_init(rpg_t *rpg);
void end_event(rpg_t *rpg);
void end_draw(rpg_t *rpg);
void event_game3(rpg_t *rpg, sfMouseButtonEvent mouse);
void event_game2(rpg_t *rpg, sfMouseButtonEvent mouse);
void event_game(rpg_t *rpg, sfMouseButtonEvent mouse);
void init_gover(rpg_t *rpg);
void gover_event(rpg_t *rpg);
void draw_gover(rpg_t *rpg);
void init_hunt(rpg_t *rpg);
void draw_hunt(rpg_t *rpg);
void event_hunt(rpg_t *rpg);
void init_market(rpg_t *rpg);
void event_market2(rpg_t *rpg);
void event_market(rpg_t *rpg);
void draw_market2(rpg_t *rpg);
void draw_market(rpg_t *rpg);
void move_map(rpg_t *rpg, int x, int y, int which);
void init_pause(rpg_t *rpg);
void draw_pause2(rpg_t *rpg);
void draw_pause(rpg_t *rpg);
void pause_event2(rpg_t *rpg);
void pause_event(rpg_t *rpg);

#endif /* !__RPG_H__ */