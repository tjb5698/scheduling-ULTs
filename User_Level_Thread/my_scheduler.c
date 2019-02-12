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
    int number, weight = 0;
    thread_node_t *node;
    if (ready_list->size == 0)
        return NULL;
    switch (scheduling_type)
    {
    case RR: // Round Robin


    case vLOT: // Lottery
            //Put your code here

    case mLOT:

    case FCFS: //First come first serve
        return ready_list->head->thread;
    default:
        return NULL;
    }
}
