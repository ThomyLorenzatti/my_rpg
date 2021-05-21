/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** mp3.c
*/

#include <rpg.h>

void mp3_init(rpg_t *rpg)
{
    rpg->mplay = 0;
    rpg->track = 0;
    rpg->mp3b = init_sprite(init_rect(0, 0, 800, 600), "res/mp3b.png");
    rpg->mp3bc = init_sprite(init_rect(0, 0, 800, 600), "res/mp3bc.png");
    rpg->playlist[0] = create_sound(rpg, "./sound/playlist/phard.ogg", 10,
    "Play Hard - \nDavid Guetta");
    rpg->playlist[1] = create_sound(rpg, "./sound/playlist/montero.ogg", 10,
    "Montero - \nLil Nas X");
    rpg->playlist[2] = create_sound(rpg, "./sound/playlist/maiha.ogg", 10,
    "Dragostea - \nO-Zone");
    rpg->mp3f = sfFont_createFromFile("res/font/font.ttf");
    rpg->mp3t = sfText_create();
    sfText_setFont(rpg->mp3t, rpg->mp3f);
    sfText_setColor(rpg->mp3t, sfBlack);
    sfText_setPosition(rpg->mp3t, (sfVector2f) {605, 310});
}

void check_play(rpg_t *rpg, int play, int track)
{
    if (play == 1) {
        rpg->mplay = (rpg->mplay == 1) ? 0 : 1;
        if (rpg->mplay == 1)
            play_sound(rpg->playlist[rpg->track].sound, rpg);
        if (rpg->mplay == 0)
            sfSound_stop(rpg->playlist[rpg->track].sound);
        return;
    }
    if (track == 1) {
        sfSound_stop(rpg->playlist[rpg->track].sound);
        rpg->track += 1;
        rpg->track = (rpg->track >= NB_SONG) ? 0 : rpg->track;
        play_sound(rpg->playlist[rpg->track].sound, rpg);
    }
    if (track == -1) {
        sfSound_stop(rpg->playlist[rpg->track].sound);
        rpg->track -= 1;
        rpg->track = (rpg->track < 0) ? NB_SONG - 1 : rpg->track;
        play_sound(rpg->playlist[rpg->track].sound, rpg);
    }
}

void mp3_event(rpg_t *rpg)
{
    if (POS.x >= 745 && POS.x <= 790 && POS.y >= 240 && POS.y <= 285
    && rpg->mp3 == 1) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            rpg->mp3 = 0;
    }
    if (POS.x >= 640 && POS.x <= 690 && POS.y >= 475 && POS.y <= 520
    && rpg->mp3 == 1) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            check_play(rpg, 1, 0);
    }
    if (POS.x >= 700 && POS.x <= 742 && POS.y >= 475 && POS.y <= 520
    && rpg->mp3 == 1) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            check_play(rpg, 0, 1);
    }
    if (POS.x >= 585 && POS.x <= 625 && POS.y >= 475 && POS.y <= 520
    && rpg->mp3 == 1) {
        if (rpg->event.mouseButton.type == sfEvtMouseButtonPressed)
            check_play(rpg, 0, -1);
    }
}

void mp3_draw(rpg_t *rpg)
{
    if (rpg->mp3 == 1) {
        display_sprite(rpg->window, &rpg->mp3b, 0, 0);
        sfText_setString(rpg->mp3t, rpg->playlist[rpg->track].name);
        sfRenderWindow_drawText(rpg->window, rpg->mp3t, NULL);
    }
}