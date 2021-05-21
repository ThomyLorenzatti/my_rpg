/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** animation boss
*/

#include <rpg.h>

void anim_boss(rpg_t *rpg)
{
    double time = (rpg->boss.state == 9) ? 0.2 : 0.15;

    rpg->boss.sp.rect.top = 96 * rpg->boss.state;
    rpg->time = sfClock_getElapsedTime(rpg->boss.sp.clock);
    if (rpg->time.microseconds / 1000000.0 > time) {
        sfClock_restart(rpg->boss.sp.clock);
        rpg->boss.sp.rect.left += 96;
        if ((rpg->boss.sp.rect.top == 96 || rpg->boss.sp.rect.top == 96 * 11) &&
        rpg->boss.sp.rect.left >= 96 * 8)
            rpg->boss.sp.rect.left = 0;
        if ((rpg->boss.sp.rect.top == 96 * 3 ||
        rpg->boss.sp.rect.top == 96 * 13) && rpg->boss.sp.rect.left >= 96 * 7)
            rpg->boss.state = 1;
        if ((rpg->boss.sp.rect.top == 96 * 9 ||
        rpg->boss.sp.rect.top == 96 * 19) && rpg->boss.sp.rect.left >= 96 * 6)
            rpg->scene = 8;
    }
    sfSprite_setTextureRect(rpg->boss.sp.sprite, rpg->boss.sp.rect);
}