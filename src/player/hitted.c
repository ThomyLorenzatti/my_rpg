/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** hit
*/

#include <rpg.h>

void change_alpha(rpg_t *rpg, int alpha)
{
    sfSprite_setColor(rpg->player.player.sprite,
    (sfColor) {255, 255, 255, alpha});
    sfSprite_setColor(rpg->player.skin.sprite,
    (sfColor) {255, 255, 255, alpha});
    sfSprite_setColor(rpg->player.pant.sprite,
    (sfColor) {255, 255, 255, alpha});
    sfSprite_setColor(rpg->player.vest.sprite,
    (sfColor) {255, 255, 255, alpha});
    sfSprite_setColor(rpg->player.paint.sprite,
    (sfColor) {255, 255, 255, alpha});
    sfSprite_setColor(rpg->player.eye.sprite,
    (sfColor) {255, 255, 255, alpha});
    sfSprite_setColor(rpg->player.hair.sprite,
    (sfColor) {255, 255, 255, alpha});
}

void player_hit(rpg_t *rpg, int damage)
{
    if (rpg->player.life > 0)
        rpg->player.life -= damage - rpg->player.varmor / 2;
    rpg->player.life = (rpg->player.life <= 0) ? 0 : rpg->player.life;
    if (rpg->player.life <= 0 && rpg->nbtot <= 0) {
        sfMusic_stop(rpg->cine.music);
        rpg->scene = 5;
    }
    else if (rpg->player.life <= 0 && rpg->nbtot >= 1) {
        rpg->player.life = 6;
        rpg->nbtot -= 1;
    }
    if (rpg->player.hitted != 1)
        sfClock_restart(rpg->player.hit);
    rpg->player.hitted = 1;
    change_alpha(rpg, 100);
}

void anim_hit(rpg_t *rpg)
{
    if (rpg->player.hitted != 1)
        return;
    rpg->time = sfClock_getElapsedTime(rpg->player.hit);
    if (rpg->time.microseconds / 1000000.0 >= 2) {
        sfClock_restart(rpg->player.hit);
        rpg->player.hitted = 0;
        change_alpha(rpg, 255);
    }
}