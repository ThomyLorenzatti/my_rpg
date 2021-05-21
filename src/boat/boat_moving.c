/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** boat moving
*/

#include <rpg.h>

sfVector2f get_boat_move_pos(rpg_t *rpg, int x, int y)
{
    sfVector2u size = sfTexture_getSize(rpg->game.boat.texture);
    sfVector2f pos1 = sfSprite_getPosition(rpg->game.boat.sprite);
    sfVector2f pos2 = sfSprite_getPosition(rpg->map.layer1.sprite);
    sfVector2f pos;
    int speed = rpg->player.vspeed;

    pos1.x += size.x / 31 / 2;
    pos1.y += size.y / 3 - 10;
    if (y == 1)
        pos1.y += 10;
    if (y == -1)
        pos1.y -= 15;
    pos.x = (pos1.x + (x * (speed + 10)) + (pos2.x * -1)) / 32;
    pos.y = (pos1.y + (y * speed) + (pos2.y * -1)) / 32;
    return (pos);
}

void boat_move_ver(rpg_t *rpg, sfVector2f temp, int speed, sfVector2f pos)
{
    if (rpg->player.move == 1)
        pos = get_boat_move_pos(rpg, 0, -1);
    if (rpg->player.move == 1 && temp.y >= 150 &&
    check_move(rpg, pos, rpg->map.collisions) == 0)
        rpg->game.boat.position.y += -speed;
    else if (rpg->player.move == 1 &&
    check_move(rpg, pos, rpg->map.collisions) == 0) {
        rpg->game.boat.position.y += -speed;
        move_map(rpg, 0, speed, 0);
    }
    if (rpg->player.move == -1)
        pos = get_boat_move_pos(rpg, 0, 1);
    if (rpg->player.move == -1 && temp.y <= 350 &&
    check_move(rpg, pos, rpg->map.collisions) == 0)
        rpg->game.boat.position.y += speed;
    else if (rpg->player.move == -1 &&
    check_move(rpg, pos, rpg->map.collisions) == 0) {
        rpg->game.boat.position.y += speed;
        move_map(rpg, 0, -speed, 0);
    }
}

void boat_move_up(rpg_t *rpg, sfVector2f pos, sfVector2f temp, int speed)
{
    if (rpg->player.move == 2)
        pos = get_boat_move_pos(rpg, 1, 0);
    if (rpg->player.move == 2 && temp.x <= 550 &&
    check_move(rpg, pos, rpg->map.collisions) == 0)
        rpg->game.boat.position.x += speed;
    else if (rpg->player.move == 2 &&
    check_move(rpg, pos, rpg->map.collisions) == 0) {
        rpg->game.boat.position.x += speed;
        move_map(rpg, -speed, 0, 0);
    }
}

void boat_move_hor(rpg_t *rpg, sfVector2f pos, sfVector2f temp, int speed)
{
    rpg->map.layer1.position = sfSprite_getPosition(rpg->map.layer1.sprite);
    if (rpg->player.move == -2)
        pos = get_boat_move_pos(rpg, -1, 0);
    if (rpg->player.move == -2 && temp.x >= 200 &&
    check_move(rpg, pos, rpg->map.collisions) == 0)
        rpg->game.boat.position.x += -speed;
    else if (rpg->player.move == -2 &&
    check_move(rpg, pos, rpg->map.collisions) == 0) {
        rpg->game.boat.position.x += -speed;
        move_map(rpg, speed, 0, 0);
    }
    boat_move_up(rpg, pos, temp, speed);
    boat_move_ver(rpg, temp, speed, pos);
}

void boat_moving(rpg_t *rpg)
{
    sfVector2f pos;
    sfVector2f temp = sfSprite_getPosition(rpg->game.boat.sprite);
    int speed = 8;

    rpg->time = sfClock_getElapsedTime(rpg->player.moved);
    if (!(rpg->time.microseconds / 1000000.0 > 0.02))
        return;
    else
        sfClock_restart(rpg->player.moved);
    boat_move_hor(rpg, pos, temp, speed);
}