/**** You may MODIFY the designated portions of this file ****/
/**** You may also add any additional functions you need for your implementation ****/

/**** Please fill in your (and your partner's) information (Name and PSU email) below and in the variables below
 * Name:
 * Email:
 * Name:
 * Email:
 ****/
//#define _POSIX_C_SOURCE 199309L
#include "threads.h"
#include <stdlib.h>
#include <time.h>

// Fill out your PSU ID (xyz1234) here
// Make sure to NOT USE your PSU number
char ID_1[] = "acd5466";
char ID_2[] = "tjb5698";

// If you need to have extra variables from threads.c, add them here as `extern`
extern int scheduling_type;
extern thread_queue_t* ready_list;
extern thread_queue_t* thread_list;
extern thread_t* current;
extern int next_thread;
//extern int mlot = 0;

// You may also add your own variables
struct timespec ts_start;
struct timespec ts_end;
int ctxsw_count =0;


//thread_node_t *curr_node = NULL;
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
    if (scheduling_type == RR) {
        thread_enqueue(t, q);
        return;
    }
    if (scheduling_type == vLOT) {
        thread_enqueue(t, q); 
        return;
    }
    if (scheduling_type == mLOT) {
      if (current->status->no_of_bursts % current->weight == 0)
	  	thread_enqueue(t, q);
	  return;
	}
	

}

// This function is called whenever a context switch is starting
void BeginContextSwitch()
{
	clock_gettime(CLOCK_MONOTONIC, &ts_start);
	
	ctxsw_count++;
}

// This function is called whenever a context switch is done
void EndContextSwitch()
{
	clock_gettime(CLOCK_MONOTONIC, &ts_end);
	
	printf("Context switch %d\t", ctxsw_count);
	printf("Elapsed time ");
	printf("%lds ",(ts_end.tv_sec - ts_start.tv_sec));
	printf("%ldns \n", (ts_end.tv_nsec - ts_start.tv_nsec)); 
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
  	 // thread_enqueue(curr_head, ready_list);
	  return curr_head;
	  
        }
        /**** End Round Robin code ****/

    case vLOT: // Vanilla Lottery
        /**** Implement the Vanilla Lottery scheduler here ****/
        // Your code here
        {
          int total_weight = 0;
	  thread_node_t *current_node = malloc(sizeof(*current_node));
	  current_node = ready_list->head;
	  while (current_node != NULL) {
	  	total_weight = total_weight + current_node->thread->weight; //create total weight based on weight of all threads
		current_node = current_node->next; //iterate node
	  }
	 // int count = 0;
	  int winner = 1 + (rand() % total_weight); //select random value from total weight 
	  current_node = ready_list->head;
	  while (current_node != NULL) {
	  //	count = count + (current_node->thread->weight);
	//	if (count > winner)
		winner = winner - (current_node->thread->weight); //remove current node from the running
		if (winner <= 0) 
			return current_node->thread; //If no other threads, finish current thread
		current_node = current_node->next;
	  }
	 }
        /**** End Vanilla Lottery code ****/

    case mLOT:  // Modified Lottery
        /**** Implement the Modified Lottery scheduler here ****/
        // Your code here
      
	   if (current == NULL)
		return thread_list->head->thread; //at beginning, just start with first thread	
	  if ((current->status->no_of_bursts) % (current->weight) == 0){
		  thread_t *winner = NULL;
		  while (winner == NULL) {
		    winner = GetThread ( 1 + (rand() % next_thread)); //get thread ID of random number within range of thread id
	 	  }
		  return winner;
		}  
  		return current; //keep current if no others
		
		
	  } 


      
        
        /**** End Modified Lottery code ****/

    case FCFS: // First Come, First Served
        /**** DO NOT MODIFY ****/
        return ready_list->head->thread;

    default:
       return NULL;
    }
}
