/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** boss move
*/

#include <rpg.h>

int check_bmove(rpg_t *rpg)
{
    rpg->time = sfClock_getElapsedTime(rpg->boss.c_move);
    if (rpg->time.microseconds / 1000000.0 >= 0.05) {
        sfClock_restart(rpg->boss.c_move);
        return (1);
    }
    return (0);
}

void check_hitted_boss(rpg_t *rpg)
{
    sfVector2f b_pos = sfSprite_getPosition(rpg->boss.sp.sprite);
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);

    b_pos.x += 50;
    b_pos.y += 75;
    if (p_pos.x < b_pos.x + 35 && p_pos.x + 32 > b_pos.x &&
    p_pos.y + 48 > b_pos.y && p_pos.y + 24 < b_pos.y + 20)
        if (rpg->player.hitted != 1)
            player_hit(rpg, rpg->boss.attack);
}

void boss_move(rpg_t *rpg)
{
    sfVector2f b_pos = sfSprite_getPosition(rpg->boss.sp.sprite);
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);
    int speed = 2;

    if (rpg->boss.state != 1 && rpg->boss.state != 11)
        return;
    b_pos.x += 50;
    b_pos.y += 75;
    if (b_pos.x - p_pos.x < -1 && check_bmove(rpg) == 1) {
        rpg->boss.sp.position.x += speed;
        rpg->boss.state = 1;
    } else if (b_pos.x - p_pos.x > 1 && check_bmove(rpg) == 1) {
        rpg->boss.sp.position.x -= speed;
        rpg->boss.state = 11;
    }
    if (b_pos.y - p_pos.y - 48 < -1 && check_bmove(rpg) == 1)
        rpg->boss.sp.position.y += speed;
    else if (b_pos.y - 20 - p_pos.y > 1 && check_bmove(rpg) == 1)
        rpg->boss.sp.position.y -= speed;
}