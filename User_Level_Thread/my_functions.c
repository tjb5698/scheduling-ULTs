/**** You may MODIFY the designated portions of this file ****/
/**** You may also add any additional functions you need for your implementation ****/

/**** Please fill in your (and your partner's) information (Name and PSU email) below and in the variables below
 * Name: Trishita Bhattacharya
 * Email:tjb5698@psu.edu
 * Name: Aidan Dowling
 * Email: acd5466@psu.edu
 ****/

// Feel free to modify this value for test purposes
#define SLEEP_TIME 2

void counter () 
{
  int id = GetMyId();
  
  unsigned t1 = GetCurrentTime();
  
  long long int rf = 0;
 
  while (1)
  {
      unsigned t2 = GetCurrentTime(); 
      //used to compare start of loop to start of thread
      //If time between start of thread and start of loop is greater than 10 seconds, exit.
      if (((long long)t2 - (long long)t1)/1000 >= 10.0) 
      {
         //display thread contents on exit
         printf("counter tid: %d; rf = %lld;\n", GetMyId(), rf);
	 printf("DELETING MYSELF (tid: %d); time now: %ld\n", GetMyId(),(long long)t2);
	 DeleteThread(GetMyId()); //clean up       
       }
      rf++; //increment "work done" or count
  }

}

void sleeping () {
  
    int id = GetMyId();
    
    unsigned t1 = GetCurrentTime();
  
    long long int rf = 0;

    printf("sleeping tid: %d; rf = %lld\n", GetMyId(), rf);

    if (id % 2 == 0)
    {
        printf("Sleeping for %d...\n", SLEEP_TIME);
        sleep(SLEEP_TIME);
	//Put thread to sleep for small amount of time if even numbered id
    }
    else
    {
	//put thread to sleep for longer if odd id
        printf("Sleeping for 7...\n");
        sleep(7);
    }

    printf("sleeping tid: %d; rf = %lld\n", GetMyId(), rf);

    while (1)
    {
      rf++;

      unsigned t2 = GetCurrentTime();

      if (((long long)t2 - (long long)t1)/1000 >= 10.0)
      {
       break; //if more than 10 seconds have passed in the thread, stop the thread and clean it up
      }
    }

    printf("sleeping tid: %d, rf = %lld\n", GetMyId(), rf); //display contents on exit
    DeleteThread(GetMyId()); //clean up
}
