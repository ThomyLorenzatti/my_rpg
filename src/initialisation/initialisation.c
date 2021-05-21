/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** initialisation.c
*/

#include "rpg.h"

void create_npcs(rpg_t *rpg)
{
    rpg->npcs.sp1 = init_sprite(init_rect(0, 32, 32, 32), "./Free/mayor.png");
    sfSprite_setPosition(rpg->npcs.sp1.sprite, (sfVector2f) {0, 0});
    sfSprite_setScale(rpg->npcs.sp1.sprite, (sfVector2f) {1.2, 1.2});
    rpg->npcs.sp2 = init_sprite(init_rect(0, 32, 32, 32), "./Free/npc.png");
    sfSprite_setPosition(rpg->npcs.sp2.sprite, (sfVector2f) {0, 0});
    sfSprite_setScale(rpg->npcs.sp2.sprite, (sfVector2f) {1.2, 1.2});
    rpg->npcs.sp3 = init_sprite(init_rect(0, 32, 32, 32), "./Free/npc2.png");
    sfSprite_setPosition(rpg->npcs.sp3.sprite, (sfVector2f) {0, 0});
    sfSprite_setScale(rpg->npcs.sp3.sprite, (sfVector2f) {1.2, 1.2});
}

void create_talk(rpg_t *rpg)
{
    rpg->talk.bg = init_sprite(init_rect(0, 0, 800, 100), "res/talk.png");
    rpg->talk.font = sfFont_createFromFile("res/font/font.ttf");
    rpg->talk.text = sfText_create();
    sfText_setFont(rpg->talk.text, rpg->talk.font);
    sfText_setString(rpg->talk.text, "Test a dialog");
    sfText_setPosition(rpg->talk.text, (sfVector2f) {35, 510});
    rpg->talk.is_speaking = 0;
}

void init_game3(rpg_t *rpg)
{
    event_window(rpg);
    create_talk(rpg);
    end_init(rpg);
    rpg->clic = create_sound(rpg, "sound/clic.ogg", 50, "clic");
    init_hunt(rpg);
    rpg->boss.c_move = sfClock_create();
    rpg->boss.state = 1;
    rpg->boss.c_attack = sfClock_create();
    init_market(rpg);
    mp3_init(rpg);
    rpg->boss.attack = 2;
    rpg->boss.f_attack = sfClock_create();
    rpg->boss.fire = init_sprite(init_rect(0, 0, 32, 32), "enemies/fire.png");
    rpg->game.eng_clock = sfClock_create();
    rpg->game.eng_clock_up = sfClock_create();
    init_particule_engine(rpg);
    refresh_loader(rpg, -8);
}

void init_game2(rpg_t *rpg)
{
    get_collisions_cave(rpg);
    init_object(rpg);
    init_pause(rpg);
    init_custom(rpg);
    init_house(rpg);
    event_window(rpg);
    rpg->enemies = NULL;
    rpg->game.s_door_open = create_sound(rpg, "sound/open_door.wav", 5, "door");
    rpg->game.s_door_close = create_sound(rpg,
    "sound/close_door.wav", 5, "door");
    rpg->pdc = create_sound(rpg, "sound/pdc.ogg", 50, "pdc");
    rpg->boss.live = 12;
    rpg->boss.sp = init_sprite(init_rect(0, 0, 96, 96), "enemies/minotaur.png");
    rpg->boss.map = init_sprite(init_rect(0, 0, 900, 900), "map/arene.png");
    rpg->boss.map.position = (sfVector2f) {0, 0};
    get_collisions_boss(rpg);
    rpg->boss.ic = init_sprite(init_rect(0, 0, 403, 483), "res/boss_ic.png");
    sfSprite_setScale(rpg->boss.sp.sprite, (sfVector2f) {1.6, 1.6});
    rpg->boss.sp.position = (sfVector2f) {200, 200};
    init_game3(rpg);
}

void init_game(rpg_t *rpg)
{
    rpg->window = create_window(800, 600, "RPG", 32);
    rpg->cursor = create_cursor();
    init_loader(rpg);
    refresh_loader(rpg, -1);
    create_menu(rpg);
    refresh_loader(rpg, -2);
    create_inventory(rpg);
    refresh_loader(rpg, -3);
    create_game(rpg);
    refresh_loader(rpg, -4);
    create_player(rpg);
    event_window(rpg);
    refresh_loader(rpg, -5);
    create_map(rpg);
    refresh_loader(rpg, -6);
    get_collisions(rpg);
    refresh_loader(rpg, -7);
    create_npcs(rpg);
    init_game2(rpg);
    init_cinema(rpg);
}