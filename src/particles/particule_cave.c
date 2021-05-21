/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** particule cave
*/

#include <rpg.h>

void particules_cave(rpg_t *rpg)
{
    pdata_t data;

    data.color = (sfColor) {246, 132, 24, 255};
    data.density = 0.5;
    data.r_alpha = (sfVector2f) {150, 230};
    data.r_size = (sfVector2f) {2, 5};
    data.r_speedx = (sfVector2f) {-5, 5};
    data.r_speedy = (sfVector2f) {3, 6};
    data.r_x = (sfVector2f) {0, 800};
    data.r_y = (sfVector2f) {0, 0};
    data.lifetime = 10;
    make_particules(rpg, data);
}