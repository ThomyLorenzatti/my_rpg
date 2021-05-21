/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-mathis.lorenzo
** File description:
** init_list.c
*/

#include <rpg.h>

void init_slot_list(rpg_t *rpg)
{
    slot_t s;

    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {224, 175}, 1, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {285, 175}, 2, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {350, 175}, 3, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {457, 175}, 4, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {523, 175}, 5, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {585, 175}, 6, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {224, 240}, 7, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {285, 240}, 8, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {350, 240}, 9, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {457, 240}, 10, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {523, 240}, 11, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {585, 240}, 12, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {224, 300}, 13, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {285, 300}, 14, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {350, 300}, 15, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {457, 300}, 16, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {523, 300}, 17, 0, s));
    slot_list_push_back(&rpg->inv.slot, i_s((sfVector2f) {585, 300}, 18, 0, s));
}

slot_t i_s(sfVector2f pos, int place, int free, slot_t to_init)
{
    to_init.pos = pos;
    to_init.place = place;
    to_init.free = free;
    to_init.clic = init_sprite(init_rect(0, 0, 50, 50), "./res/slotc.png");
    sfSprite_setOrigin(to_init.clic.sprite, (sfVector2f) {25, 25});
    return (to_init);
}

object_t init_object_list(int place, int nb, object_t to_init, char *path)
{
    to_init.look = init_sprite(init_rect(0, 0, 50, 50), path);
    sfSprite_setOrigin(to_init.look.sprite, (sfVector2f) {25, 25});
    to_init.place = place;
    to_init.nb = nb;
    return (to_init);
}

float get_distance(float cx, float cy, float x, float y)
{
    float xdist = x - cx;
    float ydist = y - cy;
    float res = sqrtf(pow(xdist, 2) + pow(ydist, 2));
    return (res);
}