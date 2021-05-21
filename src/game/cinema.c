/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** cinema.c
*/

#include <rpg.h>

void init_cinema(rpg_t *rpg)
{
    rpg->cine = init_sprite(init_rect(0, 0, 800, 600),
    "./res/cinema/background.jpg");
    rpg->cinekeys = init_sprite(init_rect(0, 0, 75, 75), "./res/cinema/k.png");
    rpg->cine.clock2 = sfClock_create();
    rpg->cine.music = sfMusic_createFromFile("./res/cinema/donjon.ogg");
    rpg->cine.font = sfFont_createFromFile("res/font/donjon.ttf");
    rpg->cine.text = sfText_create();
    sfText_setFont(rpg->cine.text, rpg->cine.font);
    sfText_setColor(rpg->cine.text, sfWhite);
    sfText_setOutlineThickness(rpg->cine.text, 1);
    sfText_setOutlineColor(rpg->player.textpt, sfBlack);
    sfMusic_setVolume(rpg->cine.music, 15);
    rpg->cine.array = my_malloc(sizeof(char *) * 3);
    rpg->cine.array[0] = my_strdup("Welcome to the donjon !!");
    rpg->cine.array[1] = my_strdup("A boss is living there ...");
    rpg->cine.array[2] = my_strdup("Save the mayor, you ill be gratified");
    rpg->cine.index = 0;
    rpg->cine.size = 1;
    sfText_setPosition(rpg->cine.text, (sfVector2f) {200, 500});
    sfSprite_setOrigin(rpg->cine.sprite, (sfVector2f) {400, 300});
}

void text_positions(rpg_t *rpg)
{
    if (rpg->cine.index == 0)
        sfText_setPosition(rpg->cine.text, (sfVector2f) {200, 500});
    if (rpg->cine.index == 1)
        sfText_setPosition(rpg->cine.text, (sfVector2f) {215, 500});
    if (rpg->cine.index == 2)
        sfText_setPosition(rpg->cine.text, (sfVector2f) {107, 500});
}

void draw_cinema2(rpg_t *rpg)
{
    if (rpg->cine.seconds2 > 1) {
        rpg->cine.size += 0.001;
        text_positions(rpg);
        sfSprite_setScale(rpg->cine.sprite, (sfVector2f)
        {rpg->cine.size, rpg->cine.size});
        sfClock_restart(rpg->cine.clock2);
    }
    if (rpg->cine.rect.left >= 2400) {
        rpg->cine.rect.left = 0;
        rpg->scene = 7;
        rpg->cine.index = 0;
        return;
    }
}

void draw_cinema(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    rpg->cine.time = sfClock_getElapsedTime(rpg->cine.clock);
    rpg->cine.time2 = sfClock_getElapsedTime(rpg->cine.clock);
    rpg->cine.seconds = rpg->cine.time.microseconds / 1000000.0;
    rpg->cine.seconds2 = rpg->cine.time2.microseconds / 1000000.0;
    if (rpg->cine.seconds > 5) {
        rpg->cine.rect.left += 800;
        rpg->cine.size = 1;
        rpg->cine.index += 1;
        sfClock_restart(rpg->cine.clock);
    }
    draw_cinema2(rpg);
    sfText_setString(rpg->cine.text, rpg->cine.array[rpg->cine.index]);
    display_sprite(rpg->window, &rpg->cine, 400, 300);
    display_sprite(rpg->window, &rpg->cinekeys, 700, 25);
    sfRenderWindow_drawText(rpg->window, rpg->cine.text, NULL);
}

void cine_checker(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == sfKeyUp) {
        rpg->scene = 7;
    }
    if (rpg->event.type == sfEvtKeyPressed &&
    rpg->event.key.code == sfKeyRight) {
        rpg->cine.index += 1;
        rpg->cine.rect.left += 800;
        sfClock_restart(rpg->cine.clock);
    }
}