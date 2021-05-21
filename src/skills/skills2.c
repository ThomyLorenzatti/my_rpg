/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** skills.c
*/

#include <rpg.h>

void speed_click(rpg_t *rpg)
{
    if (rpg->player.pt > 0 && rpg->player.vspeed < 9) {
        rpg->player.vspeed += 1;
        rpg->player.speedtree.rect.left += 37;
        rpg->player.pt -= 1;
        play_sound(rpg->player.levelup.sound, rpg);
    }
}

void attack_click(rpg_t *rpg)
{
    if (rpg->player.pt > 0 && rpg->player.vattack < 6) {
        rpg->player.vattack += 1;
        rpg->player.attacktree.rect.left += 37;
        rpg->player.pt -= 1;
        play_sound(rpg->player.levelup.sound, rpg);
    }
}

void armor_click(rpg_t *rpg)
{
    if (rpg->player.pt > 0 && rpg->player.varmor < 5) {
        rpg->player.varmor += 1;
        rpg->player.armortree.rect.left += 37;
        rpg->player.pt -= 1;
        play_sound(rpg->player.levelup.sound, rpg);
    }
}