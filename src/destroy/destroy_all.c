/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** destroy all part 2
*/

#include <rpg.h>

void destroy_sprite(sprite_t *sp)
{
    sfTexture_destroy(sp->texture);
    sfSprite_destroy(sp->sprite);
    sfClock_destroy(sp->clock);
}

void destroy_sound(sound_t *s)
{
    sfSound_destroy(s->sound);
    sfSoundBuffer_destroy(s->buffer);
}

void destroy_particule_engine(rpg_t *rpg)
{
    for (int i = 0; i < MAX_PART; i++)
        sfClock_destroy(rpg->game.eng[i].clock);
}