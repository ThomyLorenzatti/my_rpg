/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __SOUND_H__
#define __SOUND_H__

#include <rpg.h>

void mp3_init(rpg_t *rpg);
void check_play(rpg_t *rpg, int play, int track);
void mp3_event(rpg_t *rpg);
void mp3_draw(rpg_t *rpg);
sound_t create_sound(rpg_t *rpg, char *path, int vol, char *name);
void play_sound(sfSound *sound, rpg_t *rpg);
void play_music(sfMusic *music, rpg_t *rpg);

#endif /* !__RPG_H__ */