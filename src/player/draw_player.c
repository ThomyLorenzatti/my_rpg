/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw player
*/

#include <rpg.h>

void display_attack(rpg_t *rpg)
{
    get_attack_pos(rpg);
    if (rpg->player.attacking == 1)
        display_sprite(rpg->window, &rpg->player.attack,
        rpg->player.player.position.x + rpg->player.attack.position.x,
        rpg->player.player.position.y + rpg->player.attack.position.y);
}

void display_player(rpg_t *rpg)
{
    display_attack(rpg);
    display_sprite(rpg->window, &rpg->player.skin,
    rpg->player.player.position.x, rpg->player.player.position.y);
    display_sprite(rpg->window, &rpg->player.pant,
    rpg->player.player.position.x, rpg->player.player.position.y);
    display_sprite(rpg->window, &rpg->player.vest,
    rpg->player.player.position.x, rpg->player.player.position.y);
    display_sprite(rpg->window, &rpg->player.paint,
    rpg->player.player.position.x, rpg->player.player.position.y);
    display_sprite(rpg->window, &rpg->player.eye,
    rpg->player.player.position.x, rpg->player.player.position.y);
    if (rpg->game.quest >= 3)
        display_sprite(rpg->window, &rpg->player.sword,
        rpg->player.player.position.x, rpg->player.player.position.y);
    display_sprite(rpg->window, &rpg->player.hair,
    rpg->player.player.position.x, rpg->player.player.position.y);
    if (rpg->player.player.rect.top == 0)
        display_attack(rpg);
}