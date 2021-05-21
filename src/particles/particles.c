/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** particles
*/

#include <rpg.h>

int check_clock_parts(rpg_t *rpg, float limit)
{
    rpg->time = sfClock_getElapsedTime(rpg->game.clock_part);
    if (rpg->time.microseconds / 1000000.0 >= limit) {
        sfClock_restart(rpg->game.clock_part);
        return (1);
    }
    return (0);
}

void init_particle(rpg_t *rpg, int index)
{
    int a = rand() % 55 + 100;

    rpg->game.part[index].color = (sfColor) {0, 0, 0, a};
    rpg->game.part[index].pos = (sfVector2f) {0, 50};
    rpg->game.part[index].size = 2;
    rpg->game.part[index].speed.x = ((rand() % 30) - 15);
    rpg->game.part[index].speed.y = (rand() % 20) + 5;
}

void update_particles(rpg_t *rpg)
{
    if (check_clock_parts(rpg, 0.05) == 0)
        return;
    for (int i = 0; i < MAX_PART; i++) {
        rpg->game.part[i].pos.x += rpg->game.part[i].speed.x / 10 / 2;
        rpg->game.part[i].pos.y -= rpg->game.part[i].speed.y / 10 / 2;
        rpg->game.part[i].color.a -= 5;
        if (rpg->game.part[i].pos.y <= 0 || rpg->game.part[i].color.a >= 200)
            init_particle(rpg, i);
    }
}

void draw_particles(rpg_t *rpg)
{
    sfCircleShape *shape = sfCircleShape_create();
    sfVector2f pos;

    for (int i = 0; i < MAX_PART; i++) {
        pos.x = rpg->map.layer1.position.x + 166 * 32 + 5
        + rpg->game.part[i].pos.x;
        pos.y = rpg->map.layer1.position.y + 171 * 32 - 50
        + rpg->game.part[i].pos.y;
        sfCircleShape_setPosition(shape, pos);
        sfCircleShape_setRadius(shape, rpg->game.part[i].size);
        sfCircleShape_setFillColor(shape, rpg->game.part[i].color);
        sfRenderWindow_drawCircleShape(rpg->window, shape, NULL);
    }
    sfCircleShape_destroy(shape);
}