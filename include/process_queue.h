#pragma once 

#include <generic_queue.h>
#include <process_struct.h>

struct _process_queue
{
    generic_queue_head *head;
};
typedef struct _process_queue process_queue;
process_queue *init();

bool enqueue(process_queue *queue, process *new_node);
process *dequeue(process_queue * queue);
bool empty(process_queue *queue);
void destroy(process_queue *queue);

