/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** player attack 2
*/

#include <rpg.h>

void attack_enemies(rpg_t *rpg)
{
    enemies_t *temp = rpg->enemies;
    int index = 0;

    while (temp) {
        enemy_hitted(rpg, &temp);
        if (temp->life <= 0) {
            gain_xp(rpg, &temp);
            kill_enemy(rpg, &temp, index);
        }
        temp = temp->next;
        index++;
    }
}

void destroy_assets(rpg_t *rpg, enemies_t *temp2)
{
    destroy_sprite(&temp2->sp);
    sfClock_destroy(temp2->a_clock);
    destroy_sprite(&temp2->att);
}

void kill_enemy(rpg_t *rpg, enemies_t **enemy, int index)
{
    enemies_t *temp = rpg->enemies;
    enemies_t *temp2 = NULL;

    if (temp == NULL)
        return;
    if (index == 0) {
        temp2 = rpg->enemies;
        rpg->enemies = rpg->enemies->next;
        destroy_assets(rpg, temp2);
        return;
    }
    for (int i = 1; i < index; i++)
        temp = temp->next;
    temp2 = temp->next;
    temp->next = temp->next->next;
    destroy_assets(rpg, temp2);
}