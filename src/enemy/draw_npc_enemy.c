/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw npcs and enemies
*/

#include <rpg.h>

void display_npcs(rpg_t *rpg)
{
    if (rpg->game.quest < 2)
        display_sprite(rpg->window, &rpg->npcs.sp1, rpg->map.layer1.position.x
        + 142 * 32 - 5, rpg->map.layer1.position.y + 157 * 32 - 16);
    else {
        display_sprite(rpg->window, &rpg->npcs.sp1, rpg->map.layer1.position.x
        + 165 * 32 - 5, rpg->map.layer1.position.y + 177 * 32 - 16);
        display_sprite(rpg->window, &rpg->npcs.sp4, rpg->map.layer1.position.x
        + 140 * 32 - 5, rpg->map.layer1.position.y + 159 * 32 - 16);
    }
    display_sprite(rpg->window, &rpg->npcs.sp2, rpg->map.layer1.position.x
    + 157 * 32 - 5, rpg->map.layer1.position.y + 168 * 32 - 16);
    display_sprite(rpg->window, &rpg->npcs.sp3, rpg->map.layer1.position.x
    + 154 * 32 - 5, rpg->map.layer1.position.y + 175 * 32 - 16);
}

void display_enemy(rpg_t *rpg, enemies_t *temp)
{
    sfVector2f save;

    save = temp->sp.position;
    display_sprite(rpg->window, &temp->sp,
    rpg->map.cave_wall.position.x + save.x,
    rpg->map.cave_wall.position.y + save.y);
    temp->sp.position = save;
    if (temp->type == 2) {
        save = temp->att.position;
        display_sprite(rpg->window, &temp->att,
        rpg->map.cave_wall.position.x + save.x,
        rpg->map.cave_wall.position.y + save.y);
        temp->att.position = save;
    } else if (temp->type == 3 && temp->swoosh == 1) {
        save = temp->att.position;
        display_sprite(rpg->window, &temp->att,
        rpg->map.cave_wall.position.x + temp->sp.position.x + temp->dir.x,
        rpg->map.cave_wall.position.y + temp->sp.position.y + temp->dir.y);
        temp->att.position = save;
    }
}

void display_enemies(rpg_t *rpg)
{
    enemies_t *temp = rpg->enemies;
    sfVector2f p_pos;
    sfVector2f e_pos;

    if (temp == NULL)
        return;
    p_pos = get_player_move_position(rpg, 0, 0, rpg->map.cave_ground.sprite);
    e_pos = get_enemy_move_position(rpg, 0, 0, temp->sp);
    while (temp) {
        display_enemy(rpg, temp);
        if (range_e_p(rpg, temp, 0, 3) == 1 && e_pos.y < p_pos.y)
            display_player(rpg);
        temp = temp->next;
        if (temp)
            e_pos = get_enemy_move_position(rpg, 0, 0, temp->sp);
    }
}