/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init player
*/

#include <rpg.h>

void create_perso2(rpg_t *rpg)
{
    rpg->player.eye = init_sprite(init_rect(0, 48, 48, 48), "res/bg.jpg");
    sfTexture_destroy(rpg->player.eye.texture);
    rpg->player.eye.texture = sfTexture_copy(rpg->player.eyes[0]);
    rpg->player.hair = init_sprite(init_rect(0, 48, 48, 48), "res/bg.jpg");
    sfTexture_destroy(rpg->player.hair.texture);
    rpg->player.hair.texture = sfTexture_copy(rpg->player.hairs[0]);
    rpg->player.sword = init_sprite(init_rect(0, 48, 48, 48),
    "player/sword.png");
    rpg->player.i_skin = 0;
    rpg->player.i_pant = 0;
    rpg->player.i_vest = 0;
    rpg->player.i_paint = 0;
    rpg->player.i_eye = 0;
    rpg->player.i_hair = 0;
    rpg->player.skilltab = 0;
    rpg->player.varmor = 0;
    rpg->player.vattack = 1;
    rpg->player.pt = 10;
    init_skilltab(rpg);
}

void create_perso(rpg_t *rpg)
{
    load_skins(rpg->player.skins);
    load_pants(rpg->player.pants);
    load_vests(rpg->player.vests);
    load_paints(rpg->player.paints);
    load_eyes(rpg->player.eyes);
    load_hairs(rpg->player.hairs);
    rpg->player.skin = init_sprite(init_rect(0, 48, 48, 48), "res/bg.jpg");
    sfTexture_destroy(rpg->player.skin.texture);
    rpg->player.skin.texture = sfTexture_copy(rpg->player.skins[0]);
    rpg->player.pant = init_sprite(init_rect(0, 48, 48, 48), "res/bg.jpg");
    sfTexture_destroy(rpg->player.pant.texture);
    rpg->player.pant.texture = sfTexture_copy(rpg->player.pants[0]);
    rpg->player.vest = init_sprite(init_rect(0, 48, 48, 48), "res/bg.jpg");
    sfTexture_destroy(rpg->player.vest.texture);
    rpg->player.vest.texture = sfTexture_copy(rpg->player.vests[0]);
    rpg->player.paint = init_sprite(init_rect(0, 48, 48, 48), "res/bg.jpg");
    sfTexture_destroy(rpg->player.paint.texture);
    rpg->player.paint.texture = sfTexture_copy(rpg->player.paints[0]);
    create_perso2(rpg);
}

void create_player(rpg_t *rpg)
{
    rpg->player.player = init_sprite(init_rect(0, 0, 48, 48),
    "player/skin/green.png");
    rpg->player.player.position = (sfVector2f) {200, 250};
    sfSprite_setPosition(rpg->player.player.sprite, (sfVector2f) {255, 210});
    rpg->player.vspeed = 4;
    rpg->player.e = init_sprite(init_rect(0, 0, 50, 50), "res/ebubble.png");
    rpg->player.max_life = 6;
    rpg->player.life = 6;
    rpg->player.max_xp = 6;
    rpg->player.xp = 0;
    rpg->player.lvl = 0;
    load_xp_life_bar(rpg);
    rpg->player.heart = init_sprite(init_rect(0, 0, 35, 35), "res/life/h.png");
    rpg->player.xlogo = init_sprite(init_rect(0, 0, 28, 35), "res/xp/xp.png");
    rpg->player.hit = sfClock_create();
    create_perso(rpg);
    rpg->player.attack = init_sprite(init_rect(0, 0, 35, 35), "res/attack.png");
    rpg->player.attacking = 0;
    rpg->player.moved = sfClock_create();
}

void load_xp_life_bar(rpg_t *rpg)
{
    rpg->player.life_bar = init_sprite(init_rect(0, 0, 150, 30),
    "res/life/1.png");
    rpg->player.lifes[0] = sfTexture_createFromFile("./res/life/1.png", NULL);
    rpg->player.lifes[1] = sfTexture_createFromFile("./res/life/2.png", NULL);
    rpg->player.lifes[2] = sfTexture_createFromFile("./res/life/3.png", NULL);
    rpg->player.lifes[3] = sfTexture_createFromFile("./res/life/4.png", NULL);
    rpg->player.lifes[4] = sfTexture_createFromFile("./res/life/5.png", NULL);
    rpg->player.lifes[5] = sfTexture_createFromFile("./res/life/6.png", NULL);
    rpg->player.lifes[6] = sfTexture_createFromFile("./res/life/7.png", NULL);
    rpg->player.xp_bar = init_sprite(init_rect(0, 0, 150, 30), "res/xp/1.png");
    rpg->player.xps[0] = sfTexture_createFromFile("./res/xp/1.png", NULL);
    rpg->player.xps[1] = sfTexture_createFromFile("./res/xp/2.png", NULL);
    rpg->player.xps[2] = sfTexture_createFromFile("./res/xp/3.png", NULL);
    rpg->player.xps[3] = sfTexture_createFromFile("./res/xp/4.png", NULL);
    rpg->player.xps[4] = sfTexture_createFromFile("./res/xp/5.png", NULL);
    rpg->player.xps[5] = sfTexture_createFromFile("./res/xp/6.png", NULL);
    rpg->player.xps[6] = sfTexture_createFromFile("./res/xp/7.png", NULL);
}