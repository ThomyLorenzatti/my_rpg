/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** enimies gestions
*/

#include <rpg.h>

sfVector2f get_dir_ball(rpg_t *rpg, sfVector2f p_pos, sfVector2f e_pos,
sfVector2f dir)
{
    if (e_pos.x - 8 > p_pos.x + 32 + 8)
        return ((sfVector2f) {-6, 0});
    else if (e_pos.x + 32 + 8 < p_pos.x - 8)
        return ((sfVector2f) {6, 0});
    if (e_pos.y > p_pos.y + 32 + 24 && p_pos.x + 32 + 24 > e_pos.x - 24 &&
    p_pos.x - 24 < e_pos.x + 32 + 24)
        return ((sfVector2f) {0, -6});
    if (e_pos.y + 32 + 16 < p_pos.y + 24 &&
    p_pos.x + 32 + 24 > e_pos.x - 24 && p_pos.x - 24 < e_pos.x + 32 + 24)
        return ((sfVector2f) {0, 6});
    return (dir);
}

void enemy_fire_ball(rpg_t *rpg, enemies_t *temp)
{
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);
    sfVector2f e_pos = sfSprite_getPosition(temp->sp.sprite);

    check_damage(rpg, temp->att, temp);
    if (check_clock_eng(rpg, 0.1, temp->att.clock) == 1) {
        temp->att.position.x += temp->dir.x;
        temp->att.position.y += temp->dir.y;
    }
    if (check_clock_eng(rpg, temp->cooldown, temp->a_clock) == 0)
        return;
    temp->att.position = temp->sp.position;
    temp->dir = get_dir_ball(rpg, p_pos, e_pos, temp->dir);
}

sfVector2f get_dir_swoosh(rpg_t *rpg, sfVector2f e_pos,
sfVector2f dir, enemies_t *temp)
{
    sfVector2f p_pos = sfSprite_getPosition(rpg->player.player.sprite);

    if (e_pos.x - 8 > p_pos.x + 32 + 8) {
        temp->att.rect.top = 35 * 1;
        return ((sfVector2f) {-32 + 10, 0});
    } else if (e_pos.x + 32 + 8 < p_pos.x - 8) {
        temp->att.rect.top = 35 * 2;
        return ((sfVector2f) {32 - 10, 0});
    }
    if (e_pos.y > p_pos.y + 32 + 24 && p_pos.x + 32 + 24 > e_pos.x - 24 &&
    p_pos.x - 24 < e_pos.x + 32 + 24) {
        temp->att.rect.top = 35 * 3;
        return ((sfVector2f) {0, -32 + 10});
    }
    if (e_pos.y + 32 + 16 < p_pos.y + 24 &&
    p_pos.x + 32 + 24 > e_pos.x - 24 && p_pos.x - 24 < e_pos.x + 32 + 24) {
        temp->att.rect.top = 35 * 0;
        return ((sfVector2f) {0, 32 - 10});
    }
    return (dir);
}

void enemy_swoosh(rpg_t *rpg, enemies_t *temp)
{
    sfVector2f e_pos = sfSprite_getPosition(temp->sp.sprite);

    check_damage(rpg, temp->att, temp);
    if (check_clock_eng(rpg, 0.1, temp->att.clock) == 1) {
        temp->att.rect.left += 35;
        if (temp->att.rect.left >= 5 * 35)
            temp->swoosh = 0;
        sfSprite_setTextureRect(temp->att.sprite, temp->att.rect);
    }
    if (check_clock_eng(rpg, temp->cooldown, temp->a_clock) == 0)
        return;
    temp->swoosh = 1;
    temp->att.position = temp->sp.position;
    temp->dir = get_dir_swoosh(rpg, e_pos, temp->dir, temp);
    temp->att.rect.left = 0;
    sfSprite_setTextureRect(temp->att.sprite, temp->att.rect);
}

void enemies_damages(rpg_t *rpg)
{
    enemies_t *temp = rpg->enemies;

    while (temp) {
        check_damage(rpg, temp->sp, temp);
        if (temp->type == 2)
            enemy_fire_ball(rpg, temp);
        if (temp->type == 3)
            enemy_swoosh(rpg, temp);
        temp = temp->next;
    }
}