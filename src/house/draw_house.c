/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw house
*/

#include <rpg.h>

void display_house_interact(rpg_t *rpg)
{
    if (rpg->talk.is_speaking == 1 && rpg->game.quest == 2) {
        display_sprite(rpg->window, &rpg->talk.bg, 0, 500);
        sfText_setString(rpg->talk.text,
        "Now, I have my weapon in case of danger.");
        sfRenderWindow_drawText(rpg->window, rpg->talk.text, NULL);
    }
}

void draw_house(rpg_t *rpg)
{
    sfVector2f pos = get_player_move_position_h(rpg, 0, -1);
    display_sprite(rpg->window, &rpg->house.back, 0, 0);
    display_sprite(rpg->window, &rpg->house.ground, 160, 60);
    display_sprite(rpg->window, &rpg->house.wall, 160, 60);
    display_sprite(rpg->window, &rpg->house.props, 160, 60);
    display_sprite(rpg->window, &rpg->house.props2, 160, 60);
    display_player(rpg);
    if (rpg->house.collisions[(int) pos.y][(int) pos.x] == '2')
        display_sprite(rpg->window, &rpg->house.props2, 160, 60);
    if (rpg->house.bubble == 1)
        display_sprite(rpg->window, &rpg->player.e,
        rpg->player.player.position.x + 30, rpg->player.player.position.y - 30);
    display_house_interact(rpg);
}