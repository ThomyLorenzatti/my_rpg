/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create map
*/

#include <rpg.h>

void create_game(rpg_t *rpg)
{
    rpg->game.water = init_sprite(init_rect(0, 0, 800, 600),
    "./res/water.png");
    rpg->game.rain = init_sprite(init_rect(0, 0, 800, 1824),
    "./res/rain.png");
    rpg->game.rain.position.y = -608;
    rpg->game.quest = 0;
    rpg->game.door = init_sprite(init_rect(0, 0, 32, 32), "./res/door.png");
    rpg->game.door_open = 0;
    rpg->game.boat = init_sprite(init_rect(0, 0, 64, 64),
    "./res/boat1.png");
    rpg->game.boat.position = (sfVector2f) {123 * 32, 164 * 32};
    rpg->game.clock_part = sfClock_create();
    for (int i = 0; i < MAX_PART; i++)
        init_particle(rpg, i);
    rpg->game.is_boat = 0;
    rpg->game.deboat = 0;
}

void create_map(rpg_t *rpg)
{
    rpg->map.back = init_sprite(init_rect(0, 0, 800, 600),
    "./map/back.jpg");
    sfSprite_setColor(rpg->map.back.sprite, (sfColor) {255, 255, 255, 75});
    rpg->map.layer1 = init_sprite(init_rect(0, 0, 6400, 6400),
    "./map/green.png");
    sfSprite_setPosition(rpg->map.layer1.sprite, (sfVector2f) {-5010, -5370});
    rpg->map.border = init_sprite(init_rect(0, 0, 6400, 6400),
    "./map/edge_tree.png");
    rpg->map.path = init_sprite(init_rect(0, 0, 6400, 6400),
    "./map/village_chemin1.png");
    rpg->map.houses = init_sprite(init_rect(0, 0, 6400, 6400),
    "./map/village_house1.png");
    rpg->map.cave = init_sprite(init_rect(0, 0, 6400, 6400),
    "./map/cave.png");
    rpg->map.cave_ground = init_sprite(init_rect(0, 0, 3200, 3200),
    "./map/cave/sol.png");
    rpg->map.cave_wall = init_sprite(init_rect(0, 0, 3200, 3200),
    "./map/cave/cave.png");
    rpg->map.lava = init_sprite(init_rect(0, 0, 800, 600),
    "./res/water.png");
}