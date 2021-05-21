/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event cave
*/

#include <rpg.h>

void cave_checker(rpg_t *rpg, sfVector2f pos)
{
    if (rpg->map.cave_col[(int) pos.y][(int) pos.x + 1] == 'E') {
        rpg->scene = 1;
        sfSprite_setPosition(rpg->map.layer1.sprite,
        (sfVector2f) {-573, -3550});
        sfSprite_setPosition(rpg->player.player.sprite, (sfVector2f)
        {320, 270});
        destroy_all_enemies(rpg);
        reset_particule_engine(rpg);
    }
    if (rpg->map.cave_col[(int) pos.y - 1][(int) pos.x] == 'N') {
        play_music(rpg->cine.music, rpg);
        rpg->scene = 20;
        sfClock_restart(rpg->cine.clock);
        sfSprite_setPosition(rpg->player.player.sprite,
        (sfVector2f) {300, 300});
        destroy_all_enemies(rpg);
    }
}

void cave_events(rpg_t *rpg)
{
    sfVector2f pos =
    get_player_move_position(rpg, 0, 0, rpg->map.cave_wall.sprite);

    if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == sfKeyE)
        cave_checker(rpg, pos);
}