/*
** EPITECH PROJECT, 2020
** create_window
** File description:
** create_window
*/

#include <SFML/Graphics/RenderWindow.h>

sfRenderWindow *create_window(int width, int height, char *title, int bpp)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bpp;
    window = sfRenderWindow_create(video_mode, title, \
    sfClose | sfResize, NULL);
    return (window);
}