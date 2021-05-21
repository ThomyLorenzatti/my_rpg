/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** destroy player
*/

#include <rpg.h>

void destroy_all4(rpg_t *rpg)
{
    sfClock_destroy(rpg->boss.f_attack);
    destroy_particule_engine(rpg);
    destroy_sound(&rpg->game.s_door_open);
    destroy_sound(&rpg->game.s_door_close);
    destroy_sprite(&rpg->blueoption);
    destroy_sprite(&rpg->redoption);
    destroy_sprite(&rpg->greyoption1);
    destroy_sprite(&rpg->greyoption2);
}

void destroy_all3(rpg_t *rpg)
{
    destroy_sound(&rpg->player.levelup);
    destroy_sound(&rpg->pdc);
    destroy_sound(&rpg->clic);
    destroy_sprite(&rpg->map.lava);
    destroy_sprite(&rpg->map.cave_wall);
    destroy_sprite(&rpg->map.cave_ground);
    destroy_sprite(&rpg->map.cave);
    sfMusic_destroy(rpg->cine.music);
    destroy_all_enemies(rpg);
    destroy_sprite(&rpg->cine);
    sfClock_destroy(rpg->cine.clock2);
    sfText_destroy(rpg->cine.text);
    destroy_sprite(&rpg->duck);
    destroy_sprite(&rpg->market);
    destroy_sprite(&rpg->mb);
    destroy_sprite(&rpg->cred);
    destroy_sprite(&rpg->cgreen);
    for (int i = 0; i < NB_SONG; i++)
        destroy_sound(&(rpg->playlist[i]));
    destroy_all4(rpg);
}

void destroy_all2(rpg_t *rpg)
{
    destroy_sprite(&rpg->npcs.sp2);
    destroy_sprite(&rpg->npcs.sp3);
    destroy_sprite(&rpg->talk.bg);
    sfFont_destroy(rpg->talk.font);
    sfText_destroy(rpg->talk.text);
    destroy_sprite(&rpg->player.e);
    destroy_sprite(&rpg->persom);
    destroy_sprite(&rpg->inv.inv);
    sfTexture_destroy(rpg->loading.texture);
    sfSprite_destroy(rpg->loading.sprite);
    destroy_sprite(&rpg->player.life_bar);
    destroy_sprite(&rpg->player.xp_bar);
    for (int i = 0; i < 7; i++) {
        sfTexture_destroy(rpg->player.lifes[i]);
        sfTexture_destroy(rpg->player.xps[i]);
    }
    destroy_sprite(&rpg->player.heart);
    destroy_sprite(&rpg->player.xlogo);
    sfClock_destroy(rpg->player.hit);
    destroy_all3(rpg);
}

void destroy_all(rpg_t *rpg)
{
    destroy_sprite(&rpg->back);
    destroy_sprite(&rpg->game.water);
    destroy_sprite(&rpg->map.layer1);
    destroy_sprite(&rpg->player.player);
    destroy_sprite(&rpg->mbg);
    destroy_sprite(&rpg->mbutton);
    destroy_sprite(&rpg->playc);
    destroy_sprite(&rpg->loadc);
    destroy_sprite(&rpg->optionc);
    destroy_sprite(&rpg->quitc);
    destroy_sprite(&rpg->moption);
    destroy_sprite(&rpg->fpsc);
    destroy_sprite(&rpg->backc);
    destroy_sprite(&rpg->map.houses);
    destroy_sprite(&rpg->map.path);
    destroy_sprite(&rpg->map.border);
    destroy_all2(rpg);
    destroy_cursor(rpg);
    sfRenderWindow_destroy(rpg->window);
    destroy_sprite(&rpg->npcs.sp1);
}