/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** menu.c
*/

#include <rpg.h>

void init_loader(rpg_t *rpg)
{
    rpg->menu = -8;
    rpg->loading.offset = 800;
    rpg->loading.rect.left = 0;
    rpg->loading.rect.top = 0;
    rpg->loading.rect.height = 600;
    rpg->loading.rect.width = 6400;
    rpg->loading.texture =
    sfTexture_createFromFile("res/loading_menu.jpg", NULL);
    rpg->loading.sprite = sfSprite_create();
}

void refresh_loader(rpg_t *rpg, int status)
{
    status *= -1;
    rpg->loading.rect.left = status * 800;
    sfSprite_setTexture(rpg->loading.sprite,
    rpg->loading.texture, sfTrue);
    sfSprite_setTextureRect(rpg->loading.sprite, rpg->loading.rect);
    sfRenderWindow_drawSprite(rpg->window, rpg->loading.sprite, NULL);
    sfRenderWindow_display(rpg->window);
}