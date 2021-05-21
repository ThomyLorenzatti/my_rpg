/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create sounds
*/

#include <rpg.h>

sound_t create_sound(rpg_t *rpg, char *path, int vol, char *name)
{
    sound_t s;

    s.sound = sfSound_create();
    s.buffer = sfSoundBuffer_createFromFile(path);
    s.name = name;
    sfSound_setBuffer(s.sound, s.buffer);
    sfSound_setVolume(s.sound, vol);
    return (s);
}