/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** save load
*/

#include <rpg.h>

void load_inventory(rpg_t *rpg, char **data)
{
    object_t obj;

    if (!data[34])
        return;
    for (int i = 34; data[i]; i++) {
        obj_list_push_back(&rpg->inv.obj,
        init_object_list(rpg->nbobj, 1, obj, data[i]));
        rpg->nbobj = obj_list_len(rpg);
        if (my_strcmp(data[i], "./res/totem.png") == 0)
            rpg->nbtot += 1;
    }
}

void load_skin(rpg_t *rpg, char **data)
{
    rpg->player.i_eye = my_atoi(data[27]);
    rpg->player.i_hair = my_atoi(data[28]);
    rpg->player.i_paint = my_atoi(data[29]);
    rpg->player.i_pant = my_atoi(data[30]);
    rpg->player.i_skin = my_atoi(data[31]);
    rpg->player.i_vest = my_atoi(data[32]);
    change_parts(rpg);
}

void change_map(rpg_t *rpg)
{
    rpg->map.collisions[157][142] = ' ';
    rpg->map.collisions[177][165] = '9';
    rpg->map.collisions[159][140] = '9';
}

void save_load2(rpg_t *rpg, char **data)
{
    rpg->player.vattack = my_atoi(data[19]);
    rpg->player.attacktree.rect.left = 37 * (rpg->player.vattack - 1);
    rpg->player.varmor = my_atoi(data[20]);
    rpg->player.armortree.rect.left = 37 * rpg->player.varmor;
    rpg->player.vspeed = my_atoi(data[21]);
    rpg->player.speedtree.rect.left = 37 * (rpg->player.vspeed - 4);
    rpg->game.quest = my_atoi(data[23]);
    if (rpg->game.quest >= 2) {
        change_map(rpg);
        destroy_sprite(&rpg->npcs.sp1);
        rpg->npcs.sp1 = init_sprite(init_rect(96, 32, 32, 32),
        "Free/after.png");
        sfSprite_setScale(rpg->npcs.sp1.sprite, (sfVector2f) {1.2, 1.2});
        rpg->npcs.sp4 = init_sprite(init_rect(64, 32, 32, 32),
        "Free/alert.png");
        sfSprite_setScale(rpg->npcs.sp4.sprite, (sfVector2f) {1.2, 1.2});
    }
    load_skin(rpg, data);
    load_inventory(rpg, data);
}

void save_load(rpg_t *rpg)
{
    char *buffer = load_file("res/save/save.txt");
    char **data = NULL;

    destroy_inv(rpg);
    if (buffer == NULL)
        return;
    data = my_str_word_array(buffer, '\n');
    sfSprite_setPosition(rpg->player.player.sprite,
    (sfVector2f) {my_atoi(data[1]), my_atoi(data[2])});
    sfSprite_setPosition(rpg->map.layer1.sprite,
    (sfVector2f) {my_atoi(data[4]), my_atoi(data[5])});
    rpg->game.boat.position.x = my_atoi(data[7]);
    rpg->game.boat.position.y = my_atoi(data[8]);
    rpg->player.life = my_atoi(data[10]);
    rpg->player.max_life = my_atoi(data[11]);
    rpg->player.xp = my_atoi(data[13]);
    rpg->player.max_xp = my_atoi(data[14]);
    rpg->player.pt = my_atoi(data[16]);
    rpg->player.lvl = my_atoi(data[17]);
    save_load2(rpg, data);
}