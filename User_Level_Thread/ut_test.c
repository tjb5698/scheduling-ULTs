#include "threads.h"
#include "my_functions.c"
#include <string.h>

//#define NUM_THREADS 2 

int main(int argc, char const *argv[])
{
  //thread_t threads[NUM_THREADS];
  int NUM_THREADS = atoi(argv[2]); 
  int rc;
  void *tab[] = {counter, sleeping}; //used to select thread function at run time via argument
  int flag = -1;

  setup(RR);

  if (argc < 3)
  {
    printf("Usage: %s [counter] | [sleeping]	Thread count\n", argv[0]); //if no/invalid argument, boot user and prompt for valid argument
    return -1;
  }

  flag = !(strcmp(argv[1], "counter")) ? 0 : 1;
  //create flag to pass to createthread which selects thread function
  printf("Code under execution .. \n");

  for (int t = 0; t < NUM_THREADS; t++)
  {
    // create number of threads defined by user
    rc = CreateThread(tab[flag], 1); //return value checks if vaild thread is created
    if (rc == -1)
      exit(-1);
  }

  Go(); //call the scheduler, begin running threads

  printf("Done."); 

  return 0; 
}
