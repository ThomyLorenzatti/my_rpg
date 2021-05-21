/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw cave
*/

#include <rpg.h>

void draw_cave2(rpg_t *rpg)
{
    display_bars(rpg);
    draw_inventory(rpg);
    draw_skilltab(rpg);
}

void draw_cave(rpg_t *rpg)
{
    sfVector2f pos =
    get_player_move_position(rpg, 0, 0, rpg->map.cave_wall.sprite);

    display_sprite(rpg->window, &rpg->map.back, 0, 0);
    display_sprite(rpg->window, &rpg->map.cave_ground,
    rpg->map.cave_wall.position.x,
    rpg->map.cave_wall.position.y);
    display_sprite(rpg->window, &rpg->map.cave_wall,
    rpg->map.cave_wall.position.x,
    rpg->map.cave_wall.position.y);
    display_player(rpg);
    display_enemies(rpg);
    draw_particules_eng(rpg);
    if (rpg->map.cave_col[(int) pos.y][(int) pos.x + 1] == 'E' ||
    rpg->map.cave_col[(int) pos.y - 1][(int) pos.x] == 'N')
        display_sprite(rpg->window, &rpg->player.e,
        rpg->player.player.position.x + 30,
        rpg->player.player.position.y - 30);
    draw_cave2(rpg);
}