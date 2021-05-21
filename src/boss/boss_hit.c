/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** boss hitted
*/

#include <rpg.h>

void boss_death(rpg_t *rpg)
{
    if (rpg->boss.live <= 0 && rpg->boss.state != 10) {
        rpg->boss.live = 0;
        rpg->boss.state = (rpg->boss.state < 10) ? 9 : 19;
        rpg->boss.sp.rect.left = 0;
        sfSprite_setTextureRect(rpg->boss.sp.sprite, rpg->boss.sp.rect);
    }
}

void boss_hitted(rpg_t *rpg)
{
    int top = rpg->player.player.rect.top;
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);
    sfVector2f e_pos = sfSprite_getPosition(rpg->boss.sp.sprite);

    e_pos.x += 50;
    e_pos.y += 75;
    if (top == 0 && e_pos.x < p_pos.x + 48 && e_pos.x + 35 > p_pos.x &&
    e_pos.y + 20 > p_pos.y && e_pos.y < p_pos.y + 48 + 35)
        rpg->boss.live -= rpg->player.vattack;
    if (top == 48 && e_pos.x < p_pos.x + 48 && e_pos.x + 35 > p_pos.x - 35 &&
    e_pos.y + 20 > p_pos.y + 24 && e_pos.y < p_pos.y + 48)
        rpg->boss.live -= rpg->player.vattack;
    if (top == 96 && e_pos.x < p_pos.x + 48 + 35 && e_pos.x + 35 > p_pos.x &&
    e_pos.y + 20 > p_pos.y + 24 && e_pos.y < p_pos.y + 48)
        rpg->boss.live -= rpg->player.vattack;
    if (top == 144 && e_pos.x < p_pos.x + 48 && e_pos.x + 35 > p_pos.x &&
    e_pos.y + 20 > p_pos.y + 24 - 48 && e_pos.y < p_pos.y + 48)
        rpg->boss.live -= rpg->player.vattack;
    boss_death(rpg);
}