#include "threads.h"
#include "my_functions.c"
#include <string.h>

//#define NUM_THREADS 2 

int main(int argc, char const *argv[])
{
  //thread_t threads[NUM_THREADS];
  int NUM_THREADS = atoi(argv[2]); 
  int rc;
  void *tab[] = {counter, sleeping};
  int flag = -1;

  setup(RR);

  if (argc < 3)
  {
    printf("Usage: %s [counter] | [sleeping]	Thread count\n", argv[0]);
    return -1;
  }

  flag = !(strcmp(argv[1], "counter")) ? 0 : 1;

  printf("Code under execution .. \n");

  for (int t = 0; t < NUM_THREADS; t++)
  {
    // printf("Creating thread %d\n", t);
    rc = CreateThread(tab[flag], 1); //tab[flg], 1);  
    // printf("rc = %d\n", rc);
    if (rc == -1)
      exit(-1);
  }

  Go();

  printf("Done.");

  return 0;
}
