/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_SOUND_H__
#define __STRUCT_SOUND_H__

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct sound_s sound_t;

struct sound_s {
    sfSound *sound;
    sfSoundBuffer *buffer;
    char *name;
};

#endif /* !__RPG_H__ */