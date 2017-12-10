#pragma once

#include <defs.h>
#include <stdlib.h>

typedef struct generic_queue_node generic_queue_node;
struct generic_queue_node
{
    void * data;
    generic_queue_node * next;
};
typedef struct generic_queue_head generic_queue_head;
struct generic_queue_head
{
    generic_queue_node * first;
    generic_queue_node * last;
};

generic_queue_head * init_generic_queue();
bool generic_queue_enqueue(generic_queue_head * head, void * new_node);
void * generic_queue_dequeue(generic_queue_head * head);
bool generic_queue_empty(generic_queue_head * head);
void generic_queue_destroy(generic_queue_head * head);

