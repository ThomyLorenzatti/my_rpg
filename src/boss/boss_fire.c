/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** boss fire attack
*/

#include <rpg.h>

void check_player_ball(rpg_t *rpg, sfVector2f b_pos)
{
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);

    if (p_pos.x + 32 > b_pos.x && p_pos.x < b_pos.x + 32 &&
    p_pos.y + 32 > b_pos.y && p_pos.y + 16 < b_pos.y + 32)
        if (rpg->player.hitted != 1)
            player_hit(rpg, 1);
}

void draw_ball(rpg_t *rpg, sprite_t *sp, int x, int y)
{
    sfVector2f save;

    save = sp->position;
    display_sprite(rpg->window, sp,
    (*sp).position.x + rpg->boss.map.position.x + x,
    (*sp).position.y + rpg->boss.map.position.y + y);
    (*sp).position = (sfVector2f) {save.x + x, save.y + y};
}

int check_ball_clock(rpg_t *rpg, sfClock *clock)
{
    rpg->time = sfClock_getElapsedTime(clock);
    if (rpg->time.microseconds / 1000000.0 > 0.02) {
        sfClock_restart(clock);
        draw_ball(rpg, &rpg->boss.up, 0, -5);
        draw_ball(rpg, &rpg->boss.ri, 5, 0);
        draw_ball(rpg, &rpg->boss.dow, 0, 5);
        draw_ball(rpg, &rpg->boss.le, -5, 0);
        return (1);
    }
    return (0);
}

void fire_ball(rpg_t *rpg)
{
    check_player_ball(rpg, sfSprite_getPosition(rpg->boss.up.sprite));
    check_player_ball(rpg, sfSprite_getPosition(rpg->boss.ri.sprite));
    check_player_ball(rpg, sfSprite_getPosition(rpg->boss.dow.sprite));
    check_player_ball(rpg, sfSprite_getPosition(rpg->boss.le.sprite));
    draw_ball(rpg, &rpg->boss.up, 0, 0);
    draw_ball(rpg, &rpg->boss.ri, 0, 0);
    draw_ball(rpg, &rpg->boss.dow, 0, 0);
    draw_ball(rpg, &rpg->boss.le, 0, 0);
    if (check_ball_clock(rpg, rpg->boss.up.clock) == 0)
        return;
    if (rpg->boss.up.position.y < -40 && rpg->boss.ri.position.x > 810 &&
    rpg->boss.dow.position.y > 610 && rpg->boss.le.position.x < -40) {
        rpg->boss.attacking = 0;
        destroy_sprite(&rpg->boss.up);
        destroy_sprite(&rpg->boss.ri);
        destroy_sprite(&rpg->boss.dow);
        destroy_sprite(&rpg->boss.le);
    }
}