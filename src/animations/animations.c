/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** anim water
*/

#include <rpg.h>

void anim_water(rpg_t *rpg)
{
    rpg->time = sfClock_getElapsedTime(rpg->game.water.clock);
    if (rpg->time.microseconds / 1000000.0 > 0.05) {
        sfClock_restart(rpg->game.water.clock);
        rpg->game.water.rect.left += 800;
        if (rpg->game.water.rect.left >= 11200)
            rpg->game.water.rect.left = 0;
        sfSprite_setTextureRect(rpg->game.water.sprite, rpg->game.water.rect);
    }
}

void anim_rain(rpg_t *rpg)
{
    rpg->time = sfClock_getElapsedTime(rpg->game.rain.clock);
    if (rpg->time.microseconds / 1000000.0 > 0.05) {
        sfClock_restart(rpg->game.rain.clock);
        rpg->game.rain.rect.left += 800;
        if (rpg->game.rain.rect.left >= 11200)
            rpg->game.rain.rect.left = 0;
        sfSprite_setTextureRect(rpg->game.rain.sprite, rpg->game.rain.rect);
    }
}

void anim_boat(rpg_t *rpg)
{
    sfVector2u size = sfTexture_getSize(rpg->game.boat.texture);

    if (rpg->game.is_boat == 2) {
        if (rpg->player.move == 1)
            rpg->game.boat.rect.top = 128;
        if (rpg->player.move == -1)
            rpg->game.boat.rect.top = 0;
        if (rpg->player.move == -2)
            rpg->game.boat.rect.top = 0;
        if (rpg->player.move == 2)
            rpg->game.boat.rect.top = 64;
    }
    rpg->time = sfClock_getElapsedTime(rpg->game.boat.clock);
    if (rpg->time.microseconds / 1000000.0 > 0.1) {
        sfClock_restart(rpg->game.boat.clock);
        rpg->game.boat.rect.left += size.x / 31;
        if (rpg->game.boat.rect.left >= (int) size.x)
            rpg->game.boat.rect.left = 0;
        sfSprite_setTextureRect(rpg->game.boat.sprite, rpg->game.boat.rect);
    }
}

void anim_player(rpg_t *rpg)
{
    if (rpg->player.move == -2)
        check_anim_clock(rpg, 1);
    if (rpg->player.move == 2)
        check_anim_clock(rpg, 2);
    if (rpg->player.move == -1)
        check_anim_clock(rpg, 0);
    if (rpg->player.move == 1)
        check_anim_clock(rpg, 3);
}

void anim_lava(rpg_t *rpg)
{
    rpg->time = sfClock_getElapsedTime(rpg->map.lava.clock);
    if (rpg->time.microseconds / 1000000.0 > 0.05) {
        sfClock_restart(rpg->map.lava.clock);
        rpg->map.lava.rect.left += 800;
        if (rpg->map.lava.rect.left >= 11200)
            rpg->map.lava.rect.left = 0;
        sfSprite_setTextureRect(rpg->map.lava.sprite, rpg->map.lava.rect);
    }
}