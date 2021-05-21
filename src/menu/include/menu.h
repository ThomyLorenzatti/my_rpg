/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __MENU_H__
#define __MENU_H__

#include <rpg.h>

void draw_menu3(rpg_t *rpg);
void draw_menu2(rpg_t *rpg);
void draw_menu(rpg_t *rpg);
void option_event2(rpg_t *rpg);
void option_event(rpg_t *rpg);
void menu_event_gestion2(rpg_t *rpg);
void menu_event_gestion(rpg_t *rpg);
void create_font(text_t *text, char str, int x, int y);
void create_optmenu(rpg_t *rpg);
void create_menu(rpg_t *rpg);
void draw_option2(rpg_t *rpg);
void draw_option(rpg_t *rpg);

#endif /* !__RPG_H__ */