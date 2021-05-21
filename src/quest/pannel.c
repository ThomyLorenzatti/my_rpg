/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** pannel gestion
*/

#include <rpg.h>

void choose_pannel(rpg_t *rpg, sfVector2f pos)
{
    if ((int) pos.x == 143 && (int) pos.y == 160)
        sfText_setString(rpg->talk.text, "Mayor's house");
}

void check_pannel(rpg_t *rpg)
{
    sfVector2f pos = get_player_position(rpg, 0, 1);

    if (rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == sfKeyE) {
        if (rpg->map.collisions[(int) pos.y - 1][(int) pos.x] == 'P') {
            choose_pannel(rpg, pos);
            rpg->talk.is_speaking = 1;
        }
        if (rpg->map.collisions[(int) pos.y - 1][(int) pos.x] == 'S') {
            rpg->scene = 4;
        }
    }
}