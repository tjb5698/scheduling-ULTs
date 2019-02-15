/**** You may MODIFY the designated portions of this file ****/
/**** You may also add any additional functions you need for your implementation ****/

/**** Please fill in your (and your partner's) information (Name and PSU email) below and in the variables below
 * Name:
 * Email:
 * Name:
 * Email:
 ****/
#include "threads.h"

// Fill out your PSU ID (xyz1234) here
// Make sure to NOT USE your PSU number
char ID_1[] = "";
char ID_2[] = "";

// If you need to have extra variables from threads.c, add them here as `extern`
extern int scheduling_type;
extern thread_queue_t* ready_list;
extern thread_queue_t* thread_list;
extern thread_t* current;

// This function is called once by the test file, before the thread are created
// Feel free to modify this function as much as you want, to initialize variables or structs for instance
void setup(int schedule)
{
    printf("Student IDs:\nID_1: %s\nID_2: %s\n", ID_1, ID_2);
    srand(time(NULL));
    scheduling_type = schedule; // FCFS == 0, RR == 1, vLOT == 2, mLOT == 3
    ready_list = malloc(sizeof(thread_queue_t));
    ready_list->head = ready_list->tail = NULL;
    ready_list->size = 0;

    thread_list = malloc(sizeof(thread_queue_t));
    thread_list->head = ready_list->tail = NULL;
    thread_list->size = 0;

    current = NULL;

    signal(SIGVTALRM, Dispatch);
}

// This function adds the thread t to the ready queue q according the scheduler used
// Feel free to modify this function as much as you want
void InsertWrapper(thread_t* t, thread_queue_t* q)
{
    InsertAtHead(t, q);
}

// This function is called whenever a context switch is starting
void BeginContextSwitch()
{
}

// This function is called whenever a context switch is done
void EndContextSwitch()
{
}

// Add extra functions you want here

// Manages the thread scheduling when called
// Returns the tne running thread
thread_t* scheduler()
{
    /**** You may also add variablez declarations here, or in the sections below ****/

    /**** End variable declarations ****/

    /**** NOTE: the last running thread will be at in the `current` variable ****/
    // Make sure we still have some work to do
    if (ready_list->size == 0 && current == NULL)
        return NULL;
    switch (scheduling_type) {
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
        if (current == NULL) {
            // We did not previously have a running thread
            return ready_list->head->thread;
        } else {
            // We had a running thread...
            if (current->status->state == FINISHED || current->status->state == SLEEPING || current->status->state == SUSPENDED) {
                // ... that cannot run anymore
                if (ready_list->size == 0) {
                    return NULL;
                } else {
                    return ready_list->head->thread;
                }
            } else {
                // ... that can still run
                return current;
            }
        }
    default:
        return NULL;
    }
}
