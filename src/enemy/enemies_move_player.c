/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** enemies move player
*/

#include <rpg.h>

void move_enemy_to_player(rpg_t *rpg, enemies_t *enemy,
sfVector2f p_pos, sfVector2f e_pos)
{
    int speed = 2;

    if (e_pos.x - p_pos.x < -0.5 && check_e_clock(rpg, 2, enemy, 0.05) == 1)
        enemy->sp.position.x += speed;
    else if (e_pos.x - p_pos.x > 0.5 && check_e_clock(rpg, 1, enemy, 0.05) == 1)
        enemy->sp.position.x -= speed;
    if (e_pos.y - p_pos.y < -0.1 && check_e_clock(rpg, 0, enemy, 0.05) == 1)
        enemy->sp.position.y += speed;
    else if (e_pos.y - p_pos.y > 0.1 && check_e_clock(rpg, 3, enemy, 0.05) == 1)
        enemy->sp.position.y -= speed;
}

void move_enemy_back_player_x(rpg_t *rpg, enemies_t *enemy,
sfVector2f p_pos, sfVector2f e_pos)
{
    int speed = 2;

    if (e_pos.x - p_pos.x < -0.5 && check_move(rpg, get_enemy_move_position(rpg,
    -1, 0, enemy->sp), rpg->map.cave_col) == 0 &&
    check_e_clock(rpg, 2, enemy, 0.05) == 1) {
        enemy->sp.position.x -= speed;
    } else if (e_pos.x - p_pos.x > 0.5 && check_move(rpg,
    get_enemy_move_position(rpg, 1, 0, enemy->sp), rpg->map.cave_col) == 0 &&
    check_e_clock(rpg, 1, enemy, 0.05) == 1) {
        enemy->sp.position.x += speed;
    }
}

void move_enemy_back_player(rpg_t *rpg, enemies_t *enemy,
sfVector2f p_pos, sfVector2f e_pos)
{
    int speed = 2;

    move_enemy_back_player_x(rpg, enemy, p_pos, e_pos);
    if (e_pos.y - p_pos.y < -0.1 && check_move(rpg, get_enemy_move_position(rpg,
    0, -1, enemy->sp), rpg->map.cave_col) == 0 &&
    check_e_clock(rpg, 0, enemy, 0.05) == 1)
        enemy->sp.position.y -= speed;
    else if (e_pos.y - p_pos.y > 0.1 && check_move(rpg,
    get_enemy_move_position(rpg, 0, 1, enemy->sp), rpg->map.cave_col) == 0 &&
    check_e_clock(rpg, 3, enemy, 0.05) == 1)
        enemy->sp.position.y += speed;
}