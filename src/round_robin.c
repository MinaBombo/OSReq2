#include <round_robin.h>
#include <generic_queue.h>
#include <process_struct.h>

#define min(a,b) a<b ? a:b

static struct _process_queue{
    generic_queue_head *head;
} *_circular_queue;
typedef struct _process_queue process_queue;

static process_queue *init_circular_queue(){
    process_queue *queue = (process_queue *)malloc(sizeof(process_queue));
    queue->head = init_generic_queue();
    return queue;
}

static bool empty_circular(process_queue *queue){
    return generic_queue_empty(queue->head);
}

static bool enqueue_circular(process_queue *queue, process *new_node){
    bool ret = generic_queue_enqueue(queue->head , (void *)new_node);
    if(ret == false) return false;

    if(queue->head->first != queue->head->last)
        queue->head->last->next = queue->head->first;
    return true;
}

static process *dequeue_circular(process_queue *queue){
    process *data = (process *)generic_queue_dequeue(queue->head);
    if(data == NULL) return NULL;
    
    if(queue->head->first == queue->head->last && queue->head->first!=NULL)
        queue->head->last->next = NULL;
    return data;
}

