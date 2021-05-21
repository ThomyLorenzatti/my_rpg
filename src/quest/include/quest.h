/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __QUEST_H__
#define __QUEST_H__

#include <rpg.h>

void display_quest(rpg_t *rpg);
void display_dialog(rpg_t *rpg, sfVector2i pos);
int verif_pos(rpg_t *rpg, sfVector2i pos, char *chars);
int quest_npc2(rpg_t *rpg, sfVector2i pos);
int quest_npc(rpg_t *rpg, sfVector2i pos);
void npcs_talk(rpg_t *rpg);
void choose_pannel(rpg_t *rpg, sfVector2f pos);
void check_pannel(rpg_t *rpg);
void quest(rpg_t *rpg);

#endif /* !__RPG_H__ */