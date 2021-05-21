/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** sounds.c
*/

#include <rpg.h>

void play_sound(sfSound *sound, rpg_t *rpg)
{
    sfSound_setVolume(sound, rpg->soundv);
    sfSound_play(sound);
}

void play_music(sfMusic *music, rpg_t *rpg)
{
    sfMusic_setVolume(music, rpg->musicv);
    sfMusic_play(music);
}