/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw scenes
*/

#include <rpg.h>

void draw_boat(rpg_t *rpg)
{
    sfVector2f save = rpg->game.boat.position;

    display_sprite(rpg->window, &rpg->game.boat,
    rpg->map.layer1.position.x + rpg->game.boat.position.x,
    rpg->map.layer1.position.y + rpg->game.boat.position.y);
    if (rpg->game.is_boat == 1)
        display_sprite(rpg->window, &rpg->player.e,
        rpg->player.player.position.x + 30, rpg->player.player.position.y - 30);
    if (rpg->game.deboat != 0)
        display_sprite(rpg->window, &rpg->player.e,
        rpg->game.boat.position.x + 30, rpg->game.boat.position.y - 30);
    rpg->game.boat.position = save;
}

void draw_game2(rpg_t *rpg, sfVector2i pos)
{
    if (rpg->game.quest >= 2)
        display_sprite(rpg->window, &rpg->map.back, 0, 0);
    draw_particles(rpg);
    draw_particules_eng(rpg);
    display_dialog(rpg, pos);
    display_bars(rpg);
}

void draw_game(rpg_t *rpg)
{
    sfVector2f temp = get_player_position(rpg, 0, 1);
    sfVector2i pos = (sfVector2i) {(int) temp.x, (int) temp.y};
    int draw = (rpg->map.collisions[pos.y][pos.x] == '2') ? 1 : 0;

    draw_map(rpg);
    if (rpg->game.is_boat != 2)
        display_player(rpg);
    draw_boat(rpg);
    draw_props(rpg);
    display_npcs(rpg);
    display_sprite(rpg->window, &rpg->game.door, rpg->map.layer1.position.x
    + 165 * 32, rpg->map.layer1.position.y + 173 * 32);
    draw_reboat(rpg);
    if (draw == 0 && rpg->game.is_boat != 2) {
        display_player(rpg);
    }
    draw_game2(rpg, pos);
}

void draw_scene2(rpg_t *rpg)
{
    if (rpg->scene == 6)
        draw_cave(rpg);
    if (rpg->scene == 7)
        draw_boss(rpg);
    if (rpg->scene == 0)
        draw_menu(rpg);
    if (rpg->scene == 3)
        draw_pause(rpg);
    if (rpg->scene == 20)
        draw_cinema(rpg);
    if (rpg->hunt == 1)
        draw_hunt(rpg);
    if (rpg->mp3 == 1)
        mp3_draw(rpg);
    if (rpg->scene == 8)
        end_draw(rpg);
    sfRenderWindow_display(rpg->window);
}

void draw_scene(rpg_t *rpg)
{
    if (rpg->scene == 4)
        draw_custom(rpg);
    if (rpg->scene == 5)
        draw_gover(rpg);
    if (rpg->scene == 1) {
        draw_game(rpg);
        draw_inventory(rpg);
        draw_skilltab(rpg);
    }
    if (rpg->scene == 2) {
        draw_house(rpg);
        draw_inventory(rpg);
        draw_skilltab(rpg);
    }
    draw_market(rpg);
    draw_scene2(rpg);
}