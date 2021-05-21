/*
** EPITECH PROJECT, 2021
** rg
** File description:
** get map collisions
*/

#include <rpg.h>

void get_collisions(rpg_t *rpg)
{
    char *buffer = load_file("map/collision.txt");
    rpg->map.collisions = my_str_word_array(buffer, '\n');
}

void get_collisions_house(rpg_t *rpg)
{
    char *buffer = load_file("map/home/collision_maison");
    rpg->house.collisions = my_str_word_array(buffer, '\n');
}

void get_collisions_cave(rpg_t *rpg)
{
    char *buffer = load_file("map/cave/collision");
    rpg->map.cave_col = my_str_word_array(buffer, '\n');
}

void get_collisions_boss(rpg_t *rpg)
{
    char *buffer = load_file("map/boss_collision");
    rpg->boss.coll = my_str_word_array(buffer, '\n');
}