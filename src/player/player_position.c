/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get player_position
*/

#include <rpg.h>

sfVector2f get_player_position(rpg_t *rpg, int x, int y)
{
    sfVector2u size = sfTexture_getSize(rpg->player.player.texture);
    sfVector2f pos1 = sfSprite_getPosition(rpg->player.player.sprite);
    sfVector2f pos2 = sfSprite_getPosition(rpg->map.layer1.sprite);
    sfVector2f pos;

    pos1.x += size.x / 6;
    if (y == 1)
        pos1.y += size.y / 4;
    if (y == -1)
        pos1.y += size.y / 4 - 10;
    pos.x = (pos1.x + (pos2.x * -1)) / 32;
    pos.y = (pos1.y + (pos2.y * -1)) / 32;
    return (pos);
}