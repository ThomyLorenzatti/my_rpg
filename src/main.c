/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** main
*/

#include <rpg.h>

void event_window(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        if (rpg->event.type == sfEvtClosed ||
        (rpg->event.type == sfEvtKeyPressed
        && rpg->event.key.code == sfKeyEscape && rpg->scene == 0))
            sfRenderWindow_close(rpg->window);
        event_game(rpg, rpg->event.mouseButton);
    }
    rpg->cursor = update_cursor(rpg->window, rpg->cursor);
}

void action_game2(rpg_t *rpg)
{
    if (rpg->scene == 6) {
        anim_lava(rpg);
        player_move(rpg, rpg->map.cave_wall.sprite, rpg->map.cave_col, 1);
        anim_player(rpg);
        anim_attack(rpg);
        anim_hit(rpg);
        enemies_damages(rpg);
        move_enemies(rpg);
        particules_cave(rpg);
        update_particules_eng(rpg);
    } else if (rpg->scene == 7) {
        anim_player(rpg);
        anim_attack(rpg);
        anim_hit(rpg);
        player_move(rpg, rpg->boss.map.sprite, rpg->boss.coll, 2);
        anim_boss(rpg);
        boss_move(rpg);
        check_hitted_boss(rpg);
        boss_attack(rpg);
    }
}

void action_game(rpg_t *rpg)
{
    if (rpg->scene == 1) {
        if (rpg->game.is_boat != 2)
            player_move(rpg, rpg->map.layer1.sprite, rpg->map.collisions, 0);
        anim_hit(rpg);
        update_particles(rpg);
        anim_player(rpg);
        anim_attack(rpg);
        boat_move(rpg);
        if (rpg->game.quest >= 3) {
            particules_rain(rpg);
            update_particules_eng(rpg);
        }
        if (rpg->game.is_boat == 2)
            boat_moving(rpg);
    }
    if (rpg->scene == 2) {
        player_move_house(rpg);
        anim_player(rpg);
    }
    action_game2(rpg);
}

int main(void)
{
    rpg_t *rpg = get_main_struct(0);
    sfImage *img = sfImage_createFromFile("./res/icon.jpg");

    rpg->fps = 60;
    sfRenderWindow_setFramerateLimit(rpg->window, rpg->fps);
    rpg->window_size = sfRenderWindow_getSize(rpg->window);
    sfRenderWindow_setIcon(rpg->window, 256, 256, sfImage_getPixelsPtr(img));
    while (sfRenderWindow_isOpen(rpg->window)) {
        anim_water(rpg);
        anim_rain(rpg);
        anim_boat(rpg);
        anim_door(rpg);
        action_game(rpg);
        draw_scene(rpg);
        event_window(rpg);
    }
    destroy_all(rpg);
    sfImage_destroy(img);
    return (0);
}