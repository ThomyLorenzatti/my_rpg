/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** particule engine
*/

#include <rpg.h>

int check_clock_eng(rpg_t *rpg, double limit, sfClock *clock)
{
    rpg->time = sfClock_getElapsedTime(clock);
    if (rpg->time.microseconds / 1000000.0 >= limit) {
        sfClock_restart(clock);
        return (1);
    }
    return (0);
}

double calcul_part(rpg_t *rpg, int x, int y)
{
    if (x == 0 && y == 0)
        return (0);
    if (x < 0 && y >= 0)
        return ((rand() % (int) (y + x * -1)) + x);
    else if (x < 0 && y <= 0)
        return ((rand() % (int) (x * -1 + y)) + x);
    return ((rand() % (int) (y - x)) + x);
}

void assign_particule(rpg_t *rpg, pengine_t particule)
{
    for (int i = 0; i < MAX_PART; i++) {
        if (rpg->game.eng[i].living == 0) {
            sfClock_restart(rpg->game.eng[i].clock);
            particule.clock = rpg->game.eng[i].clock;
            rpg->game.eng[i] = particule;
            return;
        }
    }
}

void make_particules(rpg_t *rpg, pdata_t data)
{
    pengine_t particule;

    if (check_clock_eng(rpg, data.density, rpg->game.eng_clock) == 0)
        return;
    particule.color = data.color;
    particule.color.a = (rand() % (int) (data.r_alpha.y - data.r_alpha.x))
    + data.r_alpha.x;
    particule.size = ((rand() % (int) ((data.r_size.y - data.r_size.x) * 10))
    + data.r_size.x * 10) / 10;
    particule.pos.x = calcul_part(rpg, data.r_x.x, data.r_x.y);
    particule.pos.y = calcul_part(rpg, data.r_y.x, data.r_y.y);
    particule.speed.x = calcul_part(rpg, data.r_speedx.x, data.r_speedx.y);
    particule.speed.y = calcul_part(rpg, data.r_speedy.x, data.r_speedy.y);
    particule.living = 1;
    particule.lifetime = data.lifetime;
    assign_particule(rpg, particule);
}