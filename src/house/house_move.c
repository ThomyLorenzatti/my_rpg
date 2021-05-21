/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** house movement
*/

#include <rpg.h>

sfVector2f get_player_move_position_h(rpg_t *rpg, int x, int y)
{
    sfVector2u size = sfTexture_getSize(rpg->player.player.texture);
    sfVector2f pos1 = sfSprite_getPosition(rpg->player.player.sprite);
    sfVector2f pos2 = (sfVector2f) {160, 60};
    sfVector2f pos;
    int speed = rpg->player.vspeed;

    pos1.x += size.x / 6;
    pos1.y += size.y / 4 - 10;
    if (y == 1 || y == 0)
        pos1.y += 10;
    pos.x = (pos1.x + (x * (speed + 15)) + (pos2.x * -1)) / 32;
    pos.y = (pos1.y + (y * (speed + 5)) + (pos2.y * -1)) / 32;
    return (pos);
}

int check_move_h(rpg_t *rpg, sfVector2f pos)
{
    if (my_char_in_str(rpg->house.collisions[(int) pos.y]
    [(int) pos.x], " 2") == 1)
        return (0);
    return (1);
}

void player_move_house_hor(rpg_t *rpg, int speed)
{
    sfVector2f pos;

    if (rpg->player.move == -2) {
        pos = get_player_move_position_h(rpg, -1, 0);
        if (check_move_h(rpg, pos) == 0)
            sfSprite_move(rpg->player.player.sprite, (sfVector2f) {-speed, 0});
    }
    if (rpg->player.move == 2) {
        pos = get_player_move_position_h(rpg, 1, 0);
        if (check_move_h(rpg, pos) == 0)
            sfSprite_move(rpg->player.player.sprite, (sfVector2f) {speed, 0});
    }
}

void player_move_house(rpg_t *rpg)
{
    sfVector2f pos;
    int speed = 3;

    if (rpg->player.move == -1) {
        pos = get_player_move_position_h(rpg, 0, 1);
        if (check_move_h(rpg, pos) == 0)
            sfSprite_move(rpg->player.player.sprite, (sfVector2f) {0, speed});
    }
    if (rpg->player.move == 1) {
        pos = get_player_move_position_h(rpg, 0, -1);
        if (check_move_h(rpg, pos) == 0)
            sfSprite_move(rpg->player.player.sprite, (sfVector2f) {0, -speed});
    }
    player_move_house_hor(rpg, speed);
    rpg->player.player.position =
    sfSprite_getPosition(rpg->player.player.sprite);
    return;
}
