/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw boat
*/

#include <rpg.h>

void draw_reboat(rpg_t *rpg)
{
    sfVector2i pos;

    if (rpg->game.is_boat == 2) {
        pos = get_boat_pos(rpg);
        pos.x /= 32;
        pos.y /= 32;
        if (rpg->map.collisions[pos.y][pos.x] == '2')
            draw_boat(rpg);
    }
}