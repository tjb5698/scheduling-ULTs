#include "threads.h"
extern int scheduling_type;
extern thread_queue_t *ready_list;

void InsertAtHead(thread_t *t, thread_queue_t *q)
{
    thread_node_t *node = malloc(sizeof(thread_node_t));
    node->thread = t;
    node->next = q->head;
    q->head = node;
    if (q->tail == NULL)
        q->tail = node;
    q->size++;
}

void thread_enqueue(thread_t *t, thread_queue_t *q)
{
    thread_node_t *node = malloc(sizeof(thread_node_t));
    node->thread = t;
    node->next = NULL;

    if (q->tail != NULL)
        q->tail->next = node;
    else
        q->head = node;

    q->tail = node;
    q->size++;
}

thread_t *scheduler()
{
    int number, priority = 0;
    thread_node_t *node;
    if (ready_list->size == 0)
        return NULL;
    switch (scheduling_type)
    {
    case 0: // Round Robin

        //Put your code here
    case 1: // Lottery
            //Put your code here

    case 2: //First come first serve
        return ready_list->head->thread;
    default:
        return NULL;
    }
}
