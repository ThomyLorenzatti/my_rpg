/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** move_map
*/

#include <rpg.h>

void move_map(rpg_t *rpg, int x, int y, int which)
{
    if (which == 0) {
        sfSprite_move(rpg->map.layer1.sprite, (sfVector2f) {x, y});
        sfSprite_move(rpg->map.border.sprite, (sfVector2f) {x, y});
        sfSprite_move(rpg->map.path.sprite, (sfVector2f) {x, y});
        sfSprite_move(rpg->map.houses.sprite, (sfVector2f) {x, y});
        if (y > 0)
            rpg->game.rain.position.y += y;
        if (rpg->game.rain.position.y >= 0 ||
        rpg->game.rain.position.y <= -1216)
            rpg->game.rain.position.y = -608;
    } else if (which == 1) {
        rpg->map.cave_wall.position.x += x;
        rpg->map.cave_wall.position.y += y;
    } else {
        rpg->boss.map.position.x += x;
        rpg->boss.map.position.y += y;
    }
}