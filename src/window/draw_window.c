/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw window
*/

#include <rpg.h>

void draw_map(rpg_t *rpg)
{
    display_sprite(rpg->window, &rpg->game.water, 0, 0);
    rpg->map.layer1.position = sfSprite_getPosition(rpg->map.layer1.sprite);
    display_sprite(rpg->window, &rpg->map.layer1, rpg->map.layer1.position.x,
    rpg->map.layer1.position.y);
    display_sprite(rpg->window, &rpg->map.border, rpg->map.layer1.position.x,
    rpg->map.layer1.position.y);
    display_sprite(rpg->window, &rpg->map.cave, rpg->map.layer1.position.x,
    rpg->map.layer1.position.y);
    display_sprite(rpg->window, &rpg->map.path, rpg->map.layer1.position.x,
    rpg->map.layer1.position.y);
}

void draw_props(rpg_t *rpg)
{
    display_sprite(rpg->window, &rpg->map.houses, rpg->map.layer1.position.x,
    rpg->map.layer1.position.y);
}

void display_bars(rpg_t *rpg)
{
    int index_life = (int) 6 * rpg->player.life / rpg->player.max_life;
    int index_xp = (int) 6 * rpg->player.xp / rpg->player.max_xp;

    sfSprite_setRotation(rpg->player.life_bar.sprite, 0);
    sfTexture_destroy(rpg->player.life_bar.texture);
    sfTexture_destroy(rpg->player.xp_bar.texture);
    rpg->player.life_bar.texture = sfTexture_copy(rpg->player.lifes
    [index_life]);
    display_sprite(rpg->window, &rpg->player.life_bar, 25, 10);
    rpg->player.xp_bar.texture = sfTexture_copy(rpg->player.xps[index_xp]);
    display_sprite(rpg->window, &rpg->player.xp_bar, 25, 50);
    display_sprite(rpg->window, &rpg->player.heart, 5, 5);
    display_sprite(rpg->window, &rpg->player.xlogo, 5, 48);
}