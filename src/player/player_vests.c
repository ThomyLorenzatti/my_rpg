/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load player skins
*/

#include <rpg.h>

void load_vests(sfTexture **vests)
{
    vests[0] = sfTexture_createFromFile("player/vest/black-noble.png", NULL);
    vests[1] = sfTexture_createFromFile("player/vest/blue-mage.png", NULL);
    vests[2] = sfTexture_createFromFile("player/vest/blue-noble.png", NULL);
    vests[3] = sfTexture_createFromFile("player/vest/brown-robe.png", NULL);
    vests[4] = sfTexture_createFromFile("player/vest/dark-cloth.png", NULL);
    vests[5] = sfTexture_createFromFile("player/vest/elven-cloth.png", NULL);
    vests[6] = sfTexture_createFromFile("player/vest/green-mage.png", NULL);
    vests[7] = sfTexture_createFromFile("player/vest/green-noble.png", NULL);
    vests[8] = sfTexture_createFromFile("player/vest/light-cloth.png", NULL);
    vests[9] = sfTexture_createFromFile("player/vest/purple-cloth.png", NULL);
    vests[10] = sfTexture_createFromFile("player/vest/purple-mage.png", NULL);
    vests[11] = sfTexture_createFromFile("player/vest/purple-noble.png", NULL);
    vests[12] = sfTexture_createFromFile("player/vest/red-mage.png", NULL);
    vests[13] = sfTexture_createFromFile("player/vest/yellow-cloth.png", NULL);
}