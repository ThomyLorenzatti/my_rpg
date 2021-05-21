/*
** EPITECH PROJECT, 2020
** Code_CSFML
** File description:
** cursor
*/

#include <rpg.h>

cursor_t create_cursor(void)
{
    cursor_t cursor = {0};

    cursor.position.x = 0;
    cursor.position.y = 0;
    cursor.rectangle.height = 50;
    cursor.rectangle.width = 50;
    cursor.sprite = sfSprite_create();
    cursor.texture = sfTexture_createFromFile("res/cursor.png", NULL);
    cursor.clock = sfClock_create();
    sfSprite_setTexture(cursor.sprite, cursor.texture, sfTrue);
    sfSprite_setTextureRect(cursor.sprite, cursor.rectangle);
    sfSprite_setPosition(cursor.sprite, cursor.position);
    return (cursor);
}

cursor_t update_cursor(const sfRenderWindow *window, cursor_t cursor)
{
    sfVector2i vector;

    vector = sfMouse_getPositionRenderWindow(window);
    cursor.position.x = vector.x;
    cursor.position.y = vector.y;
    if (sfMouse_isButtonPressed(sfMouseLeft) == 1)
        cursor.rectangle.left = 50;
    cursor.time = sfClock_getElapsedTime(cursor.clock);
    cursor.seconds = cursor.time.microseconds / 1000000.0;
    if (cursor.seconds > 0.20) {
        cursor.rectangle.left = 0;
        sfClock_restart(cursor.clock);
    }
    sfSprite_setTextureRect(cursor.sprite, cursor.rectangle);
    sfSprite_setPosition(cursor.sprite, cursor.position);
    return (cursor);
}

void display_cursor(sfRenderWindow *window, const cursor_t cursor)
{
    sfRenderWindow_drawSprite(window, cursor.sprite, NULL);
}

void destroy_cursor(rpg_t *rpg)
{
    sfTexture_destroy(rpg->cursor.texture);
    sfSprite_destroy(rpg->cursor.sprite);
    sfClock_destroy(rpg->cursor.clock);
}