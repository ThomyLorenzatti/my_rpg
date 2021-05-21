/*
** EPITECH PROJECT, 2021
** defender
** File description:
** defender
*/

#ifndef __STRUCT_KEY_H__
#define __STRUCT_KEY_H__

#include <struct_text.h>

typedef struct settkey_s
{
    int inventory;
    text_t kinventory;
    int skilltab;
    text_t kskilltab;
    int forward;
    text_t kforward;
    int backward;
    text_t kbackward;
    int right;
    text_t kright;
    int left;
    text_t kleft;
} settkey_t;

#endif /* !__RPG_H__ */