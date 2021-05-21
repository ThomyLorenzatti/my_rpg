/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw boss
*/

#include <rpg.h>

void display_boss(rpg_t *rpg)
{
    sfVector2f save;
    sfVector2f b_pos = sfSprite_getPosition(rpg->boss.sp.sprite);

    display_player(rpg);
    save = rpg->boss.sp.position;
    display_sprite(rpg->window, &rpg->boss.sp,
    rpg->boss.sp.position.x + rpg->boss.map.position.x,
    rpg->boss.sp.position.y + rpg->boss.map.position.y);
    rpg->boss.sp.position = save;
    if (rpg->player.player.position.y + 32 > b_pos.y + 85)
        display_player(rpg);
}

void draw_boss(rpg_t *rpg)
{
    int index_life = (int) (rpg->boss.live - 1) / 2 + 1;

    display_sprite(rpg->window, &rpg->map.back, 0, 0);
    display_sprite(rpg->window, &rpg->boss.map,
    rpg->boss.map.position.x, rpg->boss.map.position.y);
    display_boss(rpg);
    if (rpg->boss.attacking == 1)
        fire_ball(rpg);
    display_bars(rpg);
    draw_inventory(rpg);
    draw_skilltab(rpg);
    index_life = (index_life > 6) ? index_life - 1 : index_life;
    index_life = (rpg->boss.live == 0) ? 0 : index_life;
    sfTexture_destroy(rpg->player.life_bar.texture);
    rpg->player.life_bar.texture = sfTexture_copy(rpg->player.lifes
    [index_life]);
    display_sprite(rpg->window, &rpg->player.life_bar, 617, 10);
    sfSprite_setScale(rpg->boss.ic.sprite, (sfVector2f) {0.1, 0.1});
    display_sprite(rpg->window, &rpg->boss.ic, 750, 2);
}