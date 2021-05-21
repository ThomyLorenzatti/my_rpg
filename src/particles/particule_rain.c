/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** particule cave
*/

#include <rpg.h>

void particules_rain(rpg_t *rpg)
{
    pdata_t data;

    data.color = (sfColor) {0, 125, 188, 255};
    data.density = 0.01;
    data.r_alpha = (sfVector2f) {150, 230};
    data.r_size = (sfVector2f) {1, 3};
    data.r_speedx = (sfVector2f) {-5, 0};
    data.r_speedy = (sfVector2f) {12, 18};
    data.r_x = (sfVector2f) {0, 800};
    data.r_y = (sfVector2f) {0, 0};
    data.lifetime = 5;
    make_particules(rpg, data);
}