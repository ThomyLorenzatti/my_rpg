/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** custom changes
*/

#include <rpg.h>

void check_index_parts2(rpg_t *rpg)
{
    rpg->player.i_skin = (rpg->player.i_skin < 0) ? MAX_SKIN - 1 :
    rpg->player.i_skin;
    rpg->player.i_skin = (rpg->player.i_skin >= MAX_SKIN) ? 0 :
    rpg->player.i_skin;
    rpg->player.i_vest = (rpg->player.i_vest < 0) ? MAX_VEST - 1 :
    rpg->player.i_vest;
    rpg->player.i_vest = (rpg->player.i_vest >= MAX_VEST) ? 0 :
    rpg->player.i_vest;
}

void check_index_parts(rpg_t *rpg)
{
    rpg->player.i_eye = (rpg->player.i_eye < 0) ? MAX_EYE - 1 :
    rpg->player.i_eye;
    rpg->player.i_eye = (rpg->player.i_eye >= MAX_EYE) ? 0 : rpg->player.i_eye;
    rpg->player.i_hair = (rpg->player.i_hair < 0) ? MAX_HAIR - 1 :
    rpg->player.i_hair;
    rpg->player.i_hair = (rpg->player.i_hair >= MAX_HAIR) ? 0 :
    rpg->player.i_hair;
    rpg->player.i_paint = (rpg->player.i_paint < 0) ? MAX_PAINT - 1 :
    rpg->player.i_paint;
    rpg->player.i_paint = (rpg->player.i_paint >= MAX_PAINT) ? 0 :
    rpg->player.i_paint;
    rpg->player.i_pant = (rpg->player.i_pant < 0) ? MAX_PANT - 1 :
    rpg->player.i_pant;
    rpg->player.i_pant = (rpg->player.i_pant >= MAX_PANT) ? 0 :
    rpg->player.i_pant;
    check_index_parts2(rpg);
}

void change_parts(rpg_t *rpg)
{
    sfTexture_destroy(rpg->player.eye.texture);
    sfTexture_destroy(rpg->player.hair.texture);
    sfTexture_destroy(rpg->player.paint.texture);
    sfTexture_destroy(rpg->player.pant.texture);
    sfTexture_destroy(rpg->player.skin.texture);
    sfTexture_destroy(rpg->player.vest.texture);
    rpg->player.eye.texture = sfTexture_copy(rpg->player.eyes[
    rpg->player.i_eye]);
    rpg->player.hair.texture = sfTexture_copy(rpg->player.hairs[
    rpg->player.i_hair]);
    rpg->player.paint.texture = sfTexture_copy(rpg->player.paints[
    rpg->player.i_paint]);
    rpg->player.pant.texture = sfTexture_copy(rpg->player.pants[
    rpg->player.i_pant]);
    rpg->player.skin.texture = sfTexture_copy(rpg->player.skins[
    rpg->player.i_skin]);
    rpg->player.vest.texture = sfTexture_copy(rpg->player.vests[
    rpg->player.i_vest]);
}