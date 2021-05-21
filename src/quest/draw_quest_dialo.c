/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw quest and dialogs
*/

#include <rpg.h>

void display_quest(rpg_t *rpg)
{
    if (rpg->talk.is_speaking == 2) {
        display_sprite(rpg->window, &rpg->talk.bg, 0, 500);
        sfText_setString(rpg->talk.text, "I don't have the key to enter.\
        \nI should go to see the mayor.");
        sfRenderWindow_drawText(rpg->window, rpg->talk.text, NULL);
    }
    if (rpg->talk.is_speaking == 3) {
        display_sprite(rpg->window, &rpg->talk.bg, 0, 500);
        sfText_setString(rpg->talk.text, "I don't have a way to defend myself.\
        \nI should come back later.");
        sfRenderWindow_drawText(rpg->window, rpg->talk.text, NULL);
    }
}

void display_dialog(rpg_t *rpg, sfVector2i pos)
{
    if (verif_pos(rpg, pos, "9QMS") == 1 ||
    rpg->map.collisions[pos.y - 1][pos.x] == 'P' ||
    rpg->map.collisions[pos.y - 1][pos.x] == 'C')
        display_sprite(rpg->window, &rpg->player.e,
        rpg->player.player.position.x + 30,
        rpg->player.player.position.y - 30);
    if (rpg->talk.is_speaking == 1) {
        display_sprite(rpg->window, &rpg->talk.bg, 0, 500);
        sfRenderWindow_drawText(rpg->window, rpg->talk.text, NULL);
    }
    display_quest(rpg);
}