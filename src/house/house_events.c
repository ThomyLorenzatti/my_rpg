/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** house events
*/

#include <rpg.h>

sfVector2i get_position_house(rpg_t *rpg, int x, int y)
{
    sfVector2u size = sfTexture_getSize(rpg->player.player.texture);
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);
    sfVector2f offset = (sfVector2f) {160, 60};
    sfVector2i pos;

    p_pos.x += size.x / 6;
    if (y == 1)
        p_pos.y += size.y / 4;
    if (y == -1)
        p_pos.y += size.y / 4 - 10;
    pos.x = (int) (p_pos.x - offset.x) / 32;
    pos.y = (int) (p_pos.y - offset.y) / 32;
    return (pos);
}

void quit_house(rpg_t *rpg)
{
    sfVector2i pos = get_position_house(rpg, 0, 1);

    rpg->house.bubble = 0;
    if (rpg->house.collisions[pos.y + 1][pos.x] == 'S' &&
    rpg->player.player.rect.top == 0)
        rpg->house.bubble = 1;
    if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == sfKeyE &&
    rpg->house.collisions[pos.y + 1][pos.x] == 'S' &&
    rpg->player.player.rect.top == 0) {
        rpg->scene = 1;
        rpg->game.door_open = 3;
        play_sound(rpg->game.s_door_close.sound, rpg);
        sfSprite_setPosition(rpg->player.player.sprite,
        (sfVector2f) {255, 210});
        sfSprite_setPosition(rpg->map.layer1.sprite,
        (sfVector2f) {-5010, -5370});
    }
}

void chess_house(rpg_t *rpg, sfVector2i pos)
{
    if ((rpg->house.collisions[pos.y + 1][pos.x] == 'C' ||
    rpg->house.collisions[pos.y - 1][pos.x] == 'C' ||
    rpg->house.collisions[pos.y][pos.x + 1] == 'C') && rpg->game.quest == 2)
        rpg->house.bubble = 1;
    if (rpg->house.collisions[pos.y - 1][pos.x] == 'A')
        rpg->house.bubble = 1;
    if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == sfKeyE
    && rpg->house.collisions[pos.y - 1][pos.x] == 'A')
        rpg->hunt = 1;
    if (rpg->event.type == sfEvtKeyPressed && rpg->event.key.code == sfKeyE &&
    (rpg->house.collisions[pos.y + 1][pos.x] == 'C' ||
    rpg->house.collisions[pos.y - 1][pos.x] == 'C' ||
    rpg->house.collisions[pos.y][pos.x + 1] == 'C')) {
        object_t obj;
        obj_list_push_back(&rpg->inv.obj,
        init_object_list(rpg->nbobj, 1, obj, "./res/sword.png"));
        rpg->nbobj = obj_list_len(rpg);
        rpg->talk.is_speaking = 1;
    }
}

void check_quest(rpg_t *rpg)
{
    if (rpg->game.quest == 1) {
        rpg->game.quest = 2;
        rpg->map.collisions[157][142] = ' ';
        rpg->map.collisions[177][165] = '9';
        rpg->map.collisions[159][140] = '9';
        destroy_sprite(&rpg->npcs.sp1);
        rpg->npcs.sp1 = init_sprite(init_rect(96, 32, 32, 32),
        "Free/after.png");
        sfSprite_setScale(rpg->npcs.sp1.sprite, (sfVector2f) {1.2, 1.2});
        rpg->npcs.sp4 = init_sprite(init_rect(64, 32, 32, 32),
        "Free/alert.png");
        sfSprite_setScale(rpg->npcs.sp4.sprite, (sfVector2f) {1.2, 1.2});
    }
}

void event_house(rpg_t *rpg)
{
    check_quest(rpg);
    if (rpg->event.type == sfEvtKeyPressed && rpg->game.quest == 2 &&
    rpg->talk.is_speaking == 1) {
        rpg->game.quest = 3;
        rpg->talk.is_speaking = 0;
    }
    player_movements(rpg);
    quit_house(rpg);
    chess_house(rpg, get_position_house(rpg, 0, 1));
}