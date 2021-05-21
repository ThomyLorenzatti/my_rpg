/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load player skins
*/

#include <rpg.h>

void load_hairs(sfTexture **hairs)
{
    hairs[0] = sfTexture_createFromFile("player/hair/black-pony.png", NULL);
    hairs[1] = sfTexture_createFromFile("player/hair/blonde-pony.png", NULL);
    hairs[2] = sfTexture_createFromFile("player/hair/brown-pony.png", NULL);
    hairs[3] = sfTexture_createFromFile("player/hair/gray-pony.png", NULL);
    hairs[4] = sfTexture_createFromFile("player/hair/long-black.png", NULL);
    hairs[5] = sfTexture_createFromFile("player/hair/long-brown.png", NULL);
    hairs[6] = sfTexture_createFromFile("player/hair/long-red.png", NULL);
    hairs[7] = sfTexture_createFromFile("player/hair/red-pony.png", NULL);
    hairs[8] = sfTexture_createFromFile("player/hair/short-black.png", NULL);
    hairs[9] = sfTexture_createFromFile("player/hair/short-blonde.png", NULL);
    hairs[10] = sfTexture_createFromFile("player/hair/short-brown.png", NULL);
    hairs[11] = sfTexture_createFromFile("player/hair/short-red.png", NULL);
    hairs[12] = sfTexture_createFromFile("player/hair/spiked-black.png", NULL);
    hairs[13] = sfTexture_createFromFile("player/hair/spiked-blonde.png", NULL);
    hairs[14] = sfTexture_createFromFile("player/hair/spiked-blue.png", NULL);
    hairs[15] = sfTexture_createFromFile("player/hair/spiked-red.png", NULL);
}