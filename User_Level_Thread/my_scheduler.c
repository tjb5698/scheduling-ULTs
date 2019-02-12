/**** You may MODIFY the designated portions of this file ****/
/**** You may also add any additional functions you need for your implementation ****/

/**** Please fill in your (and your partner's) information (Name and PSU email) below
 * Name:
 * Email:
 * Name:
 * Email:
 ****/
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

/**** Additional Functions can go here ****/

thread_t *scheduler()
{
    /**** You may use these declarations in your implementation ****/
    int number, weight = 0;
    thread_node_t *node;

    /**** You may also add other declarations here, or in the sections below ****/

    if (ready_list->size == 0)
        return NULL;
    switch (scheduling_type)
    {
    case RR: // Round Robin
        /**** Implement the Round Robin scheduler here ****/
        // Your code here
        return NULL;
        /**** End Round Robin code ****/

    case vLOT: // Vanilla Lottery
        /**** Implement the Vanilla Lottery scheduler here ****/
        // Your code here
        return NULL;
        /**** End Vanilla Lottery code ****/

    case mLOT: // Modified Lottery
        /**** Implement the Modified Lottery scheduler here ****/
        // Your code here
        return NULL;
        /**** End Modified Lottery code ****/

    case FCFS: // First Come, First Served
        /**** DO NOT MODIFY ****/
        return ready_list->head->thread;
    default:
        return NULL;
    }
}
