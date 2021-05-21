/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load player skins
*/

#include <rpg.h>

void load_pants(sfTexture **pants)
{
    pants[0] = sfTexture_createFromFile("player/pants/blue.png", NULL);
    pants[1] = sfTexture_createFromFile("player/pants/blue-mage.png", NULL);
    pants[2] = sfTexture_createFromFile("player/pants/brown.png", NULL);
    pants[3] = sfTexture_createFromFile("player/pants/green-mage.png", NULL);
    pants[4] = sfTexture_createFromFile("player/pants/purple-mage.png", NULL);
    pants[5] = sfTexture_createFromFile("player/pants/red.png", NULL);
    pants[6] = sfTexture_createFromFile("player/pants/red-mage.png", NULL);
}