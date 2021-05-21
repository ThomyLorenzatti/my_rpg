/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** boat move
*/

#include <rpg.h>

void player_new_pos(rpg_t *rpg, int x, int y)
{
    sfVector2f pos = sfSprite_getPosition(rpg->game.boat.sprite);
    rpg->game.is_boat = 0;
    if (x > 0 || y > 0)
        sfSprite_move(rpg->map.layer1.sprite, (sfVector2f) {-1 * x, -1 * y});
    sfSprite_setPosition(rpg->player.player.sprite,
    (sfVector2f) {pos.x + x, pos.y + y});
}

void move_screen(rpg_t *rpg)
{
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);
    sfVector2f b_pos = sfSprite_getPosition(rpg->game.boat.sprite);

    if (p_pos.y > b_pos.y + 56)
        sfSprite_move(rpg->map.layer1.sprite, (sfVector2f) {0, 30});
    if (p_pos.y + 24 < b_pos.y - 56)
        sfSprite_move(rpg->map.layer1.sprite, (sfVector2f) {0, -30});
    if (p_pos.x + 24 < b_pos.x - 56)
        sfSprite_move(rpg->map.layer1.sprite, (sfVector2f) {-30, 0});
    if (p_pos.x > b_pos.x + 56)
        sfSprite_move(rpg->map.layer1.sprite, (sfVector2f) {30, 0});
}

void boat_events(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == sfKeyE) {
        if (rpg->mplay == 0)
            play_sound(rpg->pdc.sound, rpg);
        if (rpg->game.is_boat == 1) {
            rpg->game.is_boat = 2;
            move_screen(rpg);
        }
        if (rpg->game.deboat == 1)
            player_new_pos(rpg, 0, 50);
        if (rpg->game.deboat == 2)
            player_new_pos(rpg, 50, 0);
        if (rpg->game.deboat == 3)
            player_new_pos(rpg, 0, -50);
        if (rpg->game.deboat == 4)
            player_new_pos(rpg, -50, 0);
    }
    if (rpg->game.is_boat != 2) {
        sfSound_stop(rpg->pdc.sound);
        return;
    }
}

void check_deboat(rpg_t *rpg, sfVector2i b_pos)
{
    rpg->game.deboat = 0;
    b_pos.x = (b_pos.x + rpg->map.layer1.position.x * -1) / 32;
    b_pos.y = (b_pos.y + rpg->map.layer1.position.y * -1) / 32;
    if (rpg->map.collisions[b_pos.y + 3][b_pos.x] == 'B')
        rpg->game.deboat = 1;
    if (rpg->map.collisions[b_pos.y - 2][b_pos.x] == 'B')
        rpg->game.deboat = 3;
    if (rpg->map.collisions[b_pos.y][b_pos.x + 2] == 'B')
        rpg->game.deboat = 2;
    if (rpg->map.collisions[b_pos.y][b_pos.x - 2] == 'B')
        rpg->game.deboat = 4;
}

void boat_move(rpg_t *rpg)
{
    sfVector2i b_pos = get_boat_pos(rpg);
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);

    p_pos.x += 24;
    p_pos.y += 24;
    if (p_pos.x + 48 > b_pos.x - 56 && p_pos.x < b_pos.x + 56 + 32 &&
    p_pos.y + 48 > b_pos.y - 56 && p_pos.y < b_pos.y + 56 + 32 &&
    rpg->game.is_boat != 2)
        rpg->game.is_boat = 1;
    else if (rpg->game.is_boat != 2)
        rpg->game.is_boat = 0;
    if (rpg->game.is_boat == 2)
        check_deboat(rpg, b_pos);
    else
        rpg->game.deboat = 0;
}