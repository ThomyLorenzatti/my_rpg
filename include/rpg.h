/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __RPG_H__
#define __RPG_H__

#define POS rpg->cursor.position
#define SLOT get_distance(tmp->value.pos.x, tmp->value.pos.y, POS.x, POS.y)
#define MAX_SKIN 7
#define MAX_PANT 7
#define MAX_VEST 14
#define MAX_PAINT 4
#define MAX_EYE 6
#define MAX_HAIR 16

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <my.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <struct_rpg.h>
#include <loading_menu.h>
#include <animation.h>
#include <boss.h>
#include <boat.h>
#include <custom.h>
#include <destroy.h>
#include <particles.h>
#include <cave.h>
#include <house.h>
#include <enemy.h>
#include <player.h>
#include <skill.h>
#include <inventory.h>
#include <save.h>
#include <menu.h>
#include <sound.h>
#include <quest.h>
#include <window.h>
#include <list.h>
#include <game.h>
#include <initialisation.h>

// project main / main.c
void event_window(rpg_t *rpg);

#endif /* !__RPG_H__ */