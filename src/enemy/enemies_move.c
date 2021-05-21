/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** enemies move
*/

#include <rpg.h>
#include <math.h>

sfVector2f get_enemy_move_position(rpg_t *rpg, int x, int y, sprite_t sp)
{
    sfVector2u size = sfTexture_getSize(sp.texture);
    sfVector2f pos1 = sp.position;
    sfVector2f pos;
    int speed = 10;

    pos1.x += size.x / 6;
    pos1.y += size.y / 4 - 10;
    if (y == 1)
        pos1.y += 10;
    pos.x = (pos1.x + (x * (speed + 10))) / 32;
    pos.y = (pos1.y + (y * speed)) / 32;
    return (pos);
}

int check_e_clock(rpg_t *rpg, int top, enemies_t *enemy, float time)
{
    sfVector2u size = sfTexture_getSize(enemy->sp.texture);

    rpg->time = sfClock_getElapsedTime(enemy->sp.clock);
    if (rpg->time.microseconds / 1000000.0 >= time) {
        sfClock_restart(enemy->sp.clock);
        enemy->sp.rect.top = size.y / 4 * top;
        return (1);
    }
    return (0);
}

int range_e_p(rpg_t *rpg, enemies_t *enemy, int action, int dist)
{
    sfVector2f p_pos = get_player_move_position(rpg, 0, 0,
    rpg->map.cave_ground.sprite);
    sfVector2f e_pos = get_enemy_move_position(rpg, 0, 0, enemy->sp);
    sfVector2f pos = (sfVector2f) {p_pos.x - e_pos.x, p_pos.y - e_pos.y};

    pos.x = (pos.x < 0) ? pos.x * -1 : pos.x;
    pos.y = (pos.y < 0) ? pos.y * -1 : pos.y;
    if ((enemy->type == 1 || enemy->type == 3) &&
    sqrt(pos.x * pos.x + pos.y * pos.y) < dist) {
        if (action == 1)
            move_enemy_to_player(rpg, enemy, p_pos, e_pos);
        return (1);
    }
    if (enemy->type == 2 && sqrt(pos.x * pos.x + pos.y * pos.y) < 4) {
        if (action == 1)
            move_enemy_back_player(rpg, enemy, p_pos, e_pos);
        return (1);
    }
    return (0);
}

void move_rand(rpg_t *rpg, enemies_t *temp)
{
    int move = 0;
    int speed = 10;

    move = rand() % 4;
    if (move == 0 && check_move(rpg, get_enemy_move_position(rpg, -1, 0,
    temp->sp), rpg->map.cave_col) == 0 && check_e_clock(rpg, 1, temp, 1) == 1)
        temp->sp.position.x -= speed;
    if (move == 1 && check_move(rpg, get_enemy_move_position(rpg, 1, 0,
    temp->sp), rpg->map.cave_col) == 0 && check_e_clock(rpg, 2, temp, 1) == 1)
        temp->sp.position.x += speed;
    if (move == 2 && check_move(rpg, get_enemy_move_position(rpg, 0, -1,
    temp->sp), rpg->map.cave_col) == 0 && check_e_clock(rpg, 3, temp, 1) == 1)
        temp->sp.position.y -= speed;
    if (move == 3 && check_move(rpg, get_enemy_move_position(rpg, 0, 1,
    temp->sp), rpg->map.cave_col) == 0 && check_e_clock(rpg, 0, temp, 1) == 1)
        temp->sp.position.y += speed;
    temp = temp->next;
}

void move_enemies(rpg_t *rpg)
{
    enemies_t *temp = rpg->enemies;

    while (temp) {
        if (temp->type == 1 && range_e_p(rpg, temp, 1, 3) == 0)
            move_rand(rpg, temp);
        if (temp->type == 2 && range_e_p(rpg, temp, 1, 3) == 0)
            move_rand(rpg, temp);
        if (temp->type == 3 && range_e_p(rpg, temp, 1, 5) == 0)
            move_rand(rpg, temp);
        temp = temp->next;
    }
}