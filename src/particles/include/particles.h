/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __PARTICLES_H__
#define __PARTICLES_H__

#include <rpg.h>

int check_clock_parts(rpg_t *rpg, float limit);
void init_particle(rpg_t *rpg, int index);
void update_particles(rpg_t *rpg);
void draw_particles(rpg_t *rpg);
void particules_cave(rpg_t *rpg);
void draw_particules_eng(rpg_t *rpg);
void update_particules_eng(rpg_t *rpg);
void init_particule_engine(rpg_t *rpg);
void reset_particule_engine(rpg_t *rpg);
int check_clock_eng(rpg_t *rpg, double limit, sfClock *clock);
double calcul_part(rpg_t *rpg, int x, int y);
void assign_particule(rpg_t *rpg, pengine_t particule);
void make_particules(rpg_t *rpg, pdata_t data);
void particules_rain(rpg_t *rpg);

#endif /* !__RPG_H__ */