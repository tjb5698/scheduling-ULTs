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

void counter () {
        /**** Your Code Here ****/
  long tid;
  pid_t id;
  int temp;
  id = GetMyId();
  int *ar = arr;

  unsigned t1 = GetCurrentTime();
  long long int rf = 0;
 
  while (1)
  {
      rf++;
	 unsigned t2 = GetCurrentTime();
     if (((long long)t2 - (long long)t1) >= 10.0)
      {
       
        break;
      }
  }
  temp = (int)id%100;
  printf("temp = %d\n", temp);
  ar[temp] = rf;

  for(int i=0 ; i<100 ; i++) {
        printf("arr[i] = %d \n", arr[i]);
        sum += arr[i];
      }
      printf("Sum = %d \n",sum);
      CleanUp(); 

        /**** End Your Code ****/
}

void sleeping () {
        /**** Your Code Here ****/
  long tid;
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
      if (id%2 == 0)
      {
        if (((long long)t2 - (long long)t1) == 5.0)
         sleep(0.003); //3 seconds (using 3 instead of 0.003 caused segfaults when testing the sleeping function for a single thread)
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
  CleanUp();
  
        /**** End Your Code ****/
}
