/**** You may MODIFY the designated portions of this file ****/
/**** You may also add any additional functions you need for your implementation ****/

/**** Please fill in your (and your partner's) information (Name and PSU email) below and in the variables below
 * Name:
 * Email:
 * Name:
 * Email:
 ****/

// Feel free to modify this value for test purposes
#define SLEEP_TIME 2

void counter () 
{
  int id = GetMyId();
  
  unsigned t1 = GetCurrentTime();

  long long int rf = 0;

  int i =0;
   
  while (1)
  {
      unsigned t2 = GetCurrentTime(); 
      if (i % 10000000 == 0) {
            printf("counter tid: %d; rf = %lld; i = %d\n", GetMyId(), rf,i);
	    i++;
        }
      
      if (((long long)t2 - (long long)t1) >= 25.0)
      {
         printf("DELETING MYSELF (tid: %d); time now: %lld\n", GetMyId(),(long long)t2);
	 DeleteThread(GetMyId());       
       }
      rf++;
     // i++;
  }

}

void sleeping () {
  
  int id = GetMyId();
    
  unsigned t1 = GetCurrentTime();
  
  long long int rf = 0;
  
    if (id % 2 == 0)
    {
        SleepThread(SLEEP_TIME);
        printf("sleep tid: %d; rf = %lld\n", GetMyId(), rf);
    }
    else
    {
        SleepThread(7);
        printf("sleep tid: %d; rf = %lld\n", GetMyId(), rf);
    }
    while (1)
    {
      unsigned
        if (((long long)t2 - (long long)t1) >= 10.0)
      {
         printf("DELETING MYSELF (tid: %d); time now: %lld\n", GetMyId(),(long long)t2);
   DeleteThread(GetMyId());
      }
    }
}
