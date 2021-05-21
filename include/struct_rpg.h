/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_RPG_H__
#define __STRUCT_RPG_H__

#define MAX_PART 300
#define NB_SONG 3

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <struct_sprite.h>
#include <struct_sound.h>
#include <struct_particles.h>
#include <struct_player.h>
#include <struct_map.h>
#include <struct_npc.h>
#include <struct_talk.h>
#include <struct_house.h>
#include <struct_enemies.h>
#include <struct_boss.h>
#include <struct_cursor.h>
#include <struct_menu.h>
#include <struct_inventory.h>
#include <struct_text.h>
#include <struct_key.h>

typedef struct rpg_s rpg_t;
typedef struct game_s game_t;

struct game_s {
    sprite_t water;
    sprite_t rain;
    int quest;
    sprite_t door;
    int door_open;
    sprite_t boat;
    int is_boat;
    int deboat;
    particle_t part[MAX_PART];
    sfClock *clock_part;
    pengine_t eng[MAX_PART];
    sfClock *eng_clock;
    sfClock *eng_clock_up;
    sound_t s_door_open;
    sound_t s_door_close;
};

struct rpg_s {
    sfRenderWindow *window;
    sfVector2u window_size;
    cursor_t cursor;
    sfText *moneyt;
    sfFont *moneyf;
    sfTime time;
    sfEvent event;
    int mp3;
    int mplay;
    int track;
    sfText *mp3t;
    sfFont *mp3f;
    int musicv;
    int soundv;
    int nbheal;
    int nbsp;
    int nbtot;
    int nbpet;
    int nbps;
    int nbmp3;
    int nbobj;
    int scene;
    int lastscene;
    int menu;
    int fps;
    int hunt;
    int money;
    int markop;
    sound_t pdc;
    sound_t clic;
    sound_t playlist[NB_SONG];
    inv_t inv;
    sprite_t mp3b;
    sprite_t mp3bc;
    sprite_t gtmc;
    sprite_t hback;
    sprite_t duck;
    sfClock *dc;
    sprite_t customb;
    sprite_t pcc;
    sprite_t arr_hd;
    sprite_t htp;
    sprite_t htpm;
    sprite_t arr_hg;
    sprite_t arr_cd;
    sprite_t arr_cg;
    sprite_t market;
    sprite_t mb;
    int custom_click;
    sprite_t gom;
    sprite_t gomb;
    sprite_t back;
    sprite_t congrat;
    sprite_t conquit;
    sprite_t pause;
    sprite_t pausec;
    sprite_t key;
    sprite_t sword;
    sprite_t mbg;
    sprite_t mbutton;
    sprite_t playc;
    sprite_t loadc;
    sprite_t optionc;
    sprite_t quitc;
    sprite_t moption;
    sprite_t fpsc;
    sprite_t backc;
    sprite_t cgreen;
    sprite_t cred;
    sprite_t persom;
    sprite_t cine;
    sprite_t cinekeys;
    sprite_t greyoption1;
    sprite_t greyoption2;
    sprite_t redoption;
    sprite_t blueoption;
    menu_t loading;
    game_t game;
    player_t player;
    map_t map;
    house_t house;
    npc_t npcs;
    talk_t talk;
    enemies_t *enemies;
    boss_t boss;
    settkey_t settkey;
};

#endif /* !__RPG_H__ */