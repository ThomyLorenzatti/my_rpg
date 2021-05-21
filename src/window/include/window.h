/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <rpg.h>

sfRenderWindow *create_window(int width, int height, char *title, int bpp);
void draw_map(rpg_t *rpg);
void draw_props(rpg_t *rpg);
void display_bars(rpg_t *rpg);

#endif /* !__RPG_H__ */