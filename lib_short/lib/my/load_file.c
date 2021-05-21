/*
** EPITECH PROJECT, 2020
** load_file
** File description:
** load_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <my.h>

char *load_file(char *filepath)
{
    struct stat sb;
    ssize_t size_r = 0;
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;

    if (fd <= -1)
        return (NULL);
    stat(filepath, &sb);
    buffer = my_malloc(sb.st_size + 1);
    size_r = read(fd, buffer, sb.st_size);
    if (size_r <= 0)
        return (NULL);
    buffer[sb.st_size] = 0;
    close(fd);
    return (buffer);
}
