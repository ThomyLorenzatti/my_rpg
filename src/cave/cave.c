/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** cave
*/

#include <rpg.h>

void cave_locked(rpg_t *rpg)
{
    sfVector2f pos = get_player_position(rpg, 0, 1);

    if (rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == sfKeyE &&
    rpg->map.collisions[(int) pos.y - 1][(int) pos.x] == 'C') {
        if (rpg->game.quest <= 2)
            rpg->talk.is_speaking = 3;
        else {
            rpg->map.cave_wall.position = (sfVector2f) {-2350, -2550};
            sfSprite_setPosition(rpg->map.cave_wall.sprite,
            (sfVector2f) {-2350, -2550});
            rpg->scene = 6;
            rpg->player.player.position = (sfVector2f) {550, 310};
            sfSprite_setPosition(rpg->player.player.sprite,
            (sfVector2f) {550, 310});
            rpg->player.player.rect.top = 96;
            create_enemies(rpg);
            reset_particule_engine(rpg);
        }
    }
}