/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** player attack
*/

#include <rpg.h>

void get_attack_pos(rpg_t *rpg)
{
    rpg->player.attack.position.y = 20;
    rpg->player.attack.position.x = 10;
    if (rpg->player.player.rect.top / 48 == 0)
        rpg->player.attack.position.y = 40;
    if (rpg->player.player.rect.top / 48 == 1)
        rpg->player.attack.position.x = -20;
    if (rpg->player.player.rect.top / 48 == 2)
        rpg->player.attack.position.x = 30;
    if (rpg->player.player.rect.top / 48 == 3) {
        rpg->player.attack.position.x = 5;
        rpg->player.attack.position.y = -10;
    }
}

void anim_attack(rpg_t *rpg)
{
    sfVector2u size = sfTexture_getSize(rpg->player.attack.texture);

    if (rpg->player.attacking == 0)
        return;
    rpg->time = sfClock_getElapsedTime(rpg->player.attack.clock);
    if (rpg->time.microseconds / 1000000.0 >= 0.05) {
        sfClock_restart(rpg->player.attack.clock);
        rpg->player.attack.rect.left += size.x / 5;
        if (rpg->player.attack.rect.left >= (int) size.x) {
            rpg->player.attack.rect.left = 0;
            rpg->player.attacking = 0;
        }
    }
}

void enemy_hitted(rpg_t *rpg, enemies_t **enemy)
{
    int top = rpg->player.player.rect.top;
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);
    sfVector2f e_pos = sfSprite_getPosition((*enemy)->sp.sprite);

    if (top == 0 && e_pos.x < p_pos.x + 48 && e_pos.x + 32 > p_pos.x &&
    e_pos.y + 32 > p_pos.y && e_pos.y + 16 < p_pos.y + 48 + 35)
        (*enemy)->life -= rpg->player.vattack;
    if (top == 48 && e_pos.x < p_pos.x + 48 && e_pos.x + 32 > p_pos.x - 35 &&
    e_pos.y + 32 > p_pos.y + 24 && e_pos.y + 16 < p_pos.y + 48)
        (*enemy)->life -= rpg->player.vattack;
    if (top == 96 && e_pos.x < p_pos.x + 48 + 35 && e_pos.x + 32 > p_pos.x &&
    e_pos.y + 32 > p_pos.y + 24 && e_pos.y + 16 < p_pos.y + 48)
        (*enemy)->life -= rpg->player.vattack;
    if (top == 144 && e_pos.x < p_pos.x + 48 && e_pos.x + 32 > p_pos.x &&
    e_pos.y + 32 > p_pos.y + 24 - 48 && e_pos.y + 16 < p_pos.y + 48)
        (*enemy)->life -= rpg->player.vattack;
}

void gain_xp(rpg_t *rpg, enemies_t **enemy)
{
    rpg->player.xp += (*enemy)->xp;
    if (rpg->player.xp >= rpg->player.max_xp) {
        rpg->player.xp -= rpg->player.max_xp;
        rpg->player.max_xp += 6;
        rpg->player.pt += 1;
    }
}

void player_attack(rpg_t *rpg)
{
    if (!(rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == sfKeySpace && rpg->player.attacking == 0 &&
    rpg->game.quest >= 3))
        return;
    sfClock_restart(rpg->player.attack.clock);
    rpg->player.attacking = 1;
    rpg->player.attack.rect.top = rpg->player.player.rect.top / 48 * 35;
    if (rpg->scene == 6)
        attack_enemies(rpg);
    if (rpg->scene == 7 && rpg->boss.live > 0)
        boss_hitted(rpg);
}