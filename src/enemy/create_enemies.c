/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create enemies
*/

#include <rpg.h>

void destroy_all_enemies(rpg_t *rpg)
{
    enemies_t *temp = NULL;

    while (rpg->enemies) {
        temp = rpg->enemies;
        destroy_sprite(&temp->sp);
        sfClock_destroy(temp->a_clock);
        destroy_sprite(&temp->att);
        rpg->enemies = rpg->enemies->next;
    }
}

void create_enemies(rpg_t *rpg)
{
    char *buffer = load_file("enemies/enemies.txt");
    char **enemies = my_str_word_array(buffer, '\n');

    if (enemies == NULL)
        return;
    for (int i = 1; enemies[i]; i++)
        push_back_enemy(rpg, &rpg->enemies, enemies[i]);
}

void push_back_enemy2(rpg_t *rpg, enemies_t **list, char **data)
{
    if ((*list)->type == 2) {
        (*list)->cooldown = my_atoi(data[7]);
        (*list)->att = init_sprite(init_rect(0, 0, 32, 32), "enemies/fire.png");
    } else if ((*list)->type == 3) {
        (*list)->cooldown = my_atoi(data[7]);
        (*list)->att = init_sprite(init_rect(0, 0, 35, 35), "res/attack.png");
    } else {
        (*list)->cooldown = 0;
        (*list)->att = init_sprite(init_rect(0, 0, 32, 32), "enemies/fire.png");
    }
    (*list)->a_clock = sfClock_create();
    (*list)->swoosh = 0;
    (*list)->next = NULL;
}

void push_back_enemy(rpg_t *rpg, enemies_t **list, char *enemy)
{
    char **data = NULL;

    if ((*list)) {
        push_back_enemy(rpg, &((*list)->next), enemy);
        return;
    }
    data = my_str_word_array(enemy, ':');
    (*list) = my_malloc(sizeof(enemies_t));
    (*list)->sp = init_sprite(init_rect(0, 0, 32, 32), data[5]);
    sfSprite_setScale((*list)->sp.sprite, (sfVector2f) {1.2, 1.2});
    (*list)->sp.position.x = my_atoi(data[0]) * 32;
    (*list)->sp.position.y = my_atoi(data[1]) * 32;
    (*list)->life = my_atoi(data[2]);
    (*list)->speed = 2;
    (*list)->xp = my_atoi(data[4]);
    (*list)->attack = my_atoi(data[3]);
    (*list)->type = my_atoi(data[6]);
    push_back_enemy2(rpg, list, data);
}