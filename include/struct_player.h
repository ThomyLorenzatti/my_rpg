/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_PLAYER_H__
#define __STRUCT_PLAYER_H__

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <struct_sprite.h>
#include <struct_sound.h>

typedef struct player_s player_t;

struct player_s {
    sprite_t player;
    sprite_t e;
    sfTexture *lifes[7];
    sprite_t life_bar;
    sprite_t heart;
    sfTexture *xps[7];
    sprite_t xp_bar;
    sprite_t xlogo;
    sfClock *hit;
    sfClock *moved;
    sprite_t skilltabmenu;
    sprite_t speedtree;
    sprite_t armortree;
    sprite_t attacktree;
    int hitted;
    int max_life;
    int life;
    int max_xp;
    int lvl;
    int xp;
    int vspeed;
    int vattack;
    int varmor;
    sfText *textpt;
    sfFont *fontpt;
    int pt;
    int move;
    int skilltab;
    sprite_t skin;
    sfTexture *skins[7];
    int i_skin;
    sprite_t pant;
    sfTexture *pants[7];
    int i_pant;
    sprite_t vest;
    sfTexture *vests[14];
    int i_vest;
    sprite_t paint;
    sfTexture *paints[4];
    int i_paint;
    sprite_t eye;
    sfTexture *eyes[6];
    int i_eye;
    sprite_t hair;
    sfTexture *hairs[16];
    int i_hair;
    sprite_t sword;
    sprite_t attack;
    int attacking;
    sound_t s_attack;
    sound_t levelup;
};

#endif /* !__RPG_H__ */