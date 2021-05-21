/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** npcs talk
*/

#include <rpg.h>

int verif_pos(rpg_t *rpg, sfVector2i pos, char *chars)
{
    if ((pos.y - 1 >= 0 &&
    my_char_in_str(rpg->map.collisions[pos.y - 1][pos.x], chars) == 1) ||
    (rpg->map.collisions[pos.y + 1] &&
    my_char_in_str(rpg->map.collisions[pos.y + 1][pos.x], chars) == 1) ||
    (pos.x - 1 >= 0 &&
    my_char_in_str(rpg->map.collisions[pos.y][pos.x - 1], chars) == 1) ||
    (rpg->map.collisions[pos.y][pos.x + 1] &&
    my_char_in_str(rpg->map.collisions[pos.y][pos.x + 1], chars) == 1))
        return (1);
    return (0);
}

int quest_npc2(rpg_t *rpg, sfVector2i pos)
{
    if (rpg->game.quest >= 2 && verif_pos(rpg, pos, "9") == 1 &&
    ((pos.x == 140 && pos.y == 160) ||
    (pos.x == 139 && pos.y == 159) || (pos.x == 141 && pos.y == 159))) {
        rpg->talk.is_speaking = 1;
        sfText_setString(rpg->talk.text,
        "I saw them going west towards the port with the mayor!");
        return (1);
    }
    if (verif_pos(rpg, pos, "M") == 1) {
        rpg->talk.is_speaking = 1;
        rpg->markop = 1;
        sfText_setString(rpg->talk.text,
        "Hello young explorer! Do you need something ?");
        return (1);
    }
    return (0);
}

int quest_npc(rpg_t *rpg, sfVector2i pos)
{
    if (rpg->game.quest == 0 && rpg->map.collisions[pos.y - 1][pos.x]
    == '9' && pos.x == 142 && pos.y == 158) {
        rpg->talk.is_speaking = 1;
        sfText_setString(rpg->talk.text, "Take it! It will be useful!");
        object_t obj;
        obj_list_push_back(&rpg->inv.obj,
        init_object_list(rpg->nbobj, 1, obj, "./res/key.png"));
        rpg->nbobj = obj_list_len(rpg);
        rpg->game.quest = 1;
        return (1);
    }
    if (rpg->game.quest >= 2 && verif_pos(rpg, pos, "9") == 1 &&
    ((pos.x == 165 && pos.y == 176) || (pos.x == 165 && pos.y == 178) ||
    (pos.x == 164 && pos.y == 177) || (pos.x == 166 && pos.y == 177))) {
        rpg->talk.is_speaking = 1;
        sfText_setString(rpg->talk.text,
        "We need your help! The mayor has disappeared!");
        return (1);
    }
    return (quest_npc2(rpg, pos));
}

void npcs_talk(rpg_t *rpg)
{
    sfVector2f temp = get_player_position(rpg, 0, 1);
    sfVector2i pos = (sfVector2i) {(int) temp.x, (int) temp.y};
    int len = 0;
    char **texts = NULL;

    if (rpg->event.type == sfEvtKeyPressed) {
        if (rpg->event.key.code != sfKeyE) {
            rpg->talk.is_speaking = 0;
            return;
        }
    } else
        return;
    if (quest_npc(rpg, pos) == 1)
        return;
    texts = my_str_word_array(load_file("res/dialogs.txt"), '\n');
    for (; texts[len]; len++);
    if (verif_pos(rpg, pos, "9") == 1) {
        sfText_setString(rpg->talk.text, texts[rand() % len]);
        rpg->talk.is_speaking = 1;
    }
}