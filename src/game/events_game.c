/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event game
*/

#include <rpg.h>

void event_game3(rpg_t *rpg, sfMouseButtonEvent mouse)
{
    if (rpg->scene == 4)
        custom_event(rpg);
    if (rpg->scene == 7) {
        player_movements(rpg);
        inventory_event(rpg);
        skilltab_event(rpg, mouse);
        player_attack(rpg);
    }
    if (rpg->scene == 8)
        end_event(rpg);
}

void event_game2(rpg_t *rpg, sfMouseButtonEvent mouse)
{
    if (rpg->scene == 5)
        gover_event(rpg);
    if ((rpg->scene == 0 && rpg->menu == 0) || rpg->menu == 3)
        menu_event_gestion(rpg);
    if (rpg->scene == 0 && rpg->menu == 2)
        option_event(rpg);
    if (rpg->scene == 6) {
        cave_events(rpg);
        player_movements(rpg);
        inventory_event(rpg);
        skilltab_event(rpg, mouse);
        player_attack(rpg);
    }
    if (rpg->mp3 == 1)
        mp3_event(rpg);
    if (rpg->scene == 20)
        cine_checker(rpg);
    event_market(rpg);
    event_game3(rpg, mouse);
}

void event_game(rpg_t *rpg, sfMouseButtonEvent mouse)
{
    pause_event(rpg);
    if (rpg->scene == 1) {
        player_movements(rpg);
        npcs_talk(rpg);
        inventory_event(rpg);
        skilltab_event(rpg, mouse);
        quest(rpg);
        check_pannel(rpg);
        player_attack(rpg);
        boat_events(rpg);
    }
    if (rpg->scene == 2) {
        event_house(rpg);
        inventory_event(rpg);
        skilltab_event(rpg, mouse);
        pause_event(rpg);
    }
    if (rpg->hunt == 1)
        event_hunt(rpg);
    event_game2(rpg, mouse);
}