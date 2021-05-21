/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-my_rpg-mathis.lorenzo
** File description:
** spritelist.c
*/

#include <rpg.h>

void slot_list_push_back(list_slot **list, slot_t value)
{
    list_slot *node = malloc(sizeof(*node));
    list_slot *temp;

    node->value = value;
    node->next = NULL;
    if ((*list) == NULL)
        (*list) = node;
    else {
        for (temp = (*list); temp->next != NULL; temp = temp->next);
        temp->next = node;
    }
}

void slot_list_destroy(list_slot **list)
{
    list_slot *node = (*list);
    list_slot *tmp = NULL;

    while (node != NULL) {
        tmp = node->next;
        free(node);
        node = tmp;
    }
}

void obj_list_push_back(list_obj **list, object_t value)
{
    list_obj *node = my_malloc(sizeof(*node));
    list_obj *temp;

    node->value = value;
    node->next = NULL;
    if ((*list) == NULL)
        (*list) = node;
    else {
        for (temp = (*list); temp->next != NULL; temp = temp->next);
        temp->next = node;
    }
}

void obj_list_destroy(list_obj **list)
{
    list_obj *node = (*list);
    list_obj *tmp = NULL;

    while (node != NULL) {
        tmp = node->next;
        free(node);
        node = tmp;
    }
}