/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get boat pos
*/

#include <rpg.h>

sfVector2i get_boat_pos(rpg_t *rpg)
{
    sfVector2f map = rpg->map.layer1.position;
    sfVector2f boat = rpg->game.boat.position;
    sfVector2i pos;

    pos.x = (boat.x + 28) + map.x;
    pos.y = (boat.y + 35) + map.y;
    return (pos);
}