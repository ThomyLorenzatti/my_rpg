/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** enemies check damages
*/

#include <rpg.h>

void check_damage(rpg_t *rpg, sprite_t sp, enemies_t *temp)
{
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);
    sfVector2f e_pos = sfSprite_getPosition(sp.sprite);

    if (p_pos.x + 32 > e_pos.x && p_pos.x < e_pos.x + 32 &&
    p_pos.y + 32 > e_pos.y + 16 && p_pos.y + 16 < e_pos.y + 32)
        if (rpg->player.hitted != 1)
            player_hit(rpg, temp->attack);
}