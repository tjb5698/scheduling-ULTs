/**** You may MODIFY the designated portions of this file ****/
/**** You may also add any additional functions you need for your implementation ****/

/**** Please fill in your (and your partner's) information (Name and PSU email) below and in the variables below
 * Name:
 * Email:
 * Name:
 * Email:
 ****/
#include "threads.h"
#include <stdlib.h>

// Fill out your PSU ID (xyz1234) here
// Make sure to NOT USE your PSU number
char ID_1[] = "acd5466";
char ID_2[] = "tjb5698";

// If you need to have extra variables from threads.c, add them here as `extern`
extern int scheduling_type;
extern thread_queue_t* ready_list;
extern thread_queue_t* thread_list;
extern thread_t* current;
//extern int mlot = 0;

// You may also add your own variables
int mlot = 0;
thread_node_t *curr_node = NULL;
int thread_weight = 0;
int winner = 0;
// This function is called once by the test file, before the thread are created
// Feel free to modify this function as much as you want, to initialize variables or structs for instance
void setup(int schedule) {

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
    if (scheduling_type == FCFS) {
        InsertAtHead(t, q);
        return;
    }
    /**** Your Code Here ****/

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
// Returns the running thread
thread_t* scheduler()
{
    /**** You may also add variable declarations here, or in the sections below ****/

    /**** End variable declarations ****/

    /**** NOTE: the last running thread will be at in the `current` variable ****/
    // Make sure we still have some work to do
    if (ready_list->size == 0)
        return NULL;
    switch (scheduling_type) {
    case RR: // Round Robin
        /**** Implement the Round Robin scheduler here ****/
        // Your code here
	{
	  thread_t *curr_head = malloc(sizeof(*curr_head));
	  curr_head = thread_dequeue(ready_list);
  	  thread_enqueue(curr_head, ready_list);
	  return curr_head;
        }
        /**** End Round Robin code ****/

    case vLOT: // Vanilla Lottery
        /**** Implement the Vanilla Lottery scheduler here ****/
        // Your code here
        {
          int total_weight = 0;
	  thread_node_t *curr_node = malloc(sizeof(*curr_node));
	  curr_node = ready_list->head;
	  while (curr_node != NULL) {
	  	total_weight = total_weight + curr_node->thread->weight;
		curr_node = curr_node->next;
	  }
	 
	  int count = 0;
	  int winner = 1 + rand() / (RAND_MAX / (total_weight-1+1)+1);
	  curr_node = ready_list->head;
	  while (curr_node != NULL) {
	  	count = count + curr_node->thread->weight;
		if (count > winner)
			return curr_node->thread;
		curr_node = curr_node->next;
	  }
	 }
        /**** End Vanilla Lottery code ****/

    case mLOT: // Modified Lottery
        /**** Implement the Modified Lottery scheduler here ****/
        // Your code here
    {
	 	if (mlot == 0) {
	      int count = 0;
	      int list_size = thread_list->size;
	      winner = 1 + rand() / (RAND_MAX / (list_size-1+1)+1);
          curr_node = ready_list->head;
	   
	      while (curr_node != NULL) {
		    count = count +1;
		    thread_weight = curr_node->thread->weight;
		    if (count == winner) {
			  if(mlot < thread_weight-1)
			     mlot = mlot+1;
			  printf("mlot - %d\n",mlot );
              printf("weight -%d\n",curr_node->thread->weight);
              return curr_node->thread;	
		    }
            curr_node = curr_node->next;
	      }
	    }	
	    else {
            int count = 0;
            curr_node = ready_list->head;
            while (curr_node != NULL){
                count = count+1;
                thread_weight = curr_node->thread->weight;
                if (count == winner) {
                    if (mlot < (thread_weight)-1) {
                        mlot = mlot + 1;
                        printf("mlot - %d\n",mlot );
                        printf("weight - %d\n",thread_weight);
                        return curr_node->thread;
                    }
                    else if (mlot == (curr_node->thread->weight)-1) {
                        mlot = 0;
                        printf("mlot - %d\n",mlot );
                        printf("weight - %d\n",curr_node->thread->weight);
                        return curr_node->next->thread;
                    }
                } 
		    }
        }
    }    
        /**** End Modified Lottery code ****/

    case FCFS: // First Come, First Served
        /**** DO NOT MODIFY ****/
        return ready_list->head->thread;

    default:
        return NULL;
    }
}
