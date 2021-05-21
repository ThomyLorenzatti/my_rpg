/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load player skins
*/

#include <rpg.h>

void load_skins(sfTexture **skins)
{
    skins[0] = sfTexture_createFromFile("player/skin/black.png", NULL);
    skins[1] = sfTexture_createFromFile("player/skin/black2.png", NULL);
    skins[2] = sfTexture_createFromFile("player/skin/green.png", NULL);
    skins[3] = sfTexture_createFromFile("player/skin/green-moss.png", NULL);
    skins[4] = sfTexture_createFromFile("player/skin/pale.png", NULL);
    skins[5] = sfTexture_createFromFile("player/skin/red.png", NULL);
    skins[6] = sfTexture_createFromFile("player/skin/white.png", NULL);
}