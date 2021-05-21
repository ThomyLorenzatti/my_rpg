/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** door gestion
*/

#include <rpg.h>

void house_door_locked(rpg_t *rpg)
{
    sfVector2f pos = get_player_position(rpg, 0, 1);

    if (rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == sfKeyE &&
    (int) pos.x == 165 && (int) pos.y == 175 &&
    rpg->map.collisions[(int) pos.y - 1][(int) pos.x] == 'Q')
        rpg->talk.is_speaking = 2;
}

void house_door_unlocked(rpg_t *rpg)
{
    sfVector2f pos = get_player_position(rpg, 0, 1);

    if (!(rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == sfKeyE &&
    (int) pos.x == 165 && (int) pos.y == 175 &&
    rpg->map.collisions[(int) pos.y - 1][(int) pos.x] == 'Q'))
        return;
    rpg->game.door_open = 1;
    play_sound(rpg->game.s_door_open.sound, rpg);
}

void close_door(rpg_t *rpg)
{
    if (rpg->time.microseconds / 1000000.0 >= 0.15 &&
    rpg->game.door_open == 3) {
        sfClock_restart(rpg->game.door.clock);
        rpg->game.door.rect.left -= 32;
        if (rpg->game.door.rect.left < 0) {
            rpg->game.door.rect.left = 0;
            rpg->game.door_open = 0;
        }
    }
}

void anim_door(rpg_t *rpg)
{
    if (rpg->game.door_open == 0)
        return;
    rpg->time = sfClock_getElapsedTime(rpg->game.door.clock);
    if (rpg->time.microseconds / 1000000.0 >= 0.15 &&
    rpg->game.door_open == 1) {
        sfClock_restart(rpg->game.door.clock);
        rpg->game.door.rect.left += 32;
        if (rpg->game.door.rect.left >= 128) {
            rpg->game.door.rect.left = 96;
            rpg->game.door_open = 2;
            rpg->scene = 2;
            sfSprite_setPosition(rpg->player.player.sprite,
            (sfVector2f) {330, 450});
        }
    }
    close_door(rpg);
    sfSprite_setTextureRect(rpg->game.door.sprite,
    rpg->game.door.rect);
}