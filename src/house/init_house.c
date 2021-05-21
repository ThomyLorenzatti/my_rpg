/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init house
*/

#include <rpg.h>

void init_house(rpg_t *rpg)
{
    rpg->house.back = init_sprite(init_rect(0, 0, 800, 600),
    "map/home/back.jpg");
    rpg->house.ground = init_sprite(init_rect(0, 0, 480, 480),
    "map/home/sol1.png");
    rpg->house.wall = init_sprite(init_rect(0, 0, 480, 480),
    "map/home/mur2.png");
    rpg->house.props = init_sprite(init_rect(0, 0, 480, 480),
    "map/home/furniture3.png");
    rpg->house.props2 = init_sprite(init_rect(0, 0, 480, 480),
    "map/home/big_element4.png");
    get_collisions_house(rpg);
}