/*
** EPITECH PROJECT, 2019
** garbage_collector.c
** File description:
** functions for garbage_collector
*/

#include <stdlib.h>
#include <garbage.h>

void call_after_main(void) __attribute__((destructor));
garbage_collector_t *add_ptr_to_garbage_collector_t \
(garbage_collector_t *garbage_collector, void *ptr);
void destroy_ptr_to_garbage_collector_t \
(garbage_collector_t *garbage_collector);
garbage_collector_t **my_ptr_garbage(void);
void *my_malloc(int size);

void call_after_main(void)
{
    garbage_collector_t **garbage = my_ptr_garbage();

    destroy_ptr_to_garbage_collector_t(*garbage);
}

garbage_collector_t *add_ptr_to_garbage_collector_t \
(garbage_collector_t *garbage_collector, void *ptr)
{
    garbage_collector_t *garbage = malloc(sizeof(garbage_collector_t));

    garbage->ptr = ptr;
    garbage->next = garbage_collector;
    return (garbage);
}

void destroy_ptr_to_garbage_collector_t(garbage_collector_t *garbage_collector)
{
    garbage_collector_t *temp;

    while (garbage_collector != NULL) {
        temp = garbage_collector;
        free(garbage_collector->ptr);
        garbage_collector = garbage_collector->next;
        free(temp);
    }
}

garbage_collector_t **my_ptr_garbage(void)
{
    static garbage_collector_t *garbage = NULL;

    return (&garbage);
}

void *my_malloc(int size)
{
    void *ptr = malloc(size);
    garbage_collector_t **garbage = my_ptr_garbage();

    *garbage = add_ptr_to_garbage_collector_t(*garbage, ptr);
    return (ptr);
}
