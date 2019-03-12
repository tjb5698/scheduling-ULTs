
// Project 2: User level thread library
// Test file
// DO MODIFY
#include "functions.c"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s [FCFS] | [RR] | [vLOT] | [mLOT]\n", argv[0]);
        return 1;
    } else if (strcmp(argv[1], "FCFS") == 0) {
        setup(FCFS); // First Come, First Served
    } else if (strcmp(argv[1], "RR") == 0) {
        setup(RR); // Round Robin
    } else if (strcmp(argv[1], "vLOT") == 0) {
        setup(vLOT); // Vanilla Lottery
    } else if (strcmp(argv[1], "mLOT") == 0) {
        setup(mLOT); // Modified Lottery
    } else {
        printf("Usage: %s [FCFS] | [RR] | [vLOT] | [mLOT]\n", argv[0]);
        return 1;
    }

    for (int i =0; i<=85; i++){
    	CreateThread(sleeping, 1);
        //loop to create threads, call to threads.c	
    }
   // CreateThread(counter, 1); // 0
   // CreateThread(counter, 2); // 1
   // CreateThread(counter, 3); // 2


    Go();

    return 0;
}
