/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** boss attack
*/

#include <rpg.h>

int check_boss_att_clock(rpg_t *rpg, sfClock *clock)
{
    rpg->time = sfClock_getElapsedTime(clock);
    if (rpg->time.microseconds / 1000000.0 > 5.0) {
        sfClock_restart(clock);
        return (1);
    }
    return (0);
}

void check_attack_to_player(rpg_t *rpg)
{
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);
    sfVector2f b_pos = sfSprite_getPosition(rpg->boss.sp.sprite);

    b_pos.x += 50;
    b_pos.y += 75;
    if (rpg->boss.state == 3 && rpg->boss.sp.rect.left > 96)
        if (p_pos.x < b_pos.x + 35 + 25 && p_pos.y + 32 > b_pos.y - 10 &&
        p_pos.y < b_pos.y + 20 && rpg->player.hitted != 1)
            player_hit(rpg, rpg->boss.attack);
    if (rpg->boss.state == 13 && rpg->boss.sp.rect.left > 96)
        if (p_pos.x < b_pos.x - 25 && p_pos.y + 32 > b_pos.y - 10 &&
        p_pos.y < b_pos.y - 20 && rpg->player.hitted != 1)
            player_hit(rpg, rpg->boss.attack);
}

void boss_attack2(rpg_t *rpg, sfVector2f p_pos, sfVector2f b_pos)
{
    float dist = get_distance(p_pos.x, p_pos.y, b_pos.x, b_pos.y);
    sfVector2f pos = (sfVector2f)
    {rpg->boss.sp.position.x + 50 + 16,
    rpg->boss.sp.position.y + 75 + 10};

    if (rpg->boss.live > 6 || dist < 100 ||
    check_boss_att_clock(rpg, rpg->boss.f_attack) == 0)
        return;
    rpg->boss.attacking = 1;
    rpg->boss.up = init_sprite(init_rect(0, 0, 32, 32), "enemies/fire.png");
    rpg->boss.ri = init_sprite(init_rect(64, 0, 32, 32), "enemies/fire.png");
    rpg->boss.dow = init_sprite(init_rect(0, 0, 32, 32), "enemies/fire.png");
    rpg->boss.le = init_sprite(init_rect(32, 0, 32, 32), "enemies/fire.png");
    rpg->boss.up.position = pos;
    rpg->boss.ri.position = pos;
    rpg->boss.dow.position = pos;
    rpg->boss.le.position = pos;
}

void boss_attack(rpg_t *rpg)
{
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);
    sfVector2f b_pos = sfSprite_getPosition(rpg->boss.sp.sprite);

    b_pos.x += 50;
    b_pos.y += 75;
    check_attack_to_player(rpg);
    if (rpg->boss.state == 1 && b_pos.x + 35 + 25 - p_pos.x >= -35 &&
    p_pos.y + 32 > b_pos.y - 10 && p_pos.y < b_pos.y + 25 &&
    check_boss_att_clock(rpg, rpg->boss.c_attack) == 1) {
        rpg->boss.state = 3;
        rpg->boss.sp.rect.left = 0;
        sfSprite_setTextureRect(rpg->boss.sp.sprite, rpg->boss.sp.rect);
    } else if (rpg->boss.state == 11 && b_pos.x - 25 - p_pos.x  + 32 <= 75 &&
    p_pos.y + 32 > b_pos.y - 10 && p_pos.y < b_pos.y + 25 &&
    check_boss_att_clock(rpg, rpg->boss.c_attack) == 1) {
        rpg->boss.state = 13;
        rpg->boss.sp.rect.left = 0;
        sfSprite_setTextureRect(rpg->boss.sp.sprite, rpg->boss.sp.rect);
    }
    boss_attack2(rpg, p_pos, b_pos);
}