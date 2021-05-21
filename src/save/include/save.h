/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __SAVE_H__
#define __SAVE_H__

#include <rpg.h>

void load_inventory(rpg_t *rpg, char **data);
void load_skin(rpg_t *rpg, char **data);
void change_map(rpg_t *rpg);
void save_load2(rpg_t *rpg, char **data);
void save_load(rpg_t *rpg);
void putstr_file(char *str, int fd);
void save_inventory(rpg_t *rpg, int fd);
void save2(rpg_t *rpg, int fd);
void save(rpg_t *rpg);

#endif /* !__RPG_H__ */