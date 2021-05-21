/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** save
*/

#include <rpg.h>
#include <fcntl.h>
#include <unistd.h>

void putstr_file(char *str, int fd)
{
    write(fd, str, my_strlen(str));
    write(fd, "\n", 1);
}

void save_inventory(rpg_t *rpg, int fd)
{
    list_obj *temp = rpg->inv.obj;

    putstr_file("// inventory", fd);
    while (temp) {
        putstr_file(temp->value.look.path, fd);
        temp = temp->next;
    }
}

void save2(rpg_t *rpg, int fd)
{
    putstr_file("// pt / lvl", fd);
    putstr_file(my_unatoi(rpg->player.pt), fd);
    putstr_file(my_unatoi(rpg->player.lvl), fd);
    putstr_file("// attack, armor, speed", fd);
    putstr_file(my_unatoi(rpg->player.vattack), fd);
    putstr_file(my_unatoi(rpg->player.varmor), fd);
    putstr_file(my_unatoi(rpg->player.vspeed), fd);
    putstr_file("// quest", fd);
    putstr_file(my_unatoi(rpg->game.quest), fd);
    putstr_file("// quest", fd);
    putstr_file(my_unatoi(rpg->game.quest), fd);
    putstr_file("// skin", fd);
    putstr_file(my_unatoi(rpg->player.i_eye), fd);
    putstr_file(my_unatoi(rpg->player.i_hair), fd);
    putstr_file(my_unatoi(rpg->player.i_paint), fd);
    putstr_file(my_unatoi(rpg->player.i_pant), fd);
    putstr_file(my_unatoi(rpg->player.i_skin), fd);
    putstr_file(my_unatoi(rpg->player.i_vest), fd);
    save_inventory(rpg, fd);
}

void save(rpg_t *rpg)
{
    int fd = open("res/save/save.txt", O_WRONLY | O_CREAT | O_TRUNC, 00777);

    putstr_file("// player", fd);
    putstr_file(my_unatoi(rpg->player.player.position.x), fd);
    putstr_file(my_unatoi(rpg->player.player.position.y), fd);
    putstr_file("// map", fd);
    putstr_file(my_unatoi(rpg->map.layer1.position.x), fd);
    putstr_file(my_unatoi(rpg->map.layer1.position.y), fd);
    putstr_file("// boat", fd);
    putstr_file(my_unatoi(rpg->game.boat.position.x), fd);
    putstr_file(my_unatoi(rpg->game.boat.position.y), fd);
    putstr_file("// life", fd);
    putstr_file(my_unatoi(rpg->player.life), fd);
    putstr_file(my_unatoi(rpg->player.max_life), fd);
    putstr_file("// xp", fd);
    putstr_file(my_unatoi(rpg->player.xp), fd);
    putstr_file(my_unatoi(rpg->player.max_xp), fd);
    save2(rpg, fd);
    close(fd);
}