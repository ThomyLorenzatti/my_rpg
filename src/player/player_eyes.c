/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load player skins
*/

#include <rpg.h>

void load_eyes(sfTexture **eyes)
{
    eyes[0] = sfTexture_createFromFile("player/eye/brown.png", NULL);
    eyes[1] = sfTexture_createFromFile("player/eye/dark.png", NULL);
    eyes[2] = sfTexture_createFromFile("player/eye/light-blue.png", NULL);
    eyes[3] = sfTexture_createFromFile("player/eye/light-green.png", NULL);
    eyes[4] = sfTexture_createFromFile("player/eye/light-yellow.png", NULL);
    eyes[5] = sfTexture_createFromFile("player/eye/pink2.png", NULL);
}