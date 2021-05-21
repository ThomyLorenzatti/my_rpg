/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_PARTICLES_H__
#define __STRUCT_PARTICLES_H__

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct particle_s particle_t;
typedef struct pengine_s pengine_t;
typedef struct pdata_s pdata_t;

struct particle_s {
    sfVector2f pos;
    sfVector2f speed;
    sfColor color;
    int size;
};

struct pengine_s {
    sfVector2f pos;
    sfVector2f speed;
    sfColor color;
    double size;
    int living;
    sfClock *clock;
    double lifetime;
};

struct pdata_s {
    sfVector2f r_x;
    sfVector2f r_y;
    sfVector2f r_speedx;
    sfVector2f r_speedy;
    sfColor color;
    sfVector2f r_alpha;
    sfVector2f r_size;
    double density;
    double lifetime;
};

#endif /* !__RPG_H__ */