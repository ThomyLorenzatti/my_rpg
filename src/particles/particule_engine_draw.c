/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw and update partisules
*/

#include <rpg.h>

void draw_particules_eng(rpg_t *rpg)
{
    sfCircleShape *shape = sfCircleShape_create();
    sfVector2f pos;

    for (int i = 0; i < MAX_PART; i++) {
        if (rpg->game.eng[i].living == 1) {
            pos.x = rpg->game.eng[i].pos.x + rpg->game.eng[i].speed.x;
            pos.y = rpg->game.eng[i].pos.y + rpg->game.eng[i].speed.y;
            sfCircleShape_setPosition(shape, pos);
            sfCircleShape_setRadius(shape, rpg->game.eng[i].size);
            sfCircleShape_setFillColor(shape, rpg->game.eng[i].color);
            sfRenderWindow_drawCircleShape(rpg->window, shape, NULL);
        }
    }
    sfCircleShape_destroy(shape);
}

void update_particules_eng(rpg_t *rpg)
{
    if (check_clock_eng(rpg, 0.05, rpg->game.eng_clock_up) == 0)
        return;
    for (int i = 0; i < MAX_PART; i++) {
        rpg->game.eng[i].pos.x = rpg->game.eng[i].pos.x
        + rpg->game.eng[i].speed.x;
        rpg->game.eng[i].pos.y = rpg->game.eng[i].pos.y
        + rpg->game.eng[i].speed.y;
        if (rpg->game.eng[i].pos.x > 900 || rpg->game.eng[i].pos.x < -100 ||
        rpg->game.eng[i].pos.y > 700 || rpg->game.eng[i].pos.x < -100)
            rpg->game.eng[i].living = 0;
        if (check_clock_eng(rpg, rpg->game.eng[i].lifetime,
        rpg->game.eng[i].clock) == 1)
            rpg->game.eng[i].living = 0;
    }
}