/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** player moving
*/

#include <rpg.h>

int check_move(rpg_t *rpg, sfVector2f pos, char **map)
{
    if (my_char_in_str(map[(int) pos.y][(int) pos.x], " 2B") == 1)
        return (0);
    return (1);
}

sfVector2f get_player_move_position(rpg_t *rpg, int x, int y, sfSprite *sp)
{
    sfVector2u size = sfTexture_getSize(rpg->player.player.texture);
    sfVector2f pos1 = sfSprite_getPosition(rpg->player.player.sprite);
    sfVector2f pos2 = sfSprite_getPosition(sp);
    sfVector2f pos;
    int speed = rpg->player.vspeed;

    pos1.x += size.x / 6;
    pos1.y += size.y / 4 - 10;
    if (y == 1 || y == 0)
        pos1.y += 10;
    pos.x = (pos1.x + (x * (speed + 10)) + (pos2.x * -1)) / 32;
    pos.y = (pos1.y + (y * speed) + (pos2.y * -1)) / 32;
    return (pos);
}

void player_move_up(rpg_t *rpg, sfSprite *map,
char **collisions, int which)
{
    int speed = rpg->player.vspeed;
    sfVector2f pos;

    if (rpg->player.move == 1)
        pos = get_player_move_position(rpg, 0, -1, map);
    if (rpg->player.move == 1 && rpg->player.player.position.y >= 150 &&
    check_move(rpg, pos, collisions) == 0)
        sfSprite_move(rpg->player.player.sprite, (sfVector2f) {0, -speed});
    else if (rpg->player.move == 1 && check_move(rpg, pos, collisions) == 0)
        move_map(rpg, 0, speed, which);
}

void player_move(rpg_t *rpg, sfSprite *map, char **collisions, int which)
{
    sfVector2f pos;
    int speed = rpg->player.vspeed;

    rpg->time = sfClock_getElapsedTime(rpg->player.moved);
    if (!(rpg->time.microseconds / 1000000.0 > 0.02))
        return;
    else
        sfClock_restart(rpg->player.moved);
    rpg->map.layer1.position = sfSprite_getPosition(map);
    if (rpg->player.move == -1)
        pos = get_player_move_position(rpg, 0, 1, map);
    if (rpg->player.move == -1 && rpg->player.player.position.y <= 350 &&
    check_move(rpg, pos, collisions) == 0)
        sfSprite_move(rpg->player.player.sprite, (sfVector2f) {0, speed});
    else if (rpg->player.move == -1 && check_move(rpg, pos, collisions) == 0)
        move_map(rpg, 0, -speed, which);
    player_move_up(rpg, map, collisions, which);
    player_move_horizontal(rpg, map, collisions, which);
    rpg->player.player.position =
    sfSprite_getPosition(rpg->player.player.sprite);
}

void player_move_horizontal(rpg_t *rpg, sfSprite *map, char **collisions,
int which)
{
    sfVector2f pos;
    int speed = rpg->player.vspeed;

    if (rpg->player.move == -2)
        pos = get_player_move_position(rpg, -1, 0, map);
    if (rpg->player.move == -2 && rpg->player.player.position.x >= 200 &&
    check_move(rpg, pos, collisions) == 0)
        sfSprite_move(rpg->player.player.sprite, (sfVector2f) {-speed, 0});
    else if (rpg->player.move == -2 && check_move(rpg, pos, collisions) == 0)
        move_map(rpg, speed, 0, which);
    if (rpg->player.move == 2)
        pos = get_player_move_position(rpg, 1, 0, map);
    if (rpg->player.move == 2 && rpg->player.player.position.x <= 550 &&
    check_move(rpg, pos, collisions) == 0)
        sfSprite_move(rpg->player.player.sprite, (sfVector2f) {speed, 0});
    else if (rpg->player.move == 2 && check_move(rpg, pos, collisions) == 0)
        move_map(rpg, -speed, 0, which);
}