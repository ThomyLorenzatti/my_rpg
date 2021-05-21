/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load player skins
*/

#include <rpg.h>

void load_paints(sfTexture **paints)
{
    paints[0] = sfTexture_createFromFile("player/paint/blue.png", NULL);
    paints[1] = sfTexture_createFromFile("player/paint/purple.png", NULL);
    paints[2] = sfTexture_createFromFile("player/paint/red.png", NULL);
    paints[3] = sfTexture_createFromFile("player/paint/scar.png", NULL);
}