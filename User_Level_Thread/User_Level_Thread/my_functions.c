/**** You may MODIFY the designated portions of this file ****/
/**** You may also add any additional functions you need for your implementation ****/

/**** Please fill in your (and your partner's) information (Name and PSU email) below and in the variables below
 * Name:
 * Email:
 * Name:
 * Email:
 ****/

// Feel free to modify this value for test purposes
#define SLEEP_TIME 10

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
/*
void sleeping () {
        /**** Your Code Here ****/
 /* long tid;
  pid_t id;
  id = GetMyId();
  int *ar = arr;
  
  unsigned t1 = GetCurrentTime();
  int temp;
  long long int rf = 0;
  
  while (1)
  {
      rf++;
      unsigned t2 = GetCurrentTime();
      if (id % 2 == 0)
      {
        if (((long long)t2 - (long long)t1) == 5.0)
         sleep(0.003); 
      }

      if (((long long)t2 - (long long)t1) >= 10.0)
      {
        break;
      }
  }
  temp = id%100;
  ar[temp] = rf;


  for(int i=0 ; i<100 ; i++) {
    printf("arr[i] = %d \n", arr[i]);
    sum += arr[i];
  }
  printf("Sum = %d \n",sum);
  CleanUp(); */
  
        /**** End Your Code ****/
//}
